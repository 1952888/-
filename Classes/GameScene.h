#pragma once
#ifndef _GAME_Scene_H_
#define _GAME_Scene_H_
#include"cocos2d.h"

class GameScene :public cocos2d::Layer
{
public:
	//基础功能
	static cocos2d::Scene* createScene();
	virtual bool init();//初始化
	//返回开始游戏界面
	void menuBackCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(GameScene);
	//游戏功能
	//初始化游戏界面
	void initMap();
	//创建精灵
	void createSprite(int, int);
	Point positionOfItem(int, int);
};
#endif
