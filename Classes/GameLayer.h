//
//  GameLayer.h
//  Fighter
//
//  Created by zhouyizirui on 8/31/14.
//
//

#ifndef __Fighter__GameLayer__
#define __Fighter__GameLayer__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
#include <iostream>

USING_NS_CC;
USING_NS_CC_EXT;

class GameLayer:public CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(GameLayer);
};
#endif /* defined(__Fighter__GameLayer__) */
