#include "GameScene.h"
#include "SpriteShape.h"
#include "WelcomeScene.h"


Scene* GameScene::createScene()	{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
	return scene;
}

// ��ӭ���� ��ʼ������
bool GameScene::init()	
{
	// �ȳ�ʼ�����࣬���ɹ�����false
	if( !Layer::init() )	
	{
		return false;
	}

	// ����plist��png
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("icon.plist");
    spriteSheet = SpriteBatchNode::create("icon.png");
    addChild(spriteSheet);

	// ��ӱ���ͼƬ
	auto sprite = Sprite::create("scene_bg.png");
	sprite->setPosition(Point(GAME_SCREEN_WIDTH/2,GAME_SCREEN_HEIGHT/2));
    this->addChild(sprite,-1);

	// ��ӷ��ذ�ť
	auto backItem = MenuItemImage::create(
                                           "btn_back01.png",
                                           "btn_back02.png",
										   CC_CALLBACK_1(GameScene::menuBackCallback, this));
	backItem->setPosition(Vec2(GAME_SCREEN_WIDTH-backItem->getContentSize().width/2,backItem->getContentSize().height/2));

	auto menu = Menu::create(backItem, NULL);
    menu->setPosition(Vec2::ZERO);
	this -> addChild( menu );
	
	initMap();

	return true;
}

// ���غ�������ת����ӭ����
void GameScene::menuBackCallback( Ref* pSender )	
{
	auto scene = WelcomeScene::createScene();
	CCDirector::sharedDirector()->replaceScene(scene);
}

// ��ʼ����ͼ
void GameScene::initMap( )	
{
	
	for( int i = 0 ; i < ROWS ;i++ )
	{
		for( int j = 0 ; j < COLS ; j++)
		{
			createSprite(i,j);
		}
	}
}

// ��������
void GameScene::createSprite( int row , int col )	
{
	
	SpriteShape* temp = SpriteShape::create(row, col);
	
	// �������䶯��
	Point endPosition = getposition(row, col);
	Point startPosition = Point(endPosition.x, endPosition.y + GAME_SCREEN_HEIGHT / 2);
    temp->setPosition(startPosition);
	float speed = startPosition.y / (1.5 * GAME_SCREEN_HEIGHT );
    temp->runAction(MoveTo::create(speed, endPosition));
    // ���뵽spriteSheet��,�ȴ�����
    spriteSheet -> addChild(temp);

    map[row][col] = temp;
}

// �������У���ȡ����ֵ
Point GameScene::getposition(int row , int col)
{
	float x = (SPRITE_WIDTH + BOADER_WIDTH) * col + SPRITE_WIDTH / 2;
    float y = (SPRITE_WIDTH + BOADER_WIDTH) * row + SPRITE_WIDTH / 2;
    return Point(x, y);
}