//
//  SmallEnemys.h
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#ifndef __Fighter__SmallEnemys__
#define __Fighter__SmallEnemys__

#include <iostream>
#include "cocos2d.h"
#include "Protocols.h"
#include "GameObject.h"
USING_NS_CC;

class SmallEnemys:public CCObject
{
private:
    CCArray* smallEnemyArray;
public:
    SmallEnemys();
    ~SmallEnemys();
    void detectBorder();
    bool init();
    void createEnemy();
    void onMessage(const string& msg);
};

#endif /* defined(__Fighter__SmallEnemys__) */
