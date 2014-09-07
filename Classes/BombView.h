//
//  BombView.h
//  Fighter
//
//  Created by zhouyizirui on 9/7/14.
//
//

#ifndef __Fighter__BombView__
#define __Fighter__BombView__

#include <iostream>
#include "cocos2d.h"
#include "Constants.h"
USING_NS_CC;

class BombView:public CCLayer
{
private:
    CCSprite* bomb;
public:
    BombView();
    ~BombView();
    bool init();
    void onMoveStep();
    void onRemoveBomb();
    void onCreateBomb(CCObject* setPoint);
    CREATE_FUNC(BombView);
};
#endif /* defined(__Fighter__BombView__) */
