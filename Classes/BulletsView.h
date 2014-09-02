//
//  BulletsView.h
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#ifndef __Fighter__BulletsView__
#define __Fighter__BulletsView__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class BulletsView:public CCLayer
{
private:
    CCArray* bulletsArray;
public:
    BulletsView();
    ~BulletsView();
    bool init();
    CREATE_FUNC(BulletsView);
};

#endif /* defined(__Fighter__BulletsView__) */
