//
//  EnemyPoint.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/3/14.
//
//

#include "EnemyPoint.h"

EnemyPoint::EnemyPoint()
{
    //this->point
    point = new CCPoint();
}

EnemyPoint::~EnemyPoint()
{
    CC_SAFE_DELETE(point);
}

void EnemyPoint::setPoint(float x, float y)
{
    point->setPoint(x, y);
}

float EnemyPoint::getPointX()
{
    return point->x;
}

float EnemyPoint::getPointY()
{
    return point->y;
}

CCPoint* EnemyPoint::getPoint()
{
    return point;
}