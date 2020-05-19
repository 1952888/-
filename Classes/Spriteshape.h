#ifndef Spriteshapenew.h
#define Spriteshapenew.h

#include"cocos2d.h"
#include"GameDefine.h"

USING_NS_CC;

class SpriteShape:public Sprite
{
public:
	static SpriteShape* create(int row, int col);
	CC_SYNTHESIZE(int, m_col, Col);
	CC_SYNTHESIZE(int, m_row, Row);
	CC_SYNTHESIZE(int, m_imgindex, Imgindex);
};

static const char *spriteNormal[TOTAL_SPRITE] =
{
	"icon(1).png",
	"icon(2).png",
	"icon(3).png",
	"icon(4).png",
	"icon(5).png",
	"icon(6).png"
};
#endif // !SpriteShape.h
#pragma once
