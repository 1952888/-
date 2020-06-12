#pragma once


#include "cocos2d.h"

class BagScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuBackCallback(Ref* pSender);


	CREATE_FUNC(BagScene);
};

