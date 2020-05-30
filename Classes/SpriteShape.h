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
    
	CC_SYNTHESIZE(int, m_row, Row);
    CC_SYNTHESIZE(int, m_col, Col);
    CC_SYNTHESIZE(int, m_imgIndex, ImgIndex);
	CC_SYNTHESIZE(bool, m_isNeedRemove, IsNeedRemove);
private:
	bool IsNeedRemove;
};


#endif