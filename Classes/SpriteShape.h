#ifndef  _Inkmoo_SpriteShape_h_
#define  _Inkmoo_SpriteShape_h_

#include "cocos2d.h"
#include "GameDefine.h"

USING_NS_CC;

class SpriteShape : public Sprite
{
public:
	SpriteShape();
	static SpriteShape* create( int row , int col );
	void setDisplayMode(DisplayMode mode);
	void setIsfrozen(bool Isfrozen);
	CC_SYNTHESIZE(int, m_row, Row);
    CC_SYNTHESIZE(int, m_col, Col);
    CC_SYNTHESIZE(int, m_imgIndex, ImgIndex);
	CC_SYNTHESIZE(bool, m_isNeedRemove, IsNeedRemove);
	CC_SYNTHESIZE(bool, m_ignoreCheck, IgnoreCheck);
	CC_SYNTHESIZE_READONLY(DisplayMode, m_displayMode, DisplayMode);
private:
	bool IsNeedRemove;
	bool Isfrozen=0;
};


#endif