#include"GameDefine.h"
#include"WelcomeScene.h"
#include"BagScene.h"
//#include<algorithm>

using namespace std;

extern int fourDisappearNum;
extern int plus5Num;
USING_NS_CC;
using namespace CocosDenshion;

Scene* BagScene::createScene()
{
	return BagScene::create();
}


bool BagScene::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();//��ȡ��Ļ�ߴ��ԭ������
	Vec2 origin = Director::getInstance()->getVisibleOrigin();



	//���ر�������
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music_bg.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music_bg.mp3", true);

	auto sprite = Sprite::create("scene_bg.png");//���ÿ�ʼ���汳��
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	sprite->setScale(0.4);
	this->addChild(sprite, 0);

	TTFConfig configfour("fonts/fourDisappearNum.ttf", 30);
	TTFConfig configplus("fonts/plus5Num.ttf", 30);

	// ��ӷ��ذ�ť
	auto backItem = MenuItemImage::create(
		"btn_back01.png",
		"btn_back02.png",
		CC_CALLBACK_1(BagScene::menuBackCallback, this));
	backItem->setPosition(Vec2(visibleSize.width / 2 + origin.x, 15 + origin.y));
	backItem->setScale(0.5);
	//������Ӵ���������Ƭ
	auto plus5Pic = Sprite::create("plus5.png");
	plus5Pic->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50, visibleSize.height / 2 + origin.y + 80));
	plus5Pic->setScale(0.4);
	this->addChild(plus5Pic);
	//������Ӵ���Num
	auto labelplus5Num = Label::createWithTTF(configplus, "  0  ");
	labelplus5Num->setPosition(Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 80));
	labelplus5Num ->setString(StringUtils::format("  %d  ", plus5Num));
	this->addChild(labelplus5Num);

	//�������������Ƭ
	auto fourDisappearPic = Sprite::create("fourDisappear.png");
	fourDisappearPic->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50, visibleSize.height / 2 + origin.y - 50));
	fourDisappearPic->setScale(0.4);
	this->addChild(fourDisappearPic);
	//�������Num
	auto labelfourDisappearNum = Label::createWithTTF(configfour, "  0  ");
	labelfourDisappearNum->setPosition(Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y - 50));
	labelfourDisappearNum->setString(StringUtils::format("  %d  ", fourDisappearNum));
	this->addChild(labelfourDisappearNum);

	auto menu = Menu::create(backItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	return true;
}
void BagScene::menuBackCallback(Ref* pSender)
{
	auto scene = WelcomeScene::createScene();
	CCDirector::sharedDirector()->replaceScene(scene);
}
