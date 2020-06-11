#ifndef  _Inkmoo_Elimination_h_
#define  _Inkmoo_Elimination_h_

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



// �������ʾģʽ��Hor ��������һ�У�Ver��������һ��
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
// ��ͨ�ľ���
static const char *spriteNormal[TOTAL_SPRITE] = {
	"icon1.png",
	"icon2.png",
	"icon3.png",
	"icon4.png",
	"icon5.png",
    "icon6.png"
};

// ��ֱ
static const char *sprVertical[TOTAL_SPRITE] = {
	"icon1_z.png",
	"icon2_z.png",
	"icon3_z.png",
	"icon4_z.png",
	"icon5_z.png",
	"icon6_z.png"
};

// ˮƽ
static const char *sprHorizontal[TOTAL_SPRITE] = {
	"icon1_h.png",
	"icon2_h.png",
	"icon3_h.png",
	"icon4_h.png",
	"icon5_h.png",
	"icon6_h.png"
};
#endif