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

void GameScene::update(float t)//æ›´æ–°æ¯ä¸€å¸§
{
	if (isAction)//å¦‚æœæ­£åœ¨åŠ¨ä½œï¼ŒæŸ¥çœ‹æ˜¯å¦æœ‰å…¶ä»–ç²¾çµæ­£åœ¨åŠ¨ä½œ
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

	// å¦‚æœç²¾çµæ­£åœ¨ç§»åŠ¨ä¸­ï¼Œå¿½è§†è§¦æ‘¸äº‹ä»¶
	isTouchEna = !isAction;
	if (!isAction)//å¦‚æœä¸åœ¨åŠ¨ä½œï¼ŒæŸ¥çœ‹æ˜¯å¦éœ€è¦å¡«å……ç²¾çµï¼Œå¦‚æœä¸éœ€è¦å¡«å……ç²¾çµï¼ŒæŸ¥çœ‹æ˜¯å¦è¦ç§»é™¤ç²¾çµ
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
bool GameScene::checkIfDeadMap()//æŸ¥çœ‹æ˜¯å¦æ˜¯æ­»åœ°å›¾
=======
bool GameScene::checkIfDeadMap()//²é¿´ÊÇ·ñÊÇËÀµØÍ¼
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	for (int r = 0; r < ROWS; ++r)//ä¸€å…±12ç§æƒ…å†µï¼Œå¦‚æœå…¨ä¸æ»¡è¶³åˆ™è¿”å›false
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
void GameScene::checkAndRemoveSprite()//æŸ¥çœ‹å¹¶ç§»é™¤ä¸‰è¿ä»¥ä¸Šçš„ç²¾çµ
=======

// ¼ì²âÊÇ·ñÓĞ¾«Áé¿ÉÒÔÒÆ³ı
void GameScene::checkAndRemoveSprite()
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	SpriteShape *spr;
	// Éè¶¨ÊÙË¾µÄºöÊÓ¼ì²é£¬Ö®Ç°¿ÉÄÜÓĞ¾«ÁéÉèÖÃºöÊÓ¼ì²é£¬µ«Õâ´Î¼ì²éÒª½«Ö®Ç°ËùÓĞµÄ¼ì²é¶¼²»ÄÜºöÊÓ
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
			// Èç¹û¸ÃÎ»ÖÃÃ»ÓĞ¾«Áé
			if (!spr) {
				continue;
			}
			// Èç¹û¸Ã¾«ÁéĞèÒª±»ÒÆ³ı
			if (spr->getIsNeedRemove()) {
				continue;
			}
			// Èç¹û¸Ã¾«ÁéÊÇĞÂÉú³ÉµÄ¾«Áé
			if (spr->getIgnoreCheck()) {
				continue;
			}

			// ×İÏòÏàÍ¬¾«ÁéList
			std::list< SpriteShape *> colChainList;
			getColChain(spr, colChainList);
			// ºáÏòÏàÍ¬¾«ÁéList
			std::list< SpriteShape *> rowChainList;
			getRowChain(spr, rowChainList);
<<<<<<< HEAD
			//å¾—åˆ°è¾ƒé•¿çš„List
			std::list<SpriteShape*>& longerList = colChainList.size() > rowChainList.size() ? colChainList : rowChainList;
			if (longerList.size() < 3)//å¦‚æœListå°äº3ï¼Œç›´æ¥è·³è¿‡
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
					//æ ‡è®°éœ€è¦åˆ é™¤çš„ç²¾çµ
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
			// ±êÖ¾ ÊÇ·ñĞèÒªÉè¶¨ºöÊÓ¼ì²éµÄ¾«Áé
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
					//æ ‡è®°éœ€è¦åˆ é™¤çš„ç²¾çµ
					markRemove(spr);
=======
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
				}
				markRemove(spr);
			}
			// ÈçºÎÊÇ×ÔÓÉµôÂä²úÉúµÄ4Ïû, È¡×îºóÒ»¸ö±ä»¯ÎªÌØÊâ¾«Áé
			if (!isSetedIgnoreCheck && longerList.size() > 3) {
				spr->setIgnoreCheck(true);
				spr->setIsNeedRemove(false);
				spr->setDisplayMode(isRow ? DISPLAY_MODE_HORIZONTAL : DISPLAY_MODE_VERTICAL);
			}
		}
	}
<<<<<<< HEAD
	//åˆ é™¤è¢«æ ‡è®°çš„ç²¾çµ
	removeSprite();
}

void GameScene::markRemove(SpriteShape* spr)//æ ‡è®°éœ€è¦åˆ é™¤çš„ç²¾çµ
{
	if (spr->getIsNeedRemove())//å¦‚æœå·²ç»è¢«æ ‡è®°ï¼Œåˆ™ç›´æ¥è¿”å›
=======

	// Ïû³ı±ê¼ÇÁËµÄ¾«Áé
	removeSprite();
}

// ±ê¼Ç¿ÉÒÔÒÆ³ıµÄ¾«Áé
void GameScene::markRemove(SpriteShape* spr) {

	// Èç¹ûÒÑ¾­±ê¼ÇÁËÒªÒÆ³ı£¬¾Í²»ĞèÒªÔÙ±ê¼Ç
	if (spr->getIsNeedRemove()) 
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	{
		return;
	}
	// Èç¹û¸Ã¾«Áé±»ºöÊÓ£¬²»ĞèÒª±ê¼Ç
	if (spr->getIgnoreCheck()) {
		return;
	}

	// ÏÈ±ê¼Ç×Ô¼º
	spr->setIsNeedRemove(true);
	// ¼ì²éĞèÒª±ê¼ÇµÄ¾«ÁéÊÇ·ñÎª ËÄÏûÌØÊâ¾«Áé
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
void GameScene::removeSprite()//åˆ é™¤ç²¾çµ
=======
// ÒÆ³ı¾«Áé
void GameScene::removeSprite()
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	// ×öÒ»Ì×ÒÆ³ıµÄ¶¯×÷
	isAction = true;

	for (int r = 0; r < ROWS; ++r) {
		for (int c = 0; c < COLS; ++c) {
			SpriteShape* spr = map[r][c];
<<<<<<< HEAD
			if (!spr)//å¦‚æœå·²ç»è¢«åˆ é™¤ï¼Œè·³è¿‡è¿™æ¬¡å¾ªç¯
			{
				continue;
			}
			if (spr->getIsNeedRemove())//å¦‚æœéœ€è¦è¢«åˆ é™¤ï¼Œåˆ é™¤ç²¾çµï¼Œä¿®æ”¹isFillSprite
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

void GameScene::explodeSprite(SpriteShape* spr)//çˆ†ç‚¸åˆ é™¤
{
	//ä¸€ä¸ªçˆ†ç‚¸åŠ¨ä½œ
	spr->runAction(Sequence::create(ScaleTo::create(0.2f, 0.0),
		CallFuncN::create(CC_CALLBACK_1(GameScene::actionEndCallBack, this)),
		NULL));
}

<<<<<<< HEAD
void GameScene::actionEndCallBack(Node* node)//åˆ é™¤ç²¾çµå‡½æ•°
=======

// ¾«ÁéµÄºáÏòÏû³ı
void GameScene::explodeSpecialH(Point point)
{
	

	// ÏÈÉèÖÃÏàÓ¦µÄ±äÁ¿
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

// ¾«ÁéµÄ×İÏòÏû³ı
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

// ¶ÔÒÆ³ıµÄ¾«Áé½øĞĞµÄ²Ù×÷

void GameScene::actionEndCallBack(Node* node)//É¾³ı¾«Áéº¯Êı
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	SpriteShape* spr = (SpriteShape*)node;
	map[spr->getRow()][spr->getCol()] = NULL;
	spr->removeFromParent();
<<<<<<< HEAD
	//åŠ è½½çˆ†ç‚¸éŸ³ä¹
=======
	//¼ÓÔØ±¬Õ¨ÒôÀÖ
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	SimpleAudioEngine::sharedEngine()->playEffect("music_explode.wav", false);
}

void GameScene::getColChain(SpriteShape* spr, std::list<SpriteShape*>& chainList)//è·å–å·¦å³ç›¸åŒç²¾çµçš„List
{
	chainList.push_back(spr);

	int neighborCol = spr->getCol() - 1;//å‘å·¦
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

	neighborCol = spr->getCol() + 1;//å‘å³
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

void GameScene::getRowChain(SpriteShape* spr, std::list<SpriteShape*>&chainList)//è·å–ä¸Šä¸‹ç›¸åŒç²¾çµçš„List
{
	chainList.push_back(spr);

	int neighborRow = spr->getRow() - 1;//å‘ä¸Š
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
	
	neighborRow = spr->getRow() + 1;//å‘ä¸‹
=======

	neighborRow = spr->getRow() + 1;//ÏòÏÂ
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

void GameScene::fillSprite()//å¡«å……ç²¾çµï¼Œæ˜¯å…ˆè®©å·²å­˜åœ¨çš„ç²¾çµä¸‹è½ï¼Œä¹‹ååœ¨åˆ›å»ºæ–°çš„ç²¾çµ
{
	isAction = true;
	int sum = 0;//è®¡ç®—åˆ†æ•°

	int* colEmptyInfo = (int*)malloc(sizeof(int) * COLS);//åˆ›å»ºå˜é‡ï¼Œè®°å½•ç›¸åº”åˆ—æ•°ç§»é™¤çš„æ•°é‡
	memset((void*)colEmptyInfo, 0, sizeof(int) * COLS);

	SpriteShape* spr = NULL;
	for (int c = 0; c < COLS; ++c)//éå†map
	{
		//è‡ªåº•å‘ä¸Š
		int removedSpriteOfCol = 0;
		for (int r = 0; r < ROWS; ++r)
		{
			spr = map[r][c];
			if (spr == NULL)//å¦‚æœè¿™ä¸ªä½ç½®æ²¡æœ‰ç²¾çµï¼Œå˜é‡è‡ªå¢
			{
				++removedSpriteOfCol;
			}
			else//åœ¨ç¬¬ä¸€ä¸ªå‡ºç°ç²¾çµçš„ä½ç½®ï¼Œè®©ç²¾çµä¸‹è½
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
		colEmptyInfo[c] = removedSpriteOfCol;//è®°å½•æ¯åˆ—è¢«æ¶ˆé™¤çš„ç²¾çµæ•°é‡
		sum += removedSpriteOfCol;
	}

	for (int c = 0; c < COLS; ++c)//åˆ›å»ºæ–°çš„ç²¾çµä¸‹è½
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
// å¼€å§‹è§¦æ‘¸
bool GameScene::onTouchBegan(Touch *touch, Event *unused) 
=======
// ¿ªÊ¼´¥Ãş
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
// è§¦æ‘¸åç§»åŠ¨çš„æ–¹å‘
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

// ´¥ÃşºóÒÆ¶¯µÄ·½Ïò
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
void GameScene::onTouchMoved(Touch *touch, Event *unused)
{
	// å¦‚æœæ²¡æœ‰åˆå§‹ç²¾çµ æˆ–è€… è§¦æ‘¸äº‹ä»¶ä¸å¯è¡Œï¼Œç›´æ¥è¿”å›
	if (!startSprite || !isTouchEna)
	{
		return;
	}


	// è·å– åˆå§‹ç²¾çµ çš„è¡Œåˆ—
	int row = startSprite->getRow();
	int col = startSprite->getCol();

	// è·å–ç§»åŠ¨åˆ°çš„ ç‚¹ çš„ä½ç½®
	auto location = touch->getLocation();
	auto halfSpriteWidth = SPRITE_WIDTH / 2;
	auto halfSpriteHeight = SPRITE_WIDTH / 2;

	auto  upRect = Rect(startSprite->getPositionX() - halfSpriteWidth,
		startSprite->getPositionY() + halfSpriteHeight,
		SPRITE_WIDTH,
		SPRITE_WIDTH);

<<<<<<< HEAD
	// åˆ¤æ–­æ˜¯åœ¨å‘å“ªä¸ªæ–¹å‘ç§»åŠ¨ï¼Œ
	if (upRect.containsPoint(location)) 
=======
	// ÅĞ¶ÏÊÇÔÚÏòÄÄ¸ö·½ÏòÒÆ¶¯£¬
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

	// å¦åˆ™ï¼Œå¹¶éä¸€ä¸ªæœ‰æ•ˆçš„ç§»åŠ¨
}

<<<<<<< HEAD
// æ ¹æ®è§¦æ‘¸çš„ç‚¹ä½ç½®ï¼Œè¿”å›æ˜¯åœ°å›¾ä¸­å“ªä¸ªç²¾çµ
=======

void GameScene::onTouchMoved1(Touch *touch, Event *unused)
{
	// Èç¹ûÃ»ÓĞ³õÊ¼¾«Áé »òÕß ´¥ÃşÊÂ¼ş²»¿ÉĞĞ£¬Ö±½Ó·µ»Ø
	if (!temp1 || !isUse)
	{
		return;
	}

	// »ñÈ¡ÒÆ¶¯µ½µÄ µã µÄÎ»ÖÃ
	auto location = touch->getLocation();
	auto halfSpriteWidth = SPRITE_WIDTH / 2;
	auto halfSpriteHeight = SPRITE_WIDTH / 2;

	auto  upRect = Rect(temp1->getPositionX() - halfSpriteWidth,
		temp1->getPositionY() + halfSpriteHeight,
		SPRITE_WIDTH,
		SPRITE_WIDTH);

	// ÅĞ¶ÏÊÇÔÚÏòÄÄ¸ö·½ÏòÒÆ¶¯£¬
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

	// ·ñÔò£¬²¢·ÇÒ»¸öÓĞĞ§µÄÒÆ¶¯
}


// ¸ù¾İ´¥ÃşµÄµãÎ»ÖÃ£¬·µ»ØÊÇµØÍ¼ÖĞÄÄ¸ö¾«Áé
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
// äº¤æ¢ç²¾çµ
void GameScene::swapSprite() 
=======
// ½»»»¾«Áé
void GameScene::swapSprite()
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	// ç§»åŠ¨ä¸­ï¼Œä¸å…è®¸å†æ¬¡è§¦æ‘¸ï¼Œæ‰§è¡ŒåŠ¨ä½œè®¾ç½®ä¸ºtrue
	isAction = true;
	isTouchEna = false;

<<<<<<< HEAD
	// åˆå§‹ç²¾çµ å’Œ ç»ˆæ­¢ç²¾çµ å‡ä¸èƒ½ä¸ºç©º
	if (!startSprite || !endSprite) 
=======
	// ³õÊ¼¾«Áé ºÍ ÖÕÖ¹¾«Áé ¾ù²»ÄÜÎª¿Õ
	if (!startSprite || !endSprite)
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	{
		return;
	}

	Point posOfSrc = startSprite->getPosition();
	Point posOfDest = endSprite->getPosition();

	float time = 0.2;

	// åœ¨æ•°ç»„ä¸­äº¤æ¢ä½ç½®
	map[startSprite->getRow()][startSprite->getCol()] = endSprite;
	map[endSprite->getRow()][endSprite->getCol()] = startSprite;

	int tmpRow = startSprite->getRow();
	int tmpCol = startSprite->getCol();
	startSprite->setRow(endSprite->getRow());
	startSprite->setCol(endSprite->getCol());
	endSprite->setRow(tmpRow);
	endSprite->setCol(tmpCol);

	// æ£€æŸ¥æ˜¯å¦èƒ½æ¶ˆé™¤
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
		// å¦‚æœèƒ½å¤Ÿæ¶ˆé™¤ï¼Œä»…ä»…è¿›è¡Œç§»åŠ¨ï¼ˆä¸ä¼šç§»åŠ¨å›æ¥ï¼‰
		startSprite->runAction(MoveTo::create(time, posOfDest));
		endSprite->runAction(MoveTo::create(time, posOfSrc));
		myFrequency();//ä¿®æ”¹æ¬¡æ•°
		return;
	}

	// ä¸èƒ½æ¶ˆé™¤ï¼Œåˆ™ç§»åŠ¨è¿‡å»è¿˜è¦è¿”å›
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

//æ”¾ç½®å‰©ä½™æ¬¡æ•°
void GameScene::myFrequency()
{
	--m_frequency;
	if (m_frequency == 0)//å¦‚æœæ¬¡æ•°å½’0ï¼Œç›´æ¥ç»“æŸæ¸¸æˆ
	{
<<<<<<< HEAD
		//å¦‚æœåˆ†æ•°å¤§äº1000ï¼Œè·å¾—å¢åŠ æ¬¡æ•°é“å…·
		if (m_score > 1000)
		{
			plus5Num++;
		}

=======
		//Èç¹û·ÖÊı´óÓÚ1000£¬»ñµÃÔö¼Ó´ÎÊıµÀ¾ß
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
		// ä¼ é€’å½“å‰æ¸¸æˆè·å¾—çš„åˆ†æ•°
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

		// ´«µİµ±Ç°ÓÎÏ·»ñµÃµÄ·ÖÊı
		layer->setScore(m_score);
		scene->addChild(layer);
		
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129

		CCTransitionScene* reScene = CCTransitionFadeUp::create(1.0f, scene);
		CCDirector::sharedDirector()->replaceScene(reScene);

		return;
	}
	if (m_frequency > 0)//å¤§äºé›¶ï¼Œæ”¹å˜è¾“å‡ºçš„æ•°å­—
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
// æ¬¢è¿ç•Œé¢ åˆå§‹åŒ–å‡½æ•°
bool GameScene::init()	
{
	// å…ˆåˆå§‹åŒ–çˆ¶ç±»ï¼Œä¸æˆåŠŸè¿”å›false
	if( !Layer::init() )	
=======
// »¶Ó­½çÃæ ³õÊ¼»¯º¯Êı
bool GameScene::init()
{
	// ÏÈ³õÊ¼»¯¸¸Àà£¬²»³É¹¦·µ»Øfalse
	if (!Layer::init())
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	{
		return false;
	}
	//æ·»åŠ éŸ³ä¹
	SimpleAudioEngine* audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("music_bg.mp3");
	audio->setBackgroundMusicVolume(0);

<<<<<<< HEAD
	// åŠ è½½plistå’Œpng
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("icon.plist");
    spriteSheet = SpriteBatchNode::create("icon.png");
    addChild(spriteSheet);
	mapLBX = (GAME_SCREEN_WIDTH - SPRITE_WIDTH * COLS - (COLS - 1) * BOADER_WIDTH) / 2;
	mapLBY = (GAME_SCREEN_HEIGHT - SPRITE_WIDTH * ROWS - (ROWS - 1) * BOADER_WIDTH) / 2;

	// æ·»åŠ èƒŒæ™¯å›¾ç‰‡
=======
	//Ìí¼ÓÒôÀÖ
	SimpleAudioEngine* audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("music_bg.mp3");
	audio->setBackgroundMusicVolume(0);

	// ¼ÓÔØplistºÍpng
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("icon.plist");
	spriteSheet = SpriteBatchNode::create("icon.png");
	addChild(spriteSheet);
	mapLBX = (GAME_SCREEN_WIDTH - SPRITE_WIDTH * COLS - (COLS - 1) * BOADER_WIDTH) / 2;
	mapLBY = (GAME_SCREEN_HEIGHT - SPRITE_WIDTH * ROWS - (ROWS - 1) * BOADER_WIDTH) / 2;

	// Ìí¼Ó±³¾°Í¼Æ¬
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	auto sprite = Sprite::create("scene_bg.png");
	sprite->setPosition(Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 2));
	this->addChild(sprite, -1);

	// æ·»åŠ è¿”å›æŒ‰é’®
	auto backItem = MenuItemImage::create(
<<<<<<< HEAD
                                           "btn_back01.png",
                                           "btn_back02.png",
										   CC_CALLBACK_1(GameScene::menuBackCallback, this));
	backItem->setPosition(Vec2(GAME_SCREEN_WIDTH-backItem->getContentSize().width/2,backItem->getContentSize().height/2));
	
	//æ·»åŠ è®¾ç½®æŒ‰é’®
	auto set_upItem = MenuItemImage::create("set_up.png",
		                                    "set_up.png", 
		                                    CC_CALLBACK_1(GameScene::menuSetupCallBack, this,audio));
	set_upItem->setPosition(Vec2(GAME_SCREEN_WIDTH/1.1, GAME_SCREEN_WIDTH/1.7));
=======
		"btn_back01.png",
		"btn_back02.png",
		CC_CALLBACK_1(GameScene::menuBackCallback, this));
	backItem->setPosition(Vec2(GAME_SCREEN_WIDTH - backItem->getContentSize().width / 2, backItem->getContentSize().height / 2));

	//Ìí¼ÓÉèÖÃ°´Å¥
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
	// åŠ è½½ttfå­—ä½“
=======
	// ¼ÓÔØttf×ÖÌå
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	TTFConfig config("fonts/haibaoti.ttf", 30);
	//æ˜¾ç¤ºåˆ†æ•°
	auto labelScore = Label::createWithTTF(config, StringUtils::format("Score: %d ", m_score));
	labelScore->setPosition(Vec2(GAME_SCREEN_WIDTH - backItem->getContentSize().width / 2, backItem->getContentSize().height / 2 + labelScore->getContentSize().height * 2.6));
	labelScore->setTag(10);
	this->addChild(labelScore);

	
<<<<<<< HEAD
	//æ·»åŠ ç›‘å¬å™¨
=======
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	auto labelTime = Label::createWithTTF(config, StringUtils::format("Frequency: %d", m_frequency));
	labelTime->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25, GAME_SCREEN_WIDTH / 2));
	labelTime->setTag(11);
	this->addChild(labelTime);

	int* pfrequency = &m_frequency;

<<<<<<< HEAD
	//æ·»åŠ ä¸¤ä¸ªé“å…·ç…§ç‰‡å’Œæ•°æ®
	//æ·»åŠ å¢åŠ æ¬¡æ•°é“å…·
	TTFConfig configfour("fonts/fourDisappearNum.ttf", 30);
	TTFConfig configplus("fonts/plus5Num.ttf", 30);
	auto plus5Pic = MenuItemImage::create("plus5.png",
		                                  "plus5.png",
		                                  CC_CALLBACK_1(GameScene::menuPlus5Callback, this, pfrequency));
	plus5Pic->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 - 50, GAME_SCREEN_WIDTH / 2 - 35));
	plus5Pic->setScale(0.3);
	//æ·»åŠ å¢åŠ æ¬¡æ•°Num
=======
	//Ìí¼ÓÁ½¸öµÀ¾ßÕÕÆ¬ºÍÊı¾İ
	//Ìí¼ÓÔö¼Ó´ÎÊıµÀ¾ß
	TTFConfig configfour("fonts/fourDisappearNum.ttf", 30);
	TTFConfig configplus("fonts/plus5Num.ttf", 30);
	auto plus5Pic = MenuItemImage::create("plus5.png",
		"plus5.png",
		CC_CALLBACK_1(GameScene::menuPlus5Callback, this, pfrequency));
	plus5Pic->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 - 50, GAME_SCREEN_WIDTH / 2 - 35));
	plus5Pic->setScale(0.3);

	//Ìí¼ÓÔö¼Ó´ÎÊıNum
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	auto labelplus5Num = Label::createWithTTF(configplus, "  0  ");
	labelplus5Num->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 + 30, GAME_SCREEN_WIDTH / 2 - 35));
	labelplus5Num->setString(StringUtils::format("  %d  ", plus5Num));
	labelplus5Num->setTag(21);
	this->addChild(labelplus5Num);

<<<<<<< HEAD
	//æ·»åŠ å››æ¶ˆé“å…·
	auto fourDisappearPic = MenuItemImage::create("fourDisappear.png",
		                                          "fourDisappear.png",
		                                          CC_CALLBACK_1(GameScene::menufourDisappearCallback, this));
	fourDisappearPic->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 - 50, GAME_SCREEN_WIDTH / 2 - 80));
	fourDisappearPic->setScale(0.3);
	//æ·»åŠ å››æ¶ˆNum
=======
	//Ìí¼ÓËÄÏûµÀ¾ß
	auto fourDisappearPic = MenuItemImage::create("fourDisappear.png",
		"fourDisappear.png",
		CC_CALLBACK_1(GameScene::menufourDisappearCallback, this));
	fourDisappearPic->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 - 50, GAME_SCREEN_WIDTH / 2 - 80));
	fourDisappearPic->setScale(0.3);
	//Ìí¼ÓËÄÏûNum
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	auto labelfourDisappearNum = Label::createWithTTF(configfour, "  0  ");
	labelfourDisappearNum->setPosition(Vec2(GAME_SCREEN_WIDTH / 1.25 + 30, GAME_SCREEN_WIDTH / 2 - 80));
	labelfourDisappearNum->setString(StringUtils::format("  %d  ", fourDisappearNum));
	labelfourDisappearNum->setTag(22);
	this->addChild(labelfourDisappearNum);
<<<<<<< HEAD
	//æ·»åŠ æœ‰ä¸¤ä¸ªé“å…·çš„menu
=======
	//Ìí¼ÓÓĞÁ½¸öµÀ¾ßµÄmenu
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
	auto menu2 = Menu::create(plus5Pic, fourDisappearPic, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2);

<<<<<<< HEAD
	// è§¦æ‘¸äº‹ä»¶å¤„ç†
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
// è¿”å›å‡½æ•°ï¼Œè·³è½¬åˆ°æ¬¢è¿ç•Œé¢
void GameScene::menuBackCallback( Ref* pSender )	
=======
// ·µ»Øº¯Êı£¬Ìø×ªµ½»¶Ó­½çÃæ
void GameScene::menuBackCallback(Ref* pSender)
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{
	auto scene = WelcomeScene::createScene();
	CCDirector::sharedDirector()->replaceScene(scene);
}

<<<<<<< HEAD
//è®¾ç½®å‡½æ•°ï¼Œæ‰“å¼€è®¾ç½®ç•Œé¢
=======
//ÉèÖÃº¯Êı£¬´ò¿ªÉèÖÃ½çÃæ
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

//å…³é—­è®¾ç½®ç•Œé¢
=======
	musicNum -= 1;
	audio->setBackgroundMusicVolume(musicNum);
}

//¹Ø±ÕÉèÖÃ½çÃæ
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
void GameScene::menuReturnCallBack(Ref* pSender, Sprite* spr)
{
	spr->removeFromParent();
}

<<<<<<< HEAD
//éŸ³ä¹å¼€å§‹å‡½æ•°
=======
//ÒôÀÖ¿ªÊ¼º¯Êı
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
void GameScene::menuMusicStrCallBack(Ref* pSender)
{
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music_bg.mp3", true);
}

<<<<<<< HEAD
//éŸ³ä¹æš‚åœå‡½æ•°
=======
//ÒôÀÖÔİÍ£º¯Êı
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
void GameScene::menuMusicCloseCallBack(Ref* pSender)
{
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

<<<<<<< HEAD
// åˆå§‹åŒ–åœ°å›¾
void GameScene::initMap( )	
=======
// ³õÊ¼»¯µØÍ¼
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
// åˆ›å»ºç²¾çµ
void GameScene::createSprite( int row , int col )	
=======
// ´´½¨¾«Áé
void GameScene::createSprite(int row, int col)
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129
{

	SpriteShape* temp = SpriteShape::create(row, col);
<<<<<<< HEAD
	
	// åˆ›å»ºä¸‹è½åŠ¨ç”»
	Point endPosition = getposition(row, col);
	Point startPosition = Point(endPosition.x, endPosition.y + GAME_SCREEN_HEIGHT / 2);
    temp->setPosition(startPosition);
	float speed = startPosition.y / (1.5 * GAME_SCREEN_HEIGHT );
    temp->runAction(MoveTo::create(speed, endPosition));
    // åŠ å…¥åˆ°spriteSheetä¸­,ç­‰å¾…ç»˜åˆ¶
    spriteSheet -> addChild(temp);
=======

	// ´´½¨ÏÂÂä¶¯»­
	Point endPosition = getposition(row, col);
	Point startPosition = Point(endPosition.x, endPosition.y + GAME_SCREEN_HEIGHT / 2);
	temp->setPosition(startPosition);
	float speed = startPosition.y / (1.5 * GAME_SCREEN_HEIGHT);
	temp->runAction(MoveTo::create(speed, endPosition));
	// ¼ÓÈëµ½spriteSheetÖĞ,µÈ´ı»æÖÆ
	spriteSheet->addChild(temp);
>>>>>>> 55a6950d7f73a348aa2244862f8241a9dbe20129

	map[row][col] = temp;
}

<<<<<<< HEAD
// æ ¹æ®è¡Œåˆ—ï¼Œè·å–åæ ‡å€¼
Point GameScene::getposition(int row , int col)
=======
// ¸ù¾İĞĞÁĞ£¬»ñÈ¡×ø±êÖµ
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
