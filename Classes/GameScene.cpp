#include "GameScene.h"
#include"GameDefine.h"
#include"Spriteshapenew.h"
#include"WelcomeScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//添加背景
	auto sprite = Sprite::create("scene_bg.png");
	sprite->setPosition(Point(GAME_SCREEN_WIDTH / 2, GANE_SCREEN_HEIGHT / 2));
	this->addChild(sprite, -1);
	//添加返回按钮
	auto backbutton = MenuItemImage::create("btn_back01.png", "btn_back02.png", CC_CALLBACK_1(GameScene::menuBackCallback, this));
	backbutton->setPosition(Vec2(GAME_SCREEN_WIDTH - backbutton->getContentSize().width / 2, backbutton->getContentSize().height / 2));

	auto menu = Menu::create(backbutton, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
	return true;

}


void GameScene::menuBackCallback(Ref*pSender)
{
	auto scene = WelcomeScene::createScene();
	CCDirector::sharedDirector()->replaceScene(scene);
}
//初始化地图
void GameScene::initMap()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			createSprite(i, j);
		}
	}
}

static SpriteShape* map[ROWS][COLS];
static Scene* spriteSheet;
void GameScene::createSprite(int row, int col)
{
	SpriteShape* temp = SpriteShape::create(row, col);
	Point endPosition = positionOfItem(row, col);
	temp->setPosition(endPosition);
	spriteSheet->addChild(temp);
	map[row][col] = temp;
}

Point GameScene::positionOfItem(int row, int col)
{
	float x = mapLBX + (SPRITE_WIDTH + BOADER_WIDTH)*col + SPRITE_WIDTH / 2;
	float y = mapLBY + (SPRITE_WIDTH + BOADER_WIDTH)*row + SPRITE_WIDTH / 2;
	return Point(x, y);
}
