//
//  BigEnemys.h
//  Fighter
//
//  Created by zhouyizirui on 9/6/14.
//
//

#ifndef __Fighter__BigEnemys__
#define __Fighter__BigEnemys__

#include <iostream>
#include "cocos2d.h"
#include "Protocols.h"
#include "Constants.h"
#include "ModelPoint.h"

USING_NS_CC;
using namespace std;

class BigEnemys:public CCObject, public Updateable
{
private:
    CCArray* bigEnemyArray;
public:
    BigEnemys();
    ~BigEnemys();
    virtual void update(float dt);
    int detectBorder();
    bool init();
    void moveEnemy();
    void hitBullet(int index);
    void hitPlayer(int index);
    void removeEnemy(int index);
    void createEnemy();
    void onMessage(const string& msg);
    CCArray* getBigArray();
};

#endif /* defined(__Fighter__BigEnemys__) */
