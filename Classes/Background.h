//
//  Background.h
//  Fighter
//
//  Created by zhouyizirui on 9/7/14.
//
//

#ifndef __Fighter__Background__
#define __Fighter__Background__

#include <iostream>
#include "cocos2d.h"
#include "Constants.h"
#include "ModelPoint.h"
USING_NS_CC;

class Background:public CCObject
{
private:
    ModelPoint* pausePoint;
    bool isPaused;
public:
    Background();
    ~Background();
    bool getIsPaused();
    bool init();
    int judgePause(CCPoint tapPoint);
};

#endif /* defined(__Fighter__Background__) */
