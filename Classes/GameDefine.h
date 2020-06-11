#ifndef  _Inkmoo_Elimination_h_
#define  _Inkmoo_Elimination_h_

#define userDefault CCUserDefault::sharedUserDefault()

// 定义屏幕宽高，这与所做的图片有关
#define GAME_SCREEN_WIDTH 480
#define GAME_SCREEN_HEIGHT 800

// 定义每个精灵大小与边框大小
#define SPRITE_WIDTH 48
#define BOADER_WIDTH 2

// 游戏精灵行数和列数
#define ROWS 6
#define COLS 6

// 精灵种类总数
#define TOTAL_SPRITE 6

#include "SimpleAudioEngine.h"

// 普通的精灵
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

