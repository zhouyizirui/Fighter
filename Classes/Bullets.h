//
//  Bullets.h
//  Fighter
//
//  Created by zhouyizirui on 9/4/14.
//
//

#ifndef __Fighter__Bullets__
#define __Fighter__Bullets__

#include <iostream>
#include "cocos2d.h"
#include "Protocols.h"
#include "Constants.h"
#include "ModelPoint.h"

USING_NS_CC;

class Bullets:public CCObject, public Updateable
{
private:
    CCArray* bullets;
    BULLET_TYPE bulletType;
public:
    Bullets();
    ~Bullets();
    virtual void update(float dt);
    int detectBorder();
    bool init();
    void moveBullet();
    void upgradeSuper();
    void hitEnemy(int index);
    void createBullet(CCPoint playerPos);
    void removeBullet(int index);
    CCArray* getBulletArray();
};
#endif /* defined(__Fighter__Bullets__) */
