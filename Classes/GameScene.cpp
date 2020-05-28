#include "GameScene.h"
#include "SpriteShape.h"
#include "WelcomeScene.h"

GameScene::GameScene()
	:spriteSheet(NULL)
	,isFillSprite(false)
	,isAction(true)
	,isTouchEna(true)
	,m_frequency(30)
	,m_score(0)
{
}

void GameScene::update(float t)//����ÿһ֡
{
	if (isAction)//������ڶ������鿴�Ƿ��������������ڶ���
	{
		isAction = false;
		for (int r = 0; r < ROWS; ++r)
		{
			for (int c = 0; c < COLS; ++c)
			{
				SpriteShape* spr = map[r][c];
				if (spr && spr->getNumberOfRunningActions() > 0)
				{
					isAction = true;
					break;
				}
			}
		}
	}

	// ������������ƶ��У����Ӵ����¼�
	isTouchEna = !isAction;
	if (!isAction)//������ڶ������鿴�Ƿ���Ҫ��侫�飬�������Ҫ��侫�飬�鿴�Ƿ�Ҫ�Ƴ�����
	{
		if (isFillSprite)
		{
			fillSprite();
			isFillSprite = false;
		}
		else
		{
			checkAndRemoveSprite();
		}
		if (!checkIfDeadMap())
		{
			for (int r = 0; r < ROWS; ++r)
			{
				for (int c = 0; c < COLS; ++c)
				{
					markRemove(map[r][c]);
				}
			}
			removeSprite();
			m_score -= 1080;
		}
	}
	Label* labelScore = (Label*)this->getChildByTag(10);

	labelScore->setString(StringUtils::format("Score: %d ", m_score));
}

