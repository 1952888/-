#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameDefine.h"

USING_NS_CC;

class SpriteShape;


class GameScene : public Layer
{
public:
    static Scene* createScene();
	virtual bool init();  
	// ��ʼ����ͼ
	void initMap();
	// ��������
	void createSprite( int row , int col );
	// ���ػ�ӭ���溯��
	void menuBackCallback( Ref* pSender );
	// �õ���Ӧ���о��������ֵ
	Point getposition( int row , int col );

	CREATE_FUNC(GameScene);
private:
	// ����һ��ͼƬ
	SpriteBatchNode* spriteSheet;
	// ��ά����
	SpriteShape* map[ROWS][COLS];
};

#endif // __GAME_SCENE_H__