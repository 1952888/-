#pragma once

#include "cocos2d.h"

class RankingScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	//���ػ�ӭ����
	void menuBackCallback(Ref* pSender);

	CREATE_FUNC(RankingScene);
};

