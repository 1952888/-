#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameDefine.h"

USING_NS_CC;

class SpriteShape;


class GameScene : public Layer
{
public:
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

	CREATE_FUNC(GameScene);
private:
	// 绘制一批图片
	SpriteBatchNode* spriteSheet;
	// 二维数组
	SpriteShape* map[ROWS][COLS];
};

#endif // __GAME_SCENE_H__