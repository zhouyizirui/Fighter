//
//  Protocols.h
//  Fighter
//
//  Created by zhouyizirui on 8/31/14.
//
//

#ifndef Fighter_Protocols_h
#define Fighter_Protocols_h
#include "cocos2d.h"
USING_NS_CC;

class GameModelDelegate
{
public:
    virtual void changePosition(CCPoint startPoint) = 0;
};
class GameBoardViewDelegate
{
public:
	virtual void dealWithTouchBegan(CCPoint startPoint, int flag) = 0;
};
class GameSceneViewDelegate
{
public:
	virtual void dealWithTouchBegan(CCPoint startPoint) = 0;
    virtual void dealWithTouchMove(CCPoint duraPoint) = 0;
};
class Updateable
{
public:
    virtual void update(float dt) = 0;
};
#endif