bool GameScene::checkIfDeadMap()//�鿴�Ƿ�������ͼ
{
	for (int r = 0; r < ROWS; ++r)//һ��12����������ȫ�������򷵻�false
	{
		for (int c = 0; c < COLS; ++c)
		{
			if (r + 1 < ROWS)
			{
				if (map[r][c]->getImgIndex() == map[r + 1][c]->getImgIndex())
				{
					auto currentImg = map[r][c]->getImgIndex();
					if (r - 2 >= 0)
					{
						if (map[r - 2][c]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
					if (r - 1 >= 0 && c - 1 >= 0)
					{
						if (map[r - 1][c - 1]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
					if (r - 1 >= 0 && c + 1 < COLS)
					{
						if (map[r - 1][c + 1]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
					if (r + 3 < ROWS)
					{
						if (map[r + 3][c]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
					if (r + 2 < ROWS && c - 1 >= 0)
					{
						if (map[r + 2][c - 1]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
					if (r + 2 < ROWS && c + 1 < COLS)
					{
						if (map[r + 2][c + 1]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
				}
			}
			if (c + 1 < COLS)
			{
				if (map[r][c]->getImgIndex() == map[r][c + 1]->getImgIndex())
				{
					auto currentImg = map[r][c]->getImgIndex();
					if (c - 2 >= 0)
					{
						if (map[r][c - 2]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
					if (c - 1 >= 0 && r - 1 >= 0)
					{
						if (map[r - 1][c - 1]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
					if (c - 1 >= 0 && r + 1 < ROWS)
					{
						if (map[r + 1][c - 1]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
					if (c + 3 < COLS)
					{
						if (map[r][c + 3]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
					if (c + 2 < COLS && r + 1 < ROWS)
					{
						if (map[r + 1][c + 2]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
					if (c + 2 < COLS && r - 1 >= 0)
					{
						if (map[r - 1][c + 2]->getImgIndex() == currentImg)
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

void GameScene::checkAndRemoveSprite()//�鿴���Ƴ��������ϵľ���
{
	SpriteShape* spr;
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			spr = map[r][c];
			if (!spr)
			{
				continue;
			}
			if (spr->getIsNeedRemove())
			{
				continue;
			}
			std::list<SpriteShape*>colChainList;
			getColChain(spr, colChainList);
			
			std::list<SpriteShape*>rowChainList;
			getRowChain(spr, rowChainList);
			//�õ��ϳ���List
			std::list<SpriteShape*>& longerList = colChainList.size() > rowChainList.size() ? colChainList : rowChainList;
			if (longerList.size() < 3)//���ListС��3��ֱ������
			{
				continue;
			}
			std::list<SpriteShape*>::iterator itList;
			if (colChainList.size() > 2)
			{
				for (itList = colChainList.begin(); itList != colChainList.end(); ++itList)
				{
					spr = (SpriteShape*)*itList;
					if (!spr)
					{
						continue;
					}
					//�����Ҫɾ���ľ���
					markRemove(spr);
				}
			}
			if (rowChainList.size() > 2)
			{
				for (itList = rowChainList.begin(); itList != rowChainList.end(); ++itList)
				{
					spr = (SpriteShape*)*itList;
					if (!spr)
					{
						continue;
					}
					//�����Ҫɾ���ľ���
					markRemove(spr);
				}
			}
		}
	}
	//ɾ������ǵľ���
	removeSprite();
}

void GameScene::markRemove(SpriteShape* spr)//�����Ҫɾ���ľ���
{
	if (spr->getIsNeedRemove())//����Ѿ�����ǣ���ֱ�ӷ���
	{
		return;
	}
	spr->setIsNeedRemove(true);
}

void GameScene::removeSprite()//ɾ������
{
	isAction = true;
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			SpriteShape* spr = map[r][c];
			if (!spr)//����Ѿ���ɾ�����������ѭ��
			{
				continue;
			}
			if (spr->getIsNeedRemove())//�����Ҫ��ɾ����ɾ�����飬�޸�isFillSprite
			{
				isFillSprite = true;
				explodeSprite(spr);
			}
		}
	}
}

void GameScene::explodeSprite(SpriteShape* spr)//��ըɾ��
{
	//һ����ը����
	spr->runAction(Sequence::create(ScaleTo::create(0.2f, 0.0),
		CallFuncN::create(CC_CALLBACK_1(GameScene::actionEndCallBack, this)),
		NULL));
}

void GameScene::actionEndCallBack(Node* node)//ɾ�����麯��
{
	SpriteShape* spr = (SpriteShape*)node;
	map[spr->getRow()][spr->getCol()] = NULL;
	spr->removeFromParent();
}

void GameScene::getColChain(SpriteShape* spr, std::list<SpriteShape*>& chainList)//��ȡ������ͬ�����List
{
	chainList.push_back(spr);

	int neighborCol = spr->getCol() - 1;//����
	while (neighborCol >= 0)
	{
		SpriteShape* neighborSprite = map[spr->getRow()][neighborCol];
		if (neighborSprite &&
			(neighborSprite->getImgIndex() == spr->getImgIndex()) &&
			!neighborSprite->getIsNeedRemove())
		{
			chainList.push_back(neighborSprite);
			neighborCol--;
		}
		else
		{
			break;
		}
	}

	neighborCol = spr->getCol() + 1;//����
	while (neighborCol < COLS)
	{
		SpriteShape* neighborSprite = map[spr->getRow()][neighborCol];
		if (neighborSprite &&
			(neighborSprite->getImgIndex() == spr->getImgIndex()) &&
			!neighborSprite->getIsNeedRemove())
		{
			chainList.push_back(neighborSprite);
			neighborCol++;
		}
		else
		{
			break;
		}
	}
}

void GameScene::getRowChain(SpriteShape* spr, std::list<SpriteShape*>&chainList)//��ȡ������ͬ�����List
{
	chainList.push_back(spr);

	int neighborRow = spr->getRow() - 1;//����
	while (neighborRow >= 0)
	{
		SpriteShape* neighborSprite = map[neighborRow][spr->getCol()];
		if (neighborSprite &&
			(neighborSprite->getImgIndex() == spr->getImgIndex()) &&
			!neighborSprite->getIsNeedRemove())
		{
			chainList.push_back(neighborSprite);
			neighborRow--;
		}
		else
		{
			break;
		}
	}
	
	neighborRow = spr->getRow() + 1;//����
	while (neighborRow < ROWS)
	{
		SpriteShape* neighborSprite = map[neighborRow][spr->getCol()];
		if (neighborSprite &&
			(neighborSprite->getImgIndex() == spr->getImgIndex()) &&
			!neighborSprite->getIsNeedRemove())
		{
			chainList.push_back(neighborSprite);
			neighborRow++;
		}
		else
		{
			break;
		}
	}
}

void GameScene::fillSprite()//��侫�飬�������Ѵ��ڵľ������䣬֮���ڴ����µľ���
{
	isAction = true;
	int sum = 0;//�������

	int* colEmptyInfo = (int*)malloc(sizeof(int) * COLS);//������������¼��Ӧ�����Ƴ�������
	memset((void*)colEmptyInfo, 0, sizeof(int) * COLS);

	SpriteShape* spr = NULL;
	for (int c = 0; c < COLS; ++c)//����map
	{
		//�Ե�����
		int removedSpriteOfCol = 0;
		for (int r = 0; r < ROWS; ++r)
		{
			spr = map[r][c];
			if (spr == NULL)//������λ��û�о��飬��������
			{
				++removedSpriteOfCol;
			}
			else//�ڵ�һ�����־����λ�ã��þ�������
			{
				if (removedSpriteOfCol > 0)
				{
					int newRow = r - removedSpriteOfCol;
					map[newRow][c] = spr;
					map[r][c] = NULL;

					Point startPosition = spr->getPosition();
					Point endPosition = getposition(newRow, c);
					float speed = (startPosition.y - endPosition.y) / GAME_SCREEN_HEIGHT * 3;
					spr->stopAllActions();
					spr->runAction(CCMoveTo::create(speed, endPosition));

					spr->setRow(newRow);
				}
			}
		}
		colEmptyInfo[c] = removedSpriteOfCol;//��¼ÿ�б������ľ�������
		sum += removedSpriteOfCol;
	}

	for (int c = 0; c < COLS; ++c)//�����µľ�������
	{
		for (int r = ROWS - colEmptyInfo[c]; r < ROWS; ++r)
		{
			createSprite(r, c);
		}
	}
	m_score += sum * 30;
	free(colEmptyInfo);
}



// ��ʼ����
bool GameScene::onTouchBegan(Touch *touch, Event *unused) 
{
	startSprite = NULL;
	endSprite = NULL;

	if (isTouchEna) 
	{
		auto position= touch->getLocation();
		startSprite = spriteOfPoint(&position);
	}
	return isTouchEna;
}

// �������ƶ��ķ���
void GameScene::onTouchMoved(Touch *touch, Event *unused)
{
	// ���û�г�ʼ���� ���� �����¼������У�ֱ�ӷ���
	if (!startSprite || !isTouchEna)
	{
		return;
	}


	// ��ȡ ��ʼ���� ������
	int row = startSprite->getRow();
	int col = startSprite->getCol();

	// ��ȡ�ƶ����� �� ��λ��
	auto location = touch->getLocation();
	auto halfSpriteWidth = SPRITE_WIDTH / 2;
	auto halfSpriteHeight = SPRITE_WIDTH / 2;

	auto  upRect = Rect(startSprite->getPositionX() - halfSpriteWidth,
		startSprite->getPositionY() + halfSpriteHeight,
		SPRITE_WIDTH,
		SPRITE_WIDTH);

	// �ж��������ĸ������ƶ���
	if (upRect.containsPoint(location)) 
	{
		row++;
		if (row < ROWS)
		{
			endSprite = map[row][col];
		}
		swapSprite();
		return;
	}

	auto  downRect = Rect(startSprite->getPositionX() - halfSpriteWidth,
		startSprite->getPositionY() - (halfSpriteHeight * 3),
		SPRITE_WIDTH,
		SPRITE_WIDTH);

	if (downRect.containsPoint(location))
	{
		row--;
		if (row >= 0) 
		{
			endSprite = map[row][col];
		}
		swapSprite();
		return;
	}

	auto  leftRect = Rect(startSprite->getPositionX() - (halfSpriteWidth * 3),
		startSprite->getPositionY() - halfSpriteHeight,
		SPRITE_WIDTH,
		SPRITE_WIDTH);

	if (leftRect.containsPoint(location)) 
	{
		col--;
		if (col >= 0) 
		{
			endSprite = map[row][col];
		}
		swapSprite();
		return;
	}

	auto  rightRect = Rect(startSprite->getPositionX() + halfSpriteWidth,
		startSprite->getPositionY() - halfSpriteHeight,
		SPRITE_WIDTH,
		SPRITE_WIDTH);

	if (rightRect.containsPoint(location)) 
	{
		col++;
		if (col < COLS) 
		{
			endSprite = map[row][col];
		}
		swapSprite();
		return;
	}

	// ���򣬲���һ����Ч���ƶ�
}

// ���ݴ����ĵ�λ�ã������ǵ�ͼ���ĸ�����
SpriteShape *GameScene::spriteOfPoint(Point *point)
{
	SpriteShape *spr = NULL;
	Rect rect = Rect(0, 0, 0, 0);
	Size sz;
	sz.height = SPRITE_WIDTH;
	sz.width = SPRITE_WIDTH;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			spr = map[i][j];
			if (spr) 
			{
				rect.origin.x = spr->getPositionX() - (SPRITE_WIDTH / 2);
				rect.origin.y = spr->getPositionY() - (SPRITE_WIDTH / 2);

				rect.size = sz;
				if (rect.containsPoint(*point)) 
				{
					return spr;
				}
			}
		}
	}

	return NULL;
}

// ��������
void GameScene::swapSprite() 
{
	// �ƶ��У��������ٴδ�����ִ�ж�������Ϊtrue
	isAction = true;
	isTouchEna = false;

	// ��ʼ���� �� ��ֹ���� ������Ϊ��
	if (!startSprite || !endSprite) 
	{
		return;
	}

	Point posOfSrc = startSprite->getPosition();
	Point posOfDest = endSprite->getPosition();

	float time = 0.2;

	// �������н���λ��
	map[startSprite->getRow()][startSprite->getCol()] = endSprite;
	map[endSprite->getRow()][endSprite->getCol()] = startSprite;

	int tmpRow = startSprite->getRow();
	int tmpCol = startSprite->getCol();
	startSprite->setRow(endSprite->getRow());
	startSprite->setCol(endSprite->getCol());
	endSprite->setRow(tmpRow);
	endSprite->setCol(tmpCol);

	// ����Ƿ�������
	std::list<SpriteShape *> colChainListOfFirst;
	getColChain(startSprite, colChainListOfFirst);

	std::list<SpriteShape *> rowChainListOfFirst;
	getRowChain(startSprite, rowChainListOfFirst);

	std::list<SpriteShape *> colChainListOfSecond;
	getColChain(endSprite, colChainListOfSecond);

	std::list<SpriteShape *> rowChainListOfSecond;
	getRowChain(endSprite, rowChainListOfSecond);

	if (colChainListOfFirst.size() >= 3
		|| rowChainListOfFirst.size() >= 3
		|| colChainListOfSecond.size() >= 3
		|| rowChainListOfSecond.size() >= 3) {
		// ����ܹ����������������ƶ��������ƶ�������
		startSprite->runAction(MoveTo::create(time, posOfDest));
		endSprite->runAction(MoveTo::create(time, posOfSrc));
		myFrequency();//�޸Ĵ���
		return;
	}

	// �������������ƶ���ȥ��Ҫ����
	map[startSprite->getRow()][startSprite->getCol()] = endSprite;
	map[endSprite->getRow()][endSprite->getCol()] = startSprite;

	tmpRow = startSprite->getRow();
	tmpCol = startSprite->getCol();
	startSprite->setRow(endSprite->getRow());
	startSprite->setCol(endSprite->getCol());
	endSprite->setRow(tmpRow);
	endSprite->setCol(tmpCol);

	startSprite->runAction(Sequence::create(
		MoveTo::create(time, posOfDest),
		MoveTo::create(time, posOfSrc),
		NULL));
	endSprite->runAction(Sequence::create(
		MoveTo::create(time, posOfSrc),
		MoveTo::create(time, posOfDest),
		NULL));
}

//����ʣ�����
void GameScene::myFrequency()
{
	--m_frequency;
	if (m_frequency == 0)//���������0��ֱ�ӽ�����Ϸ
	{
		Label* labelFrequency = (Label*)this->getChildByTag(11);
		labelFrequency->setScale(0);
		
		auto gmov = Sprite::create("pic_gameover.png");
		gmov->setPosition(Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_WIDTH * 1.5));
		this->addChild(gmov);

		auto action = MoveTo::create(3.0f, Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_WIDTH / 2));
		gmov->runAction(action);

		return;
	}
	if (m_frequency > 0)//�����㣬�ı����������
	{
		Label* labelFrequency = (Label*)this->getChildByTag(11);
		labelFrequency->setString(StringUtils::format("Frequency: %d", m_frequency));
	}
}

Scene* GameScene::createScene()	{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
	return scene;
}

// ��ӭ���� ��ʼ������
bool GameScene::init()	
{
	// �ȳ�ʼ�����࣬���ɹ�����false
	if( !Layer::init() )	
	{
		return false;
	}

	// ����plist��png
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("icon.plist");
    spriteSheet = SpriteBatchNode::create("icon.png");
    addChild(spriteSheet);
	mapLBX = (GAME_SCREEN_WIDTH - SPRITE_WIDTH * COLS - (COLS - 1) * BOADER_WIDTH) / 2;
	mapLBY = (GAME_SCREEN_HEIGHT - SPRITE_WIDTH * ROWS - (ROWS - 1) * BOADER_WIDTH) / 2;



	// ��ӱ���ͼƬ
	auto sprite = Sprite::create("scene_bg.png");
	sprite->setPosition(Point(GAME_SCREEN_WIDTH/2,GAME_SCREEN_HEIGHT/2));
    this->addChild(sprite,-1);

	// ��ӷ��ذ�ť
	auto backItem = MenuItemImage::create(
                                           "btn_back01.png",
                                           "btn_back02.png",
										   CC_CALLBACK_1(GameScene::menuBackCallback, this));
	backItem->setPosition(Vec2(GAME_SCREEN_WIDTH-backItem->getContentSize().width/2,backItem->getContentSize().height/2));

	auto menu = Menu::create(backItem, NULL);
    menu->setPosition(Vec2::ZERO);
	this -> addChild( menu );
	
	// ����ttf����
	TTFConfig config("fonts/haibaoti.ttf", 30);
	//��ʾ����
	auto labelScore = Label::createWithTTF(config, StringUtils::format("Score: %d ", m_score));
	labelScore->setPosition(Vec2(GAME_SCREEN_WIDTH - backItem->getContentSize().width / 2, backItem->getContentSize().height / 2 + labelScore->getContentSize().height * 2.6));
	labelScore->setTag(10);
	this->addChild(labelScore);
	
	//��Ӽ�����
	auto labelTime = Label::createWithTTF(config, StringUtils::format("Frequency: %d", m_frequency));
	labelTime->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25, GAME_SCREEN_WIDTH / 2));
	labelTime->setTag(11);
	this->addChild(labelTime);

	// �����¼�����
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	touchListener->setSwallowTouches(true);
	initMap();
	scheduleUpdate();
	return true;
}

// ���غ�������ת����ӭ����
void GameScene::menuBackCallback( Ref* pSender )	
{
	auto scene = WelcomeScene::createScene();
	CCDirector::sharedDirector()->replaceScene(scene);
}

// ��ʼ����ͼ
void GameScene::initMap( )	
{
	
	for( int i = 0 ; i < ROWS ;i++ )
	{
		for( int j = 0 ; j < COLS ; j++)
		{
			createSprite(i,j);
		}
	}
}

// ��������
void GameScene::createSprite( int row , int col )	
{
	
	SpriteShape* temp = SpriteShape::create(row, col);
	
	// �������䶯��
	Point endPosition = getposition(row, col);
	Point startPosition = Point(endPosition.x, endPosition.y + GAME_SCREEN_HEIGHT / 2);
    temp->setPosition(startPosition);
	float speed = startPosition.y / (1.5 * GAME_SCREEN_HEIGHT );
    temp->runAction(MoveTo::create(speed, endPosition));
    // ���뵽spriteSheet��,�ȴ�����
    spriteSheet -> addChild(temp);

    map[row][col] = temp;
}

// �������У���ȡ����ֵ
Point GameScene::getposition(int row , int col)
{
	float x = (SPRITE_WIDTH + BOADER_WIDTH) * col + SPRITE_WIDTH / 2;
    float y = (SPRITE_WIDTH + BOADER_WIDTH) * row + SPRITE_WIDTH / 2;
    return Point(x, y);
}

Point GameScene::positionOfItem(int row, int col)
{
	float x = mapLBX + (SPRITE_WIDTH + BOADER_WIDTH) * col + SPRITE_WIDTH / 2;
	float y = mapLBY + (SPRITE_WIDTH + BOADER_WIDTH) * row + SPRITE_WIDTH / 2;
	return Point(x, y);
}