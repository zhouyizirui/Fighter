//
//  Size.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/3/14.
//
//

#include "ModelSize.h"

ModelSize::ModelSize()
{
}

ModelSize::~ModelSize()
{
}

void ModelSize::setSize(float width, float height)
{
    this->width = width;
    this->height = height;
}

float ModelSize::getHeight()
{
    return height;
}

float ModelSize::getWidth()
{
    return width;
}