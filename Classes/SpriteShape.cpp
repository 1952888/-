	#include "SpriteShape.h"
SpriteShape::SpriteShape()
	: m_col(0)
	, m_row(0)
	, m_imgIndex(0)
	, m_isNeedRemove(false)
{
}

SpriteShape *SpriteShape::create(int row, int col)
{
	SpriteShape *temp = new SpriteShape();
	temp->m_row = row;
	temp->m_col = col;
    temp->m_imgIndex = rand() % TOTAL_SPRITE;
    temp->initWithSpriteFrameName(spriteNormal[temp->m_imgIndex]);
	temp->autorelease();
	return temp;
}