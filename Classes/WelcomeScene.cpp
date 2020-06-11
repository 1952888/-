#include "WelcomeScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include"GameOverScene.h"
#include"RankingScene.h"
#include "BagScene.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* WelcomeScene::createScene()
{
    return WelcomeScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in WelcomeScene.cpp\n");
}

// on "init" you need to initialize your instance
bool WelcomeScene::init()
{

    //////////////////////////////
    // 1. super init first
    auto visibleSize = Director::getInstance()->getVisibleSize();//获取屏幕尺寸和原点坐标
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//加载背景音乐
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music_bg.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music_bg.mp3", true);

	auto sprite = Sprite::create("scene_bg.png");//放置开始界面背景
	if (sprite == nullptr)
	{
		problemLoading("scene_bg.png");
	}
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	sprite->setScale(0.4);
	this->addChild(sprite, 0);

	//放置标题 开心消消乐
	auto title = Sprite::create("title.png");
	if(title == nullptr)
	{
		problemLoading("title.png");
	}
	title->setPosition(Vec2(visibleSize.width / 1.95 + origin.x, visibleSize.height / 1.5 + origin.y));
	title->setScale(0.5);
	this->addChild(title, 1);

	//放置排行榜按钮，用于切换排行榜
	auto rankingItem = MenuItemImage::create("ranking.png", 
		                                     "ranking2.png", 
		                                     CC_CALLBACK_1(WelcomeScene::menuRankingCallback, this));
	if (rankingItem == nullptr ||
		rankingItem->getContentSize().width <= 0 ||
		rankingItem->getContentSize().height <= 0)
	{
		problemLoading("ranking.png,ranking2.png");
	}
	rankingItem->setColor(Color3B::BLACK);
	rankingItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2.6));
	rankingItem->setScale(0.4);

	//放置背包按钮，切换到背包界面
	auto bagItem = MenuItemImage::create("bag.png",
		                                 "bag2.png",
		                                 CC_CALLBACK_1(WelcomeScene::menuBagCallback, this));
	if (bagItem == nullptr ||
		bagItem->getContentSize().width <= 0 ||
		bagItem->getContentSize().height <= 0)
	{
		problemLoading("bag.png,bag2.png");
	}
	bagItem->setColor(Color3B::BLACK);
	bagItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3.5));
	bagItem->setScale(0.3);

	//放置开始游戏按钮，用于切换开始界面和游戏场景
	auto startItem = MenuItemImage::create("btn_start01.png", 
		                                   "btn_start02.png", 
		                                   CC_CALLBACK_1(WelcomeScene::menuStartCallback, this));
	if (startItem == nullptr ||
		startItem->getContentSize().width <= 0 ||
		startItem->getContentSize().height <= 0)
	{
		problemLoading("btn_start01.png and byn_start02.png");
	}
	startItem->setColor(Color3B::BLACK);
	startItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	startItem->setScale(0.5);

	//放置结束游戏按钮，用于结束游戏
	auto closeItem = MenuItemImage::create("gamefinish.png", 
		                                   "gamefinish2.png", 
		                                   CC_CALLBACK_1(WelcomeScene::menuCloseCallback, this));
	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'gamefinish.png' and 'gamefinish2.png'");
	}
	closeItem->setColor(Color3B::BLACK);
	closeItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 5));
	closeItem->setScale(0.3);
	
	auto menu = Menu::create(startItem, closeItem, rankingItem, bagItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	
    return true;
}

void WelcomeScene::menuCloseCallback(Ref* pSender)
{
    //关闭游戏的回调函数
    Director::getInstance()->end();
}

void WelcomeScene::menuStartCallback(Ref* pSender)
{
	auto scene = GameScene::createScene();
	CCDirector::sharedDirector()->replaceScene(scene);
}

void WelcomeScene::menuRankingCallback(Ref* pSender)
{
	auto scene = RankingScene::createScene();
	CCDirector::sharedDirector()->replaceScene(scene);
}

void WelcomeScene::menuBagCallback(Ref* pSender)
{
	auto scene = BagScene::createScene();
	CCDirector::sharedDirector()->replaceScene(scene);
}