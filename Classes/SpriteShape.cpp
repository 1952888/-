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

// ÉèÖÃ¾«Áé×´Ì¬
void SpriteShape::setDisplayMode(DisplayMode mode)
{
	m_displayMode = mode;

	SpriteFrame *frame;
	switch (mode) {
	case DISPLAY_MODE_VERTICAL:
		frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(sprVertical[m_imgIndex]);
		break;
	case DISPLAY_MODE_HORIZONTAL:
		frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(sprHorizontal[m_imgIndex]);
		break;
	default:
		return;
	}
	setDisplayFrame(frame);
}

void SpriteShape::setIsfrozen(bool Isfrozen)
{
	if (!Isfrozen)return;
	SpriteFrame* frame;
	frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteice[m_imgIndex]);
	setDisplayFrame(frame);
}