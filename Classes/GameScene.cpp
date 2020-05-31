#include "GameScene.h"
#include "SpriteShape.h"
#include "WelcomeScene.h"
#include"GameOverScene.h"

using namespace CocosDenshion;

GameScene::GameScene()
	:spriteSheet(NULL)
	,isFillSprite(false)
	,isAction(true)
	,isTouchEna(true)
	,m_frequency(30)
	,m_score(0)
	,musicNum(0.5)
{
}

void GameScene::update(float t)//更新每一帧
{
	if (isAction)//如果正在动作，查看是否有其他精灵正在动作
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

	// 如果精灵正在移动中，忽视触摸事件
	isTouchEna = !isAction;
	if (!isAction)//如果不在动作，查看是否需要填充精灵，如果不需要填充精灵，查看是否要移除精灵
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



bool GameScene::checkIfDeadMap()//查看是否是死地图
{
	for (int r = 0; r < ROWS; ++r)//一共12种情况，如果全不满足则返回false
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

void GameScene::checkAndRemoveSprite()//查看并移除三连以上的精灵
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
			//得到较长的List
			std::list<SpriteShape*>& longerList = colChainList.size() > rowChainList.size() ? colChainList : rowChainList;
			if (longerList.size() < 3)//如果List小于3，直接跳过
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
					//标记需要删除的精灵
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
					//标记需要删除的精灵
					markRemove(spr);
				}
			}
		}
	}
	//删除被标记的精灵
	removeSprite();
}

void GameScene::markRemove(SpriteShape* spr)//标记需要删除的精灵
{
	if (spr->getIsNeedRemove())//如果已经被标记，则直接返回
	{
		return;
	}
	spr->setIsNeedRemove(true);
}

void GameScene::removeSprite()//删除精灵
{
	isAction = true;
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			SpriteShape* spr = map[r][c];
			if (!spr)//如果已经被删除，跳过这次循环
			{
				continue;
			}
			if (spr->getIsNeedRemove())//如果需要被删除，删除精灵，修改isFillSprite
			{
				isFillSprite = true;
				explodeSprite(spr);
			}
		}
	}
}

void GameScene::explodeSprite(SpriteShape* spr)//爆炸删除
{
	//一个爆炸动作
	spr->runAction(Sequence::create(ScaleTo::create(0.2f, 0.0),
		CallFuncN::create(CC_CALLBACK_1(GameScene::actionEndCallBack, this)),
		NULL));
}

void GameScene::actionEndCallBack(Node* node)//删除精灵函数
{
	SpriteShape* spr = (SpriteShape*)node;
	map[spr->getRow()][spr->getCol()] = NULL;
	spr->removeFromParent();
	//加载爆炸音乐
	SimpleAudioEngine::sharedEngine()->playEffect("music_explode.wav", false);
}

void GameScene::getColChain(SpriteShape* spr, std::list<SpriteShape*>& chainList)//获取左右相同精灵的List
{
	chainList.push_back(spr);

	int neighborCol = spr->getCol() - 1;//向左
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

	neighborCol = spr->getCol() + 1;//向右
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

void GameScene::getRowChain(SpriteShape* spr, std::list<SpriteShape*>&chainList)//获取上下相同精灵的List
{
	chainList.push_back(spr);

	int neighborRow = spr->getRow() - 1;//向上
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
	
	neighborRow = spr->getRow() + 1;//向下
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

void GameScene::fillSprite()//填充精灵，是先让已存在的精灵下落，之后在创建新的精灵
{
	isAction = true;
	int sum = 0;//计算分数

	int* colEmptyInfo = (int*)malloc(sizeof(int) * COLS);//创建变量，记录相应列数移除的数量
	memset((void*)colEmptyInfo, 0, sizeof(int) * COLS);

	SpriteShape* spr = NULL;
	for (int c = 0; c < COLS; ++c)//遍历map
	{
		//自底向上
		int removedSpriteOfCol = 0;
		for (int r = 0; r < ROWS; ++r)
		{
			spr = map[r][c];
			if (spr == NULL)//如果这个位置没有精灵，变量自增
			{
				++removedSpriteOfCol;
			}
			else//在第一个出现精灵的位置，让精灵下落
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
		colEmptyInfo[c] = removedSpriteOfCol;//记录每列被消除的精灵数量
		sum += removedSpriteOfCol;
	}

	for (int c = 0; c < COLS; ++c)//创建新的精灵下落
	{
		for (int r = ROWS - colEmptyInfo[c]; r < ROWS; ++r)
		{
			createSprite(r, c);
		}
	}
	m_score += sum * 30;
	free(colEmptyInfo);
}



// 开始触摸
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

// 触摸后移动的方向
void GameScene::onTouchMoved(Touch *touch, Event *unused)
{
	// 如果没有初始精灵 或者 触摸事件不可行，直接返回
	if (!startSprite || !isTouchEna)
	{
		return;
	}


	// 获取 初始精灵 的行列
	int row = startSprite->getRow();
	int col = startSprite->getCol();

	// 获取移动到的 点 的位置
	auto location = touch->getLocation();
	auto halfSpriteWidth = SPRITE_WIDTH / 2;
	auto halfSpriteHeight = SPRITE_WIDTH / 2;

	auto  upRect = Rect(startSprite->getPositionX() - halfSpriteWidth,
		startSprite->getPositionY() + halfSpriteHeight,
		SPRITE_WIDTH,
		SPRITE_WIDTH);

	// 判断是在向哪个方向移动，
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

	// 否则，并非一个有效的移动
}

// 根据触摸的点位置，返回是地图中哪个精灵
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

// 交换精灵
void GameScene::swapSprite() 
{
	// 移动中，不允许再次触摸，执行动作设置为true
	isAction = true;
	isTouchEna = false;

	// 初始精灵 和 终止精灵 均不能为空
	if (!startSprite || !endSprite) 
	{
		return;
	}

	Point posOfSrc = startSprite->getPosition();
	Point posOfDest = endSprite->getPosition();

	float time = 0.2;

	// 在数组中交换位置
	map[startSprite->getRow()][startSprite->getCol()] = endSprite;
	map[endSprite->getRow()][endSprite->getCol()] = startSprite;

	int tmpRow = startSprite->getRow();
	int tmpCol = startSprite->getCol();
	startSprite->setRow(endSprite->getRow());
	startSprite->setCol(endSprite->getCol());
	endSprite->setRow(tmpRow);
	endSprite->setCol(tmpCol);

	// 检查是否能消除
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
		// 如果能够消除，仅仅进行移动（不会移动回来）
		startSprite->runAction(MoveTo::create(time, posOfDest));
		endSprite->runAction(MoveTo::create(time, posOfSrc));
		myFrequency();//修改次数
		return;
	}

	// 不能消除，则移动过去还要返回
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

//放置剩余次数
void GameScene::myFrequency()
{
	--m_frequency;
	if (m_frequency == 0)//如果次数归0，直接结束游戏
	{
		Label* labelFrequency = (Label*)this->getChildByTag(11);
		labelFrequency->setScale(0);
		
		auto gmov = Sprite::create("pic_gameover.png");
		gmov->setPosition(Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_WIDTH * 1.5));
		this->addChild(gmov);

		auto action = MoveTo::create(3.0f, Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_WIDTH / 2));
		gmov->runAction(action);

		auto scene = GameOver::createScene();
		CCDirector::sharedDirector()->replaceScene(scene);

		return;
	}
	if (m_frequency > 0)//大于零，改变输出的数字
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

// 欢迎界面 初始化函数
bool GameScene::init()	
{
	// 先初始化父类，不成功返回false
	if( !Layer::init() )	
	{
		return false;
	}
	//添加音乐
	SimpleAudioEngine* audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("music_bg.mp3");
	audio->setBackgroundMusicVolume(0);

	// 加载plist和png
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("icon.plist");
    spriteSheet = SpriteBatchNode::create("icon.png");
    addChild(spriteSheet);
	mapLBX = (GAME_SCREEN_WIDTH - SPRITE_WIDTH * COLS - (COLS - 1) * BOADER_WIDTH) / 2;
	mapLBY = (GAME_SCREEN_HEIGHT - SPRITE_WIDTH * ROWS - (ROWS - 1) * BOADER_WIDTH) / 2;

	// 添加背景图片
	auto sprite = Sprite::create("scene_bg.png");
	sprite->setPosition(Point(GAME_SCREEN_WIDTH/2,GAME_SCREEN_HEIGHT/2));
    this->addChild(sprite,-1);

	// 添加返回按钮
	auto backItem = MenuItemImage::create(
                                           "btn_back01.png",
                                           "btn_back02.png",
										   CC_CALLBACK_1(GameScene::menuBackCallback, this));
	backItem->setPosition(Vec2(GAME_SCREEN_WIDTH-backItem->getContentSize().width/2,backItem->getContentSize().height/2));
	
	//添加设置按钮
	auto set_upItem = MenuItemImage::create("set_up.png",
		                                    "set_up.png", 
		                                    CC_CALLBACK_1(GameScene::menuSetupCallBack, this,audio));
	set_upItem->setPosition(Vec2(GAME_SCREEN_WIDTH/1.1, GAME_SCREEN_WIDTH/1.7));
	set_upItem->setScale(0.1);


	auto menu = Menu::create(backItem, set_upItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	// 加载ttf字体
	TTFConfig config("fonts/haibaoti.ttf", 30);
	//显示分数
	auto labelScore = Label::createWithTTF(config, StringUtils::format("Score: %d ", m_score));
	labelScore->setPosition(Vec2(GAME_SCREEN_WIDTH - backItem->getContentSize().width / 2, backItem->getContentSize().height / 2 + labelScore->getContentSize().height * 2.6));
	labelScore->setTag(10);
	this->addChild(labelScore);
	
	//添加监听器
	auto labelTime = Label::createWithTTF(config, StringUtils::format("Frequency: %d", m_frequency));
	labelTime->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25, GAME_SCREEN_WIDTH / 2));
	labelTime->setTag(11);
	this->addChild(labelTime);

	// 触摸事件处理
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	touchListener->setSwallowTouches(true);
	initMap();
	scheduleUpdate();
	return true;
}

// 返回函数，跳转到欢迎界面
void GameScene::menuBackCallback( Ref* pSender )	
{
	auto scene = WelcomeScene::createScene();
	CCDirector::sharedDirector()->replaceScene(scene);
}

//设置函数，打开设置界面
void GameScene::menuSetupCallBack(Ref* pSender, SimpleAudioEngine* audio)
{
	auto spriteSetup = Sprite::create("setup.png");
	spriteSetup->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_WIDTH / 2.3)));
	spriteSetup->setScale(0.2);
	this->addChild(spriteSetup);

	auto musicStrItem = MenuItemImage::create("music_str.png", 
		                                      "music_str.png", 
		                                      CC_CALLBACK_1(GameScene::menuMusicStrCallBack,this));
	musicStrItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 0.8, GAME_SCREEN_WIDTH / 0.5)));
	musicStrItem->setScale(2);

	auto musicCloseItem = MenuItemImage::create("musicclose.png", 
		                                        "musicclose.png", 
		                                        CC_CALLBACK_1(GameScene::menuMusicCloseCallBack, this));
	musicCloseItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 1.1, GAME_SCREEN_WIDTH / 0.5)));
	musicCloseItem->setScale(2);

	auto musicPlusItem = MenuItemImage::create("plus.png",
		                                      "plus.png", 
		                                       CC_CALLBACK_1(GameScene::menuMusicPlusCallBack, this, audio));
	musicPlusItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 0.65, GAME_SCREEN_WIDTH / 0.7)));
	musicPlusItem->setScale(0.5);

	auto musicMinusItem = MenuItemImage::create("minus.png", 
		                                        "minus.png", 
		                                        CC_CALLBACK_1(GameScene::menuMusicMinusCallBack, this,audio));
	musicMinusItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 1.8, GAME_SCREEN_WIDTH / 0.7)));
	musicMinusItem->setScale(0.5);

	auto deleteItem = MenuItemImage::create("delete.png",
		                                    "delete.png",
		                                    CC_CALLBACK_1(GameScene::menuReturnCallBack, this, spriteSetup));
	deleteItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 0.49, GAME_SCREEN_WIDTH / 0.49)));
	deleteItem->setScale(0.3);

	auto menu = Menu::create(musicStrItem, musicCloseItem, deleteItem, musicMinusItem, musicPlusItem, NULL);
	menu->setPosition(Vec2::ZERO);
	spriteSetup->addChild(menu);

}

void GameScene::menuMusicPlusCallBack(Ref* pSender, SimpleAudioEngine* audio)
{
	musicNum += 0.1;
	audio->setBackgroundMusicVolume(musicNum);
}

void GameScene::menuMusicMinusCallBack(Ref* pSender, SimpleAudioEngine* audio)
{
	musicNum -= 0.1;
	audio->setBackgroundMusicVolume(musicNum);
}

//关闭设置界面
void GameScene::menuReturnCallBack(Ref* pSender, Sprite* spr)
{
	spr->removeFromParent();
}

//音乐开始函数
void GameScene::menuMusicStrCallBack(Ref* pSender)
{
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music_bg.mp3", true);
}

//音乐暂停函数
void GameScene::menuMusicCloseCallBack(Ref* pSender)
{
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// 初始化地图
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

// 创建精灵
void GameScene::createSprite( int row , int col )	
{
	
	SpriteShape* temp = SpriteShape::create(row, col);
	
	// 创建下落动画
	Point endPosition = getposition(row, col);
	Point startPosition = Point(endPosition.x, endPosition.y + GAME_SCREEN_HEIGHT / 2);
    temp->setPosition(startPosition);
	float speed = startPosition.y / (1.5 * GAME_SCREEN_HEIGHT );
    temp->runAction(MoveTo::create(speed, endPosition));
    // 加入到spriteSheet中,等待绘制
    spriteSheet -> addChild(temp);

    map[row][col] = temp;
}

// 根据行列，获取坐标值
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