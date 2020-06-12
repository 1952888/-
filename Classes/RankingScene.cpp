#include"GameDefine.h"
#include"WelcomeScene.h"
#include"RankingScene.h"
//#include<algorithm>

using namespace std;

USING_NS_CC;
using namespace CocosDenshion;

extern int score_num;
extern int score[10];

bool cmp(int,int);

Scene* RankingScene::createScene()
{
	return RankingScene::create();
}


bool RankingScene::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();//获取屏幕尺寸和原点坐标
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	

	//加载背景音乐
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music_bg.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music_bg.mp3", true);

	auto sprite = Sprite::create("scene_bg.png");//放置开始界面背景
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	sprite->setScale(0.4);
	this->addChild(sprite, 0);

	// 添加返回按钮
	auto backItem = MenuItemImage::create(
		"btn_back01.png",
		"btn_back02.png",
		CC_CALLBACK_1(RankingScene::menuBackCallback, this));
	backItem->setPosition(Vec2(visibleSize.width / 2 + origin.x, 15 + origin.y));
	backItem->setScale(0.5);

	auto rankingSprite = Sprite::create("ranking2.png");
	rankingSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height - 25 + origin.y));
	rankingSprite->setScale(0.5);
	this->addChild(rankingSprite, 0);

	sort(score, score + score_num, cmp);
	for (int i = 0; i < score_num; ++i)
	{
		TTFConfig config("fonts/haibaoti.ttf", 30);
		auto labelHScore = Label::createWithTTF(config, "Highest: 0");
		labelHScore->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height - 70 + origin.y - 25 * i));
		labelHScore->setString(StringUtils::format("%d ", score[i]));
		this->addChild(labelHScore);
	}

	auto menu = Menu::create(backItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	return true;
}
void RankingScene::menuBackCallback(Ref* pSender)
{
	auto scene = WelcomeScene::createScene();
	CCDirector::sharedDirector()->replaceScene(scene);
}
bool cmp(int a, int b)
{
	return a > b;
}
