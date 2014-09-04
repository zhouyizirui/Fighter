//
//  EnemyPoint.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/3/14.
//
//

#include "ModelPoint.h"

ModelPoint::ModelPoint(int life)
{
    //this->point
    point = new CCPoint();
    size = new ModelSize();
    this->life = life;
}

ModelPoint::~ModelPoint()
{
    CC_SAFE_DELETE(point);
    CC_SAFE_DELETE(size);
}

void ModelPoint::setPoint(float x, float y)
{
    point->setPoint(x, y);
}

void ModelPoint::setSize(float width, float height)
{
    size->setSize(width, height);
}

float ModelPoint::getPointX()
{
    return point->x;
}

float ModelPoint::getPointY()
{
    return point->y;
}

CCPoint* ModelPoint::getPosition()
{
    return point;
}

ModelSize* ModelPoint::getSize()
{
    return size;
}

void ModelPoint::minusLife()
{
    life--;
}

int ModelPoint::getLife()
{
    return life;
}