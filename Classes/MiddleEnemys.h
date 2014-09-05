//
//  MiddleEnemys.h
//  Fighter
//
//  Created by zhouyizirui on 9/5/14.
//
//

#ifndef __Fighter__MiddleEnemys__
#define __Fighter__MiddleEnemys__

#include <iostream>
#include "cocos2d.h"
#include "Protocols.h"
#include "Constants.h"
#include "ModelPoint.h"

USING_NS_CC;
using namespace std;

class MiddleEnemys:public CCObject, public Updateable
{
private:
    CCArray* middleEnemyArray;
    int life;
public:
    MiddleEnemys();
    ~MiddleEnemys();
    virtual void update(float dt);
    int detectBorder();
    bool init();
    void moveEnemy();
    void hitBullet(int index);
    void hitPlayer(int index);
    void removeEnemy(int index);
    void createEnemy();
    void onMessage(const string& msg);
    CCArray* getMiddleArray();
};

#endif /* defined(__Fighter__MiddleEnemys__) */
