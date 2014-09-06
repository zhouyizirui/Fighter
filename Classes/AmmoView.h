//
//  AmmoView.h
//  Fighter
//
//  Created by zhouyizirui on 9/6/14.
//
//

#ifndef __Fighter__AmmoView__
#define __Fighter__AmmoView__

#include <iostream>
#include "cocos2d.h"
#include "Constants.h"
USING_NS_CC;

class AmmoView:public CCLayer
{
private:
    CCSprite* ammo;
public:
    AmmoView();
    ~AmmoView();
    bool init();
    void onMoveStep();
    void onRemoveAmmo();
    void onCreateAmmo(CCObject* setPoint);
    CREATE_FUNC(AmmoView);
};

#endif /* defined(__Fighter__AmmoView__) */
