#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameDefine.h"

USING_NS_CC;

class SpriteShape;


class GameScene : public Layer
{
public:
	GameScene();
    static Scene* createScene();
	virtual bool init();  
	// 初始化地图
	void initMap();
	// 创建精灵
	void createSprite( int row , int col );
	// 返回欢迎界面函数
	void menuBackCallback( Ref* pSender );
	// 得到对应行列精灵的坐标值
	Point getposition( int row , int col );

	Point positionOfItem(int row, int col);
	

	//用于更新每一帧的动作
	void update(float t);
	void checkAndRemoveSprite();
	void markRemove(SpriteShape* spr);
	void removeSprite();
	void explodeSprite(SpriteShape* spr);
	void actionEndCallBack(Node* node);
	void getColChain(SpriteShape* spr, std::list<SpriteShape*>& chainList);
	void getRowChain(SpriteShape* spr, std::list<SpriteShape*>& chainList);
	void fillSprite();

	CREATE_FUNC(GameScene);
private:
	// 绘制一批图片
	SpriteBatchNode* spriteSheet;
	// 二维数组
	SpriteShape* map[ROWS][COLS];
	float mapLBX, mapLBY;

	bool isAction, isFillSprite;//用来判断是否在执行动作，是否需要填补空缺
};

#endif // __GAME_SCENE_H__