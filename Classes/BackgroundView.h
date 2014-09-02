//
//  BackgroundView.h
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#ifndef __Fighter__BackgroundView__
#define __Fighter__BackgroundView__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class BackgroundView: public CCSprite
{
public:
    BackgroundView();
    ~BackgroundView();
    bool init();
    CREATE_FUNC(BackgroundView);
};

#endif /* defined(__Fighter__BackgroundView__) */
