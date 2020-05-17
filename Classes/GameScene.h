#pragma once
#ifndef _GAME_Scene_H_
#define _GAME_Scene_H_
#include"cocos2d.h"

class GameScene :public cocos2d::Layer
{
public:
	//��������
	static cocos2d::Scene* createScene();
	virtual bool init();//��ʼ��
	//���ؿ�ʼ��Ϸ����
	void menuBackCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(GameScene);
	//��Ϸ����
	//��ʼ����Ϸ����
	void initMap();
	//��������
	void createSprite(int, int);
	Point positionOfItem(int, int);
};
#endif
