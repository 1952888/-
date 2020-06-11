#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class WelcomeScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    //关闭游戏的回调函数声明
    void menuCloseCallback(cocos2d::Ref* pSender);
	//切换到游戏场景的回调函数声明
	void menuStartCallback(cocos2d::Ref* pSender);
	//切换到排行榜
	void menuRankingCallback(cocos2d::Ref* pSender);
	//切换到背包
	void menuBagCallback(cocos2d::Ref* pSender);


    CREATE_FUNC(WelcomeScene);
};

#endif // __HELLOWORLD_SCENE_H__
