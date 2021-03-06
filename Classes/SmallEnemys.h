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
#include "Constants.h"
#include "ModelPoint.h"

USING_NS_CC;
using namespace std;

class SmallEnemys:public CCObject, public Updateable
{
private:
    CCArray* smallEnemyArray;
    int life;
public:
    SmallEnemys();
    ~SmallEnemys();
    virtual void update(float dt);
    int detectBorder();
    bool init();
    void moveEnemy();
    void hitBullet(int index);
    void hitPlayer(int index);
    void removeEnemy(int index);
    void createEnemy();
    void onMessage(const string& msg);
    CCArray* getSmallArray();
};

#endif /* defined(__Fighter__SmallEnemys__) */
