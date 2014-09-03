//
//  Size.h
//  Fighter
//
//  Created by zhouyizirui on 9/3/14.
//
//

#ifndef __Fighter__Size__
#define __Fighter__Size__

#include <iostream>
#include "cocos2d.h"
#include "Constants.h"
USING_NS_CC;

class ModelSize:public CCObject
{
private:
    float width;
    float height;
public:
    ModelSize();
    ~ModelSize();
    void setSize(float width, float height);
    float getWidth();
    float getHeight();
};
#endif /* defined(__Fighter__Size__) */
