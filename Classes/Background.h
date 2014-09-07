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
    ModelPoint* bombPoint;
    bool isPaused;
    //int totalScore;
    int totalBomb;
public:
    Background();
    ~Background();
    bool getIsPaused();
    bool init();
    void storeBomb();
    void useBomb();
    void setScore(int score);
    int judgePause(CCPoint tapPoint);
    bool judgeUseBomb(CCPoint tapPoint);
};

#endif /* defined(__Fighter__Background__) */
