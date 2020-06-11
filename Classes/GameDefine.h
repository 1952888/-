#ifndef  _Inkmoo_Elimination_h_
#define  _Inkmoo_Elimination_h_

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



// 精灵的显示模式，Hor 横向消除一行，Ver纵向消除一列
enum DisplayMode 
{
	DISPLAY_MODE_NORMAL = 0,
	DISPLAY_MODE_HORIZONTAL,
	DISPLAY_MODE_VERTICAL,
};

static const char *spriteice[TOTAL_SPRITE] = 
{
	"iconice1.png",
	"iconice2.png",
	"iconice3.png",
	"iconice4.png",
	"iconice5.png",
	"iconice6.png"
};
// 普通的精灵
static const char *spriteNormal[TOTAL_SPRITE] = {
	"icon1.png",
	"icon2.png",
	"icon3.png",
	"icon4.png",
	"icon5.png",
    "icon6.png"
};

// 垂直
static const char *sprVertical[TOTAL_SPRITE] = {
	"icon1_z.png",
	"icon2_z.png",
	"icon3_z.png",
	"icon4_z.png",
	"icon5_z.png",
	"icon6_z.png"
};

// 水平
static const char *sprHorizontal[TOTAL_SPRITE] = {
	"icon1_h.png",
	"icon2_h.png",
	"icon3_h.png",
	"icon4_h.png",
	"icon5_h.png",
	"icon6_h.png"
};
#endif