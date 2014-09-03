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
    size = new ModelSize();
}

EnemyPoint::~EnemyPoint()
{
    CC_SAFE_DELETE(point);
    CC_SAFE_DELETE(size);
}

void EnemyPoint::setPoint(float x, float y)
{
    point->setPoint(x, y);
}

void EnemyPoint::setSize(float width, float height)
{
    size->setSize(width, height);
}

float EnemyPoint::getPointX()
{
    return point->x;
}

float EnemyPoint::getPointY()
{
    return point->y;
}

CCPoint* EnemyPoint::getPosition()
{
    return point;
}

ModelSize* EnemyPoint::getSize()
{
    return size;
}