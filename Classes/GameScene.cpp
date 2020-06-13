#include "GameScene.h"
#include "SpriteShape.h"
#include "WelcomeScene.h"
#include"GameOverScene.h"
#include "BagScene.h"
#include "RankingScene.h"
<<<<<<< HEAD

using namespace CocosDenshion;

extern int score[10];
extern int score_num;

extern int fourDisappearNum;
extern int plus5Num;
=======
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129

using namespace CocosDenshion;

extern int score[10];
extern int score_num;

extern int fourDisappearNum;
extern int plus5Num;
extern bool success;
extern int status;
extern int temp_score;
GameScene::GameScene()
	:spriteSheet(NULL)
<<<<<<< HEAD
	,isFillSprite(false)
	,isAction(true)
	,isTouchEna(true)
	,m_frequency(30)
	,m_score(0)
	,musicNum(0.5)
=======
	, isFillSprite(false)
	, isAction(true)
	, isTouchEna(true)
	, m_frequency(30)
	,m_score(temp_score)
	, musicNum(0.5)
	, isUse(true)
	,temp1(NULL)
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
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



<<<<<<< HEAD
bool GameScene::checkIfDeadMap()//查看是否是死地图
=======
bool GameScene::checkIfDeadMap()//�鿴�Ƿ�������ͼ
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
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

<<<<<<< HEAD
void GameScene::checkAndRemoveSprite()//查看并移除三连以上的精灵
=======

// ����Ƿ��о�������Ƴ�
void GameScene::checkAndRemoveSprite()
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	SpriteShape *spr;
	// �趨��˾�ĺ��Ӽ�飬֮ǰ�����о������ú��Ӽ�飬����μ��Ҫ��֮ǰ���еļ�鶼���ܺ���
	for (int r = 0; r < ROWS; ++r) {
		for (int c = 0; c < COLS; ++c) {
			spr = map[r][c];
			if (!spr) {
				continue;
			}
			spr->setIgnoreCheck(false);
		}
	}


	for (int r = 0; r < ROWS; ++r) {
		for (int c = 0; c < COLS; ++c) {
			spr = map[r][c];
			// �����λ��û�о���
			if (!spr) {
				continue;
			}
			// ����þ�����Ҫ���Ƴ�
			if (spr->getIsNeedRemove()) {
				continue;
			}
			// ����þ����������ɵľ���
			if (spr->getIgnoreCheck()) {
				continue;
			}

			// ������ͬ����List
			std::list< SpriteShape *> colChainList;
			getColChain(spr, colChainList);
			// ������ͬ����List
			std::list< SpriteShape *> rowChainList;
			getRowChain(spr, rowChainList);
<<<<<<< HEAD
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
=======

			std::list< SpriteShape *> longerList;
			if (colChainList.size() >= rowChainList.size()) {
				if (colChainList.size() < 3) {
					continue;
				}
				longerList = colChainList;
				isRow = false;
			}
			else if (rowChainList.size() > colChainList.size()) {
				if (rowChainList.size() < 3) {
					continue;
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
				}
				longerList = rowChainList;
				isRow = true;
			}

			std::list<SpriteShape *>::iterator itList;
			// ��־ �Ƿ���Ҫ�趨���Ӽ��ľ���
			bool isSetedIgnoreCheck = false;

			for (itList = longerList.begin(); itList != longerList.end(); ++itList) {
				spr = (SpriteShape *)* itList;
				if (!spr) {
					continue;
				}

				if (longerList.size() > 3) {
					if (spr == startSprite || spr == endSprite) {
						isSetedIgnoreCheck = true;
						spr->setIgnoreCheck(true);
						spr->setIsNeedRemove(false);
						spr->setDisplayMode(isRow ? DISPLAY_MODE_HORIZONTAL : DISPLAY_MODE_VERTICAL);
						continue;
					}
<<<<<<< HEAD
					//标记需要删除的精灵
					markRemove(spr);
=======
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
				}
				markRemove(spr);
			}
			// ��������ɵ��������4��, ȡ���һ���仯Ϊ���⾫��
			if (!isSetedIgnoreCheck && longerList.size() > 3) {
				spr->setIgnoreCheck(true);
				spr->setIsNeedRemove(false);
				spr->setDisplayMode(isRow ? DISPLAY_MODE_HORIZONTAL : DISPLAY_MODE_VERTICAL);
			}
		}
	}
<<<<<<< HEAD
	//删除被标记的精灵
	removeSprite();
}

void GameScene::markRemove(SpriteShape* spr)//标记需要删除的精灵
{
	if (spr->getIsNeedRemove())//如果已经被标记，则直接返回
=======

	// ��������˵ľ���
	removeSprite();
}

// ��ǿ����Ƴ��ľ���
void GameScene::markRemove(SpriteShape* spr) {

	// ����Ѿ������Ҫ�Ƴ����Ͳ���Ҫ�ٱ��
	if (spr->getIsNeedRemove()) 
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	{
		return;
	}
	// ����þ��鱻���ӣ�����Ҫ���
	if (spr->getIgnoreCheck()) {
		return;
	}

	// �ȱ���Լ�
	spr->setIsNeedRemove(true);
	// �����Ҫ��ǵľ����Ƿ�Ϊ �������⾫��
	if (spr->getDisplayMode() == DISPLAY_MODE_VERTICAL)
	{
		for (int r = 0; r < ROWS; ++r) {
			SpriteShape* tmp = map[r][spr->getCol()];
			if (!tmp || tmp == spr) {
				continue;
			}

			if (tmp->getDisplayMode() == DISPLAY_MODE_NORMAL) {
				tmp->setIsNeedRemove(true);
			}
			else {
				markRemove(tmp);
			}
		}
	}
	else if (spr->getDisplayMode() == DISPLAY_MODE_HORIZONTAL) {
		for (int c = 0; c < COLS; ++c) {
			SpriteShape *tmp = map[spr->getRow()][c];
			if (!tmp || tmp == spr) {
				continue;
			}

			if (tmp->getDisplayMode() == DISPLAY_MODE_NORMAL) {
				tmp->setIsNeedRemove(true);
			}
			else {
				markRemove(tmp);
			}
		}
	}
}

<<<<<<< HEAD
void GameScene::removeSprite()//删除精灵
=======
// �Ƴ�����
void GameScene::removeSprite()
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	// ��һ���Ƴ��Ķ���
	isAction = true;

	for (int r = 0; r < ROWS; ++r) {
		for (int c = 0; c < COLS; ++c) {
			SpriteShape* spr = map[r][c];
<<<<<<< HEAD
			if (!spr)//如果已经被删除，跳过这次循环
			{
				continue;
			}
			if (spr->getIsNeedRemove())//如果需要被删除，删除精灵，修改isFillSprite
			{
=======
			if (!spr) {
				continue;
			}

			if (spr->getIsNeedRemove()) {
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
				isFillSprite = true;

				if (spr->getDisplayMode() == DISPLAY_MODE_HORIZONTAL)
				{
					explodeSpecialH(spr->getPosition());
				}
				else if (spr->getDisplayMode() == DISPLAY_MODE_VERTICAL)
				{
					explodeSpecialV(spr->getPosition());
				}
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

<<<<<<< HEAD
void GameScene::actionEndCallBack(Node* node)//删除精灵函数
=======

// ����ĺ�������
void GameScene::explodeSpecialH(Point point)
{
	

	// ��������Ӧ�ı���
	float scaleX = 4;
	float scaleY = 0.7;
	float time = 0.3;
	Point startPosition = point;
	float speed = 0.6f;

	auto colorSpriteRight = Sprite::create("colorHRight.png");
	addChild(colorSpriteRight, 10);
	Point endPosition1 = Point(point.x - GAME_SCREEN_WIDTH, point.y);
	colorSpriteRight->setPosition(startPosition);
	colorSpriteRight->runAction(Sequence::create(ScaleTo::create(time, scaleX, scaleY),
		MoveTo::create(speed, endPosition1),
		CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, colorSpriteRight)),
		NULL));

	auto colorSpriteLeft = Sprite::create("colorHLeft.png");
	addChild(colorSpriteLeft, 10);
	Point endPosition2 = Point(point.x + GAME_SCREEN_WIDTH, point.y);
	colorSpriteLeft->setPosition(startPosition);
	colorSpriteLeft->runAction(Sequence::create(ScaleTo::create(time, scaleX, scaleY),
		MoveTo::create(speed, endPosition2),
		CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, colorSpriteLeft)),
		NULL));


}

// �������������
void GameScene::explodeSpecialV(Point point)
{

	float scaleY = 4;
	float scaleX = 0.7;
	float time = 0.3;
	Point startPosition = point;
	float speed = 0.6f;

	auto colorSpriteDown = Sprite::create("colorVDown.png");
	addChild(colorSpriteDown, 10);
	Point endPosition1 = Point(point.x, point.y - GAME_SCREEN_HEIGHT);
	colorSpriteDown->setPosition(startPosition);
	colorSpriteDown->runAction(Sequence::create(ScaleTo::create(time, scaleX, scaleY),
		MoveTo::create(speed, endPosition1),
		CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, colorSpriteDown)),
		NULL));

	auto colorSpriteUp = Sprite::create("colorVUp.png");
	addChild(colorSpriteUp, 10);
	Point endPosition2 = Point(point.x, point.y + GAME_SCREEN_HEIGHT);
	colorSpriteUp->setPosition(startPosition);
	colorSpriteUp->runAction(Sequence::create(ScaleTo::create(time, scaleX, scaleY),
		MoveTo::create(speed, endPosition2),
		CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, colorSpriteUp)),
		NULL));


}

// ���Ƴ��ľ�����еĲ���

void GameScene::actionEndCallBack(Node* node)//ɾ�����麯��
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	SpriteShape* spr = (SpriteShape*)node;
	map[spr->getRow()][spr->getCol()] = NULL;
	spr->removeFromParent();
<<<<<<< HEAD
	//加载爆炸音乐
=======
	//���ر�ը����
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
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
<<<<<<< HEAD
	
	neighborRow = spr->getRow() + 1;//向下
=======

	neighborRow = spr->getRow() + 1;//����
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
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



<<<<<<< HEAD
// 开始触摸
bool GameScene::onTouchBegan(Touch *touch, Event *unused) 
=======
// ��ʼ����
bool GameScene::onTouchBegan(Touch *touch, Event *unused)
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	startSprite = NULL;
	endSprite = NULL;

	if (isTouchEna)
	{
		auto position = touch->getLocation();
		startSprite = spriteOfPoint(&position);
	}
	return isTouchEna;
}

<<<<<<< HEAD
// 触摸后移动的方向
=======
bool GameScene::onTouchBegan1(Touch *touch, Event *unused)
{
	temp1 = NULL;

	if (!isUse)
	{
		auto position = touch->getLocation();
		temp1 = spriteOfPoint(&position);
		isUse++;
	}
	return isUse;

	
}

// �������ƶ��ķ���
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
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

<<<<<<< HEAD
	// 判断是在向哪个方向移动，
	if (upRect.containsPoint(location)) 
=======
	// �ж��������ĸ������ƶ���
	if (upRect.containsPoint(location))
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
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

<<<<<<< HEAD
// 根据触摸的点位置，返回是地图中哪个精灵
=======

