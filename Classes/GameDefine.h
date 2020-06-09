#ifndef  _Inkmoo_Elimination_h_
#define  _Inkmoo_Elimination_h_

#define userDefault CCUserDefault::sharedUserDefault()

// ������Ļ��ߣ�����������ͼƬ�й�
#define GAME_SCREEN_WIDTH 480
#define GAME_SCREEN_HEIGHT 800

// ����ÿ�������С��߿��С
#define SPRITE_WIDTH 48
#define BOADER_WIDTH 2

// ��Ϸ��������������
#define ROWS 6
#define COLS 6

// ������������
#define TOTAL_SPRITE 6

#include "SimpleAudioEngine.h"

// ��ͨ�ľ���
static const char *spriteNormal[TOTAL_SPRITE] = {
	"icon1.png",
	"icon2.png",
	"icon3.png",
	"icon4.png",
	"icon5.png",
    "icon6.png"
};

extern int score[10];
extern int score_num;

extern int fourDisappearNum;
extern int plus5Num;

#endif

