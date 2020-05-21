#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameDefine.h"

USING_NS_CC;

class SpriteShape;


class GameScene : public Layer
{
public:
	GameScene();
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

	Point positionOfItem(int row, int col);
	

	//���ڸ���ÿһ֡�Ķ���
	void update(float t);
	void checkAndRemoveSprite();
	void markRemove(SpriteShape* spr);
	void removeSprite();
	void explodeSprite(SpriteShape* spr);
	void actionEndCallBack(Node* node);
	void getColChain(SpriteShape* spr, std::list<SpriteShape*>& chainList);
	void getRowChain(SpriteShape* spr, std::list<SpriteShape*>& chainList);
	void fillSprite();

	CREATE_FUNC(GameScene);
private:
	// ����һ��ͼƬ
	SpriteBatchNode* spriteSheet;
	// ��ά����
	SpriteShape* map[ROWS][COLS];
	float mapLBX, mapLBY;

	bool isAction, isFillSprite;//�����ж��Ƿ���ִ�ж������Ƿ���Ҫ���ȱ
};

#endif // __GAME_SCENE_H__