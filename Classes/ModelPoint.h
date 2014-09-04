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
#include "ModelSize.h"
USING_NS_CC;

class ModelPoint:public CCObject
{
private:
    CCPoint* point;
    ModelSize* size;
public:
    ModelPoint();
    ~ModelPoint();
    float getPointX();
    float getPointY();
    CCPoint* getPosition();
    ModelSize* getSize();
    void setPoint(float x, float y);
    void setSize(float width, float height);
};

#endif /* defined(__Fighter__EnemyPoint__) */
