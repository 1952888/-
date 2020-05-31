#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameDefine.h"

USING_NS_CC;
using namespace CocosDenshion;

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
	//�����ý���
	void menuSetupCallBack(Ref* pSender, SimpleAudioEngine* audio);
	//�ر����ý���
	void menuReturnCallBack(Ref* pSender, Sprite* spr);
	//������
	void menuMusicStrCallBack(Ref* pSender);
	//�ر�����
	void menuMusicCloseCallBack(Ref* pSender);
	//��������
	void menuMusicPlusCallBack(Ref* pSender, SimpleAudioEngine* audio);
	//��������
	void menuMusicMinusCallBack(Ref* pSender,SimpleAudioEngine* audio);
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
	int m_score;//����
	bool isAction, isFillSprite;//�����ж��Ƿ���ִ�ж������Ƿ���Ҫ���ȱ
	bool isTouchEna;
	float musicNum;

	int m_frequency;//ʣ�����
};

#endif // __GAME_SCENE_H__