//
//  PlayerView.h
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#ifndef __Fighter__PlayerView__
#define __Fighter__PlayerView__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class PlayerView: public CCSprite
{
public:
    PlayerView();
    ~PlayerView();
    bool init();
    void onMoveTo(CCObject* destPoint);
    void onBroken();
    void remove();
    void onSetup(CCObject* setPoint);
    CREATE_FUNC(PlayerView);
};
#endif /* defined(__Fighter__PlayerView__) */