void GameScene::onTouchMoved1(Touch *touch, Event *unused)
{
	// ���û�г�ʼ���� ���� �����¼������У�ֱ�ӷ���
	if (!temp1 || !isUse)
	{
		return;
	}

	// ��ȡ�ƶ����� �� ��λ��
	auto location = touch->getLocation();
	auto halfSpriteWidth = SPRITE_WIDTH / 2;
	auto halfSpriteHeight = SPRITE_WIDTH / 2;

	auto  upRect = Rect(temp1->getPositionX() - halfSpriteWidth,
		temp1->getPositionY() + halfSpriteHeight,
		SPRITE_WIDTH,
		SPRITE_WIDTH);

	// �ж��������ĸ������ƶ���
	if (upRect.containsPoint(location))
	{
		
		temp1->setDisplayMode(  DISPLAY_MODE_VERTICAL);
		markRemove(temp1);
		removeSprite();
	
		
		return;
	}

	auto  downRect = Rect(temp1->getPositionX() - halfSpriteWidth,
		temp1->getPositionY() - (halfSpriteHeight * 3),
		SPRITE_WIDTH,
		SPRITE_WIDTH);

	if (downRect.containsPoint(location))
	{
		
		temp1->setDisplayMode(DISPLAY_MODE_VERTICAL);
		markRemove(temp1);
		removeSprite();
		
		return;
	}

	auto  leftRect = Rect(temp1->getPositionX() - (halfSpriteWidth * 3),
		temp1->getPositionY() - halfSpriteHeight,
		SPRITE_WIDTH,
		SPRITE_WIDTH);

	if (leftRect.containsPoint(location))
	{
		
		temp1->setDisplayMode(DISPLAY_MODE_HORIZONTAL);
		markRemove(temp1);
		removeSprite();
			//explodeSpecialH(temp1->getPosition());
		
		return;
	}

	auto  rightRect = Rect(temp1->getPositionX() + halfSpriteWidth,
		temp1->getPositionY() - halfSpriteHeight,
		SPRITE_WIDTH,
		SPRITE_WIDTH);

	if (rightRect.containsPoint(location))
	{
		
		temp1->setDisplayMode(DISPLAY_MODE_HORIZONTAL);
		markRemove(temp1);
		removeSprite();
		return;
	}

	// ���򣬲���һ����Ч���ƶ�
}


// ���ݴ����ĵ�λ�ã������ǵ�ͼ���ĸ�����
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
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

<<<<<<< HEAD
// 交换精灵
void GameScene::swapSprite() 
=======
// ��������
void GameScene::swapSprite()
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	// 移动中，不允许再次触摸，执行动作设置为true
	isAction = true;
	isTouchEna = false;

<<<<<<< HEAD
	// 初始精灵 和 终止精灵 均不能为空
	if (!startSprite || !endSprite) 
=======
	// ��ʼ���� �� ��ֹ���� ������Ϊ��
	if (!startSprite || !endSprite)
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
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
	myFrequency();
}

//放置剩余次数
void GameScene::myFrequency()
{
	--m_frequency;
	if (m_frequency == 0)//如果次数归0，直接结束游戏
	{
<<<<<<< HEAD
		//如果分数大于1000，获得增加次数道具
		if (m_score > 1000)
		{
			plus5Num++;
		}

=======
		//�����������1000��������Ӵ�������
		if (m_score-temp_score> 1000)
		{
			plus5Num++;
		}
		if (m_score-temp_score > 2000)
		{
			fourDisappearNum++;
		}
		if (m_score > status*1000+4000)
		{
			success = true;
		}
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
		Label* labelFrequency = (Label*)this->getChildByTag(11);
		labelFrequency->setScale(0);

		auto gmov = Sprite::create("pic_gameover.png");
		gmov->setPosition(Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_WIDTH * 1.5));
		this->addChild(gmov);

		auto action = MoveTo::create(3.0f, Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_WIDTH / 2));
		gmov->runAction(action);

		auto scene = GameOver::createScene();
		auto layer = GameOver::create();
<<<<<<< HEAD
		auto rankingScene = RankingScene::createScene();
		auto rankingLayer = RankingScene::create();
		// 传递当前游戏获得的分数
		layer->setScore(m_score);
		scene->addChild(layer);

		score[score_num] = m_score;
		score_num++;
=======
		

		if (!success)
		{
			auto rankingScene = RankingScene::createScene();
			auto rankingLayer = RankingScene::create();
			score[score_num] = m_score;
			score_num++;
		}
		else
			temp_score = m_score;

		// ���ݵ�ǰ��Ϸ��õķ���
		layer->setScore(m_score);
		scene->addChild(layer);
		
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129

		CCTransitionScene* reScene = CCTransitionFadeUp::create(1.0f, scene);
		CCDirector::sharedDirector()->replaceScene(reScene);

		return;
	}
	if (m_frequency > 0)//大于零，改变输出的数字
	{
		Label* labelFrequency = (Label*)this->getChildByTag(11);
		labelFrequency->setString(StringUtils::format("Frequency: %d", m_frequency));
	}
}


Scene* GameScene::createScene() 
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

<<<<<<< HEAD
// 欢迎界面 初始化函数
bool GameScene::init()	
{
	// 先初始化父类，不成功返回false
	if( !Layer::init() )	
=======
// ��ӭ���� ��ʼ������
bool GameScene::init()
{
	// �ȳ�ʼ�����࣬���ɹ�����false
	if (!Layer::init())
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	{
		return false;
	}
	//添加音乐
	SimpleAudioEngine* audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("music_bg.mp3");
	audio->setBackgroundMusicVolume(0);

<<<<<<< HEAD
	// 加载plist和png
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("icon.plist");
    spriteSheet = SpriteBatchNode::create("icon.png");
    addChild(spriteSheet);
	mapLBX = (GAME_SCREEN_WIDTH - SPRITE_WIDTH * COLS - (COLS - 1) * BOADER_WIDTH) / 2;
	mapLBY = (GAME_SCREEN_HEIGHT - SPRITE_WIDTH * ROWS - (ROWS - 1) * BOADER_WIDTH) / 2;

	// 添加背景图片
=======
	//�������
	SimpleAudioEngine* audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("music_bg.mp3");
	audio->setBackgroundMusicVolume(0);

	// ����plist��png
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("icon.plist");
	spriteSheet = SpriteBatchNode::create("icon.png");
	addChild(spriteSheet);
	mapLBX = (GAME_SCREEN_WIDTH - SPRITE_WIDTH * COLS - (COLS - 1) * BOADER_WIDTH) / 2;
	mapLBY = (GAME_SCREEN_HEIGHT - SPRITE_WIDTH * ROWS - (ROWS - 1) * BOADER_WIDTH) / 2;

	// ��ӱ���ͼƬ
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	auto sprite = Sprite::create("scene_bg.png");
	sprite->setPosition(Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 2));
	this->addChild(sprite, -1);

	// 添加返回按钮
	auto backItem = MenuItemImage::create(
<<<<<<< HEAD
                                           "btn_back01.png",
                                           "btn_back02.png",
										   CC_CALLBACK_1(GameScene::menuBackCallback, this));
	backItem->setPosition(Vec2(GAME_SCREEN_WIDTH-backItem->getContentSize().width/2,backItem->getContentSize().height/2));
	
	//添加设置按钮
	auto set_upItem = MenuItemImage::create("set_up.png",
		                                    "set_up.png", 
		                                    CC_CALLBACK_1(GameScene::menuSetupCallBack, this,audio));
	set_upItem->setPosition(Vec2(GAME_SCREEN_WIDTH/1.1, GAME_SCREEN_WIDTH/1.7));
=======
		"btn_back01.png",
		"btn_back02.png",
		CC_CALLBACK_1(GameScene::menuBackCallback, this));
	backItem->setPosition(Vec2(GAME_SCREEN_WIDTH - backItem->getContentSize().width / 2, backItem->getContentSize().height / 2));

	//������ð�ť
	auto set_upItem = MenuItemImage::create("set_up.png",
		"set_up.png",
		CC_CALLBACK_1(GameScene::menuSetupCallBack, this, audio));
	set_upItem->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.1, GAME_SCREEN_WIDTH / 1.7));
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	set_upItem->setScale(0.1);


	auto menu = Menu::create(backItem, set_upItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

<<<<<<< HEAD
	// 加载ttf字体
=======
	// ����ttf����
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	TTFConfig config("fonts/haibaoti.ttf", 30);
	//显示分数
	auto labelScore = Label::createWithTTF(config, StringUtils::format("Score: %d ", m_score));
	labelScore->setPosition(Vec2(GAME_SCREEN_WIDTH - backItem->getContentSize().width / 2, backItem->getContentSize().height / 2 + labelScore->getContentSize().height * 2.6));
	labelScore->setTag(10);
	this->addChild(labelScore);

	
<<<<<<< HEAD
	//添加监听器
=======
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	auto labelTime = Label::createWithTTF(config, StringUtils::format("Frequency: %d", m_frequency));
	labelTime->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25, GAME_SCREEN_WIDTH / 2));
	labelTime->setTag(11);
	this->addChild(labelTime);

	int* pfrequency = &m_frequency;

<<<<<<< HEAD
	//添加两个道具照片和数据
	//添加增加次数道具
	TTFConfig configfour("fonts/fourDisappearNum.ttf", 30);
	TTFConfig configplus("fonts/plus5Num.ttf", 30);
	auto plus5Pic = MenuItemImage::create("plus5.png",
		                                  "plus5.png",
		                                  CC_CALLBACK_1(GameScene::menuPlus5Callback, this, pfrequency));
	plus5Pic->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 - 50, GAME_SCREEN_WIDTH / 2 - 35));
	plus5Pic->setScale(0.3);
	//添加增加次数Num
=======
	//�������������Ƭ������
	//������Ӵ�������
	TTFConfig configfour("fonts/fourDisappearNum.ttf", 30);
	TTFConfig configplus("fonts/plus5Num.ttf", 30);
	auto plus5Pic = MenuItemImage::create("plus5.png",
		"plus5.png",
		CC_CALLBACK_1(GameScene::menuPlus5Callback, this, pfrequency));
	plus5Pic->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 - 50, GAME_SCREEN_WIDTH / 2 - 35));
	plus5Pic->setScale(0.3);

	//������Ӵ���Num
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	auto labelplus5Num = Label::createWithTTF(configplus, "  0  ");
	labelplus5Num->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 + 30, GAME_SCREEN_WIDTH / 2 - 35));
	labelplus5Num->setString(StringUtils::format("  %d  ", plus5Num));
	labelplus5Num->setTag(21);
	this->addChild(labelplus5Num);

<<<<<<< HEAD
	//添加四消道具
	auto fourDisappearPic = MenuItemImage::create("fourDisappear.png",
		                                          "fourDisappear.png",
		                                          CC_CALLBACK_1(GameScene::menufourDisappearCallback, this));
	fourDisappearPic->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 - 50, GAME_SCREEN_WIDTH / 2 - 80));
	fourDisappearPic->setScale(0.3);
	//添加四消Num
=======
	//�����������
	auto fourDisappearPic = MenuItemImage::create("fourDisappear.png",
		"fourDisappear.png",
		CC_CALLBACK_1(GameScene::menufourDisappearCallback, this));
	fourDisappearPic->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 - 50, GAME_SCREEN_WIDTH / 2 - 80));
	fourDisappearPic->setScale(0.3);
	//�������Num
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	auto labelfourDisappearNum = Label::createWithTTF(configfour, "  0  ");
	labelfourDisappearNum->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 + 30, GAME_SCREEN_WIDTH / 2 - 80));
	labelfourDisappearNum->setString(StringUtils::format("  %d  ", fourDisappearNum));
	labelfourDisappearNum->setTag(22);
	this->addChild(labelfourDisappearNum);
<<<<<<< HEAD
	//添加有两个道具的menu
=======
	//������������ߵ�menu
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	auto menu2 = Menu::create(plus5Pic, fourDisappearPic, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2);

<<<<<<< HEAD
	// 触摸事件处理
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	touchListener->setSwallowTouches(true);
=======


	auto touchListener1= EventListenerTouchOneByOne::create();

	touchListener1->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan1, this);
	touchListener1->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved1, this);
	_eventDispatcher->addEventListenerWithFixedPriority(touchListener1, 1);


	
	auto touchListener2= EventListenerTouchOneByOne::create();
	touchListener2->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	touchListener2->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithFixedPriority(touchListener2, 2);
	

>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	initMap();
	scheduleUpdate();
	return true;
}

<<<<<<< HEAD
// 返回函数，跳转到欢迎界面
void GameScene::menuBackCallback( Ref* pSender )	
=======
// ���غ�������ת����ӭ����
void GameScene::menuBackCallback(Ref* pSender)
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	auto scene = WelcomeScene::createScene();
	CCDirector::sharedDirector()->replaceScene(scene);
}

<<<<<<< HEAD
//设置函数，打开设置界面
=======
//���ú����������ý���
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
void GameScene::menuSetupCallBack(Ref* pSender, SimpleAudioEngine* audio)
{
	auto spriteSetup = Sprite::create("setup.png");
	spriteSetup->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_WIDTH / 2.3)));
	spriteSetup->setScale(0.2);
	this->addChild(spriteSetup);

<<<<<<< HEAD
	auto musicStrItem = MenuItemImage::create("music_str.png", 
		                                      "music_str.png", 
		                                      CC_CALLBACK_1(GameScene::menuMusicStrCallBack,this));
	musicStrItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 0.8, GAME_SCREEN_WIDTH / 0.5)));
	musicStrItem->setScale(2);

	auto musicCloseItem = MenuItemImage::create("musicclose.png", 
		                                        "musicclose.png", 
		                                        CC_CALLBACK_1(GameScene::menuMusicCloseCallBack, this));
=======
	auto musicStrItem = MenuItemImage::create("music_str.png",
		"music_str.png",
		CC_CALLBACK_1(GameScene::menuMusicStrCallBack, this));
	musicStrItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 0.8, GAME_SCREEN_WIDTH / 0.5)));
	musicStrItem->setScale(2);

	auto musicCloseItem = MenuItemImage::create("musicclose.png",
		"musicclose.png",
		CC_CALLBACK_1(GameScene::menuMusicCloseCallBack, this));
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	musicCloseItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 1.1, GAME_SCREEN_WIDTH / 0.5)));
	musicCloseItem->setScale(2);

	auto musicPlusItem = MenuItemImage::create("plus.png",
<<<<<<< HEAD
		                                      "plus.png", 
		                                       CC_CALLBACK_1(GameScene::menuMusicPlusCallBack, this, audio));
	musicPlusItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 0.65, GAME_SCREEN_WIDTH / 0.7)));
	musicPlusItem->setScale(0.5);

	auto musicMinusItem = MenuItemImage::create("minus.png", 
		                                        "minus.png", 
		                                        CC_CALLBACK_1(GameScene::menuMusicMinusCallBack, this,audio));
=======
		"plus.png",
		CC_CALLBACK_1(GameScene::menuMusicPlusCallBack, this, audio));
	musicPlusItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 0.65, GAME_SCREEN_WIDTH / 0.7)));
	musicPlusItem->setScale(0.5);

	auto musicMinusItem = MenuItemImage::create("minus.png",
		"minus.png",
		CC_CALLBACK_1(GameScene::menuMusicMinusCallBack, this, audio));
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	musicMinusItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 1.8, GAME_SCREEN_WIDTH / 0.7)));
	musicMinusItem->setScale(0.5);

	auto deleteItem = MenuItemImage::create("delete.png",
<<<<<<< HEAD
		                                    "delete.png",
		                                    CC_CALLBACK_1(GameScene::menuReturnCallBack, this, spriteSetup));
=======
		"delete.png",
		CC_CALLBACK_1(GameScene::menuReturnCallBack, this, spriteSetup));
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	deleteItem->setPosition(Vec2(Point(GAME_SCREEN_WIDTH / 0.49, GAME_SCREEN_WIDTH / 0.49)));
	deleteItem->setScale(0.3);

	auto menu = Menu::create(musicStrItem, musicCloseItem, deleteItem, musicMinusItem, musicPlusItem, NULL);
	menu->setPosition(Vec2::ZERO);
	spriteSetup->addChild(menu);

}

void GameScene::menuMusicPlusCallBack(Ref* pSender, SimpleAudioEngine* audio)
{
<<<<<<< HEAD
	musicNum += 0.1;
=======
	musicNum += 1;
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	audio->setBackgroundMusicVolume(musicNum);
}

void GameScene::menuMusicMinusCallBack(Ref* pSender, SimpleAudioEngine* audio)
{
<<<<<<< HEAD
	musicNum -= 0.1;
	audio->setBackgroundMusicVolume(musicNum);
}

//关闭设置界面
=======
	musicNum -= 1;
	audio->setBackgroundMusicVolume(musicNum);
}

//�ر����ý���
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
void GameScene::menuReturnCallBack(Ref* pSender, Sprite* spr)
{
	spr->removeFromParent();
}

<<<<<<< HEAD
//音乐开始函数
=======
//���ֿ�ʼ����
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
void GameScene::menuMusicStrCallBack(Ref* pSender)
{
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music_bg.mp3", true);
}

<<<<<<< HEAD
//音乐暂停函数
=======
//������ͣ����
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
void GameScene::menuMusicCloseCallBack(Ref* pSender)
{
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

<<<<<<< HEAD
// 初始化地图
void GameScene::initMap( )	
=======
// ��ʼ����ͼ
void GameScene::initMap()
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			createSprite(i, j);
		}
	}
}

<<<<<<< HEAD
// 创建精灵
void GameScene::createSprite( int row , int col )	
=======
// ��������
void GameScene::createSprite(int row, int col)
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{

	SpriteShape* temp = SpriteShape::create(row, col);
<<<<<<< HEAD
	
	// 创建下落动画
	Point endPosition = getposition(row, col);
	Point startPosition = Point(endPosition.x, endPosition.y + GAME_SCREEN_HEIGHT / 2);
    temp->setPosition(startPosition);
	float speed = startPosition.y / (1.5 * GAME_SCREEN_HEIGHT );
    temp->runAction(MoveTo::create(speed, endPosition));
    // 加入到spriteSheet中,等待绘制
    spriteSheet -> addChild(temp);
=======

	// �������䶯��
	Point endPosition = getposition(row, col);
	Point startPosition = Point(endPosition.x, endPosition.y + GAME_SCREEN_HEIGHT / 2);
	temp->setPosition(startPosition);
	float speed = startPosition.y / (1.5 * GAME_SCREEN_HEIGHT);
	temp->runAction(MoveTo::create(speed, endPosition));
	// ���뵽spriteSheet��,�ȴ�����
	spriteSheet->addChild(temp);
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129

	map[row][col] = temp;
}

<<<<<<< HEAD
// 根据行列，获取坐标值
Point GameScene::getposition(int row , int col)
=======
// �������У���ȡ����ֵ
Point GameScene::getposition(int row, int col)
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
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

void GameScene::menuPlus5Callback(Ref* pSender, int*pfrequency)
{
	if (plus5Num == 0)
		return;
	if (plus5Num > 0)
	{
		m_frequency += 5;
		plus5Num--;
		Label* labelFrequency = (Label*)this->getChildByTag(11);
		labelFrequency->setString(StringUtils::format("Frequency: %d", m_frequency));

		Label* labelPlus5 = (Label*)this->getChildByTag(21);
		labelPlus5->setString(StringUtils::format("%d", plus5Num));
		return;
	}
}

void GameScene::menufourDisappearCallback(Ref* pSender)
{
<<<<<<< HEAD
	return;
}
=======
	if (fourDisappearNum == 0)
		return;
	if (fourDisappearNum > 0)
	{
		isUse = 0;
		fourDisappearNum-=1;
	
		Label* labelfourDisappearNum = (Label*)this->getChildByTag(22);
		labelfourDisappearNum->setString(StringUtils::format("%d", fourDisappearNum));
		return;
	}
}

>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
