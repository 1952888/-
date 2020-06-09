#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class WelcomeScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    //�ر���Ϸ�Ļص���������
    void menuCloseCallback(cocos2d::Ref* pSender);
	//�л�����Ϸ�����Ļص���������
	void menuStartCallback(cocos2d::Ref* pSender);
	//�л������а�
	void menuRankingCallback(cocos2d::Ref* pSender);
	//�л�������
	void menuBagCallback(cocos2d::Ref* pSender);


    CREATE_FUNC(WelcomeScene);
};

#endif // __HELLOWORLD_SCENE_H__
