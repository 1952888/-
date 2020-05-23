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
	// ���ݴ����ĵ�λ�ã������ǵ�ͼ���ĸ�����
	SpriteShape* spriteOfPoint(Point *point);

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
	//�ƶ�����
	//������괥��
	/***** �����¼� *****/
	bool onTouchBegan(Touch *touch, Event *unused);
	void onTouchMoved(Touch *touch, Event *unused);
	// ��������
	void swapSprite();
	//ʣ�����
	void myFrequency();
	//����Ƿ�������ͼ
	bool checkIfDeadMap();

	CREATE_FUNC(GameScene);
private:
	// ����һ��ͼƬ
	SpriteBatchNode* spriteSheet;
	// ��ά����
	SpriteShape* map[ROWS][COLS];
	float mapLBX, mapLBY;
	//���ݵľ���
	SpriteShape* startSprite;
	SpriteShape* endSprite;
	bool isAction, isFillSprite;//�����ж��Ƿ���ִ�ж������Ƿ���Ҫ���ȱ
	bool isTouchEna;

	int m_frequency;
};

#endif // __GAME_SCENE_H__