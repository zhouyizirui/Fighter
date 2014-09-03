//
//  EnemyPoint.h
//  Fighter
//
//  Created by zhouyizirui on 9/3/14.
//
//

#ifndef __Fighter__EnemyPoint__
#define __Fighter__EnemyPoint__

#include <iostream>
#include "cocos2d.h"
#include "Constants.h"
USING_NS_CC;

class EnemyPoint:public CCObject
{
private:
    CCPoint* point;
public:
    EnemyPoint();
    ~EnemyPoint();
    float getPointX();
    float getPointY();
    CCPoint* getPoint();
    void setPoint(float x, float y);
};

#endif /* defined(__Fighter__EnemyPoint__) */
