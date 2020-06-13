#include "GameOverScene.h"
#include "GameScene.h"
#include "WelcomeScene.h"
extern int status;
extern bool success;
extern int temp_score;
Scene* GameOver::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOver::create();
	scene->addChild(layer);
	return scene;
}

bool GameOver::init()
{
	if (!Layer::init()) {
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//获取屏幕尺寸和原点坐标
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	TTFConfig config("fonts/yuehei.otf", 48);

	// 添加背景图片
	auto sprite = Sprite::create("scene_end.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	sprite->setScale(0.4);
	this->addChild(sprite);

	// 添加重新开始按钮
	auto restartItem = MenuItemImage::create(
		"btn_restart01.png",
		"btn_restart02.png",
		CC_CALLBACK_1(GameOver::menuRestartCallback, this));

	restartItem->setPosition(Vec2(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 8));
	restartItem->setScale(0.6);
	//添加进入下一关按钮
	
	auto nextItem = MenuItemImage::create(
			"btn_next02.png","btn_next01.png",
			CC_CALLBACK_1(GameOver::menuNextCallback, this)
	);
	nextItem->setPosition(Vec2(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 5));
	nextItem->setScale(0.6);
	
	// 添加返回主菜单按钮
	auto backItem = MenuItemImage::create(
		"btn_back01.png",
		"btn_back02.png",
		CC_CALLBACK_1(GameOver::menuBackCallback, this));

	backItem->setPosition(Vec2(GAME_SCREEN_WIDTH / 2, backItem->getContentSize().height / 2));
	backItem->setScale(0.6);

	// 添加退出游戏按钮
	auto exitItem = MenuItemImage::create(
		"btn_exit01.png",
		"btn_exit02.png",
		CC_CALLBACK_1(GameOver::menuExitCallback, this));
	exitItem->setPosition(Vec2(GAME_SCREEN_WIDTH - exitItem->getContentSize().width / 2, exitItem->getContentSize().height / 2));

	auto menu = Menu::create(restartItem,nextItem, backItem, exitItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	// 分数
	auto labelScore = Label::createWithTTF(config, "0");
	labelScore->setColor(Color3B::BLUE);
	labelScore->setPosition(Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 3.5));
	labelScore->setTag(13);
	this->addChild(labelScore);

	return true;
}

void GameOver::menuRestartCallback(Ref *pSender)
{
	status = 1;
	temp_score = 0;
	auto scene = GameScene::createScene();
	CCTransitionScene* reScene = CCTransitionMoveInL::create(1.0f, scene);
	CCDirector::sharedDirector()->replaceScene(reScene);
}

void GameOver::menuBackCallback(Ref *pSender)
{
	auto scene = WelcomeScene::createScene();
	CCTransitionScene* reScene = CCTransitionSplitRows::create(1.0f, scene);
	CCDirector::sharedDirector()->replaceScene(reScene);
}

void GameOver::menuExitCallback(Ref *pSender)
{
	Director::getInstance()->end();
}

void GameOver::setScore(int sc)
{
	auto labelScore = (Label *)this->getChildByTag(13);
	labelScore->setString(StringUtils::format(" %d ", sc));
}
void GameOver::menuNextCallback(Ref *pSender)
{
	if (success)
	{
		status++;
		auto scene = GameScene::createScene();
		CCTransitionScene* reScene = CCTransitionMoveInL::create(1.0f, scene);
		CCDirector::sharedDirector()->replaceScene(reScene);
	}
	else
	{
		status = 1;
		auto scene = WelcomeScene::createScene();
		CCTransitionScene* reScene = CCTransitionSplitRows::create(1.0f, scene);
		CCDirector::sharedDirector()->replaceScene(reScene);
	}

	
}
