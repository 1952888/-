#include"Spriteshapenew.h"

SpriteShape* SpriteShape::create(int row, int col)
{
	SpriteShape* temp = new SpriteShape();
	temp->m_row = row;
	temp->m_col = col;
	temp->m_imgindex = rand() % TOTAL_SPRITE;//采用随机数
	temp->initWithSpriteFrameName(spriteNormal[temp->m_imgindex]);
	temp->autorelease();
	return temp;
}