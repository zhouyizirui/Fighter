//
//  Ammo.h
//  Fighter
//
//  Created by zhouyizirui on 9/6/14.
//
//

#ifndef __Fighter__Ammo__
#define __Fighter__Ammo__

#include <iostream>
#include "cocos2d.h"
#include "Protocols.h"
#include "Constants.h"
#include "ModelPoint.h"

USING_NS_CC;

class Ammo:public CCObject, public Updateable
{
private:
    ModelPoint* ammo;
    bool isVisible;
public:
    Ammo();
    ~Ammo();
    virtual void update(float dt);
    bool init();
    void moveAmmo();
    void hitPlayer();
    ModelPoint* getAmmo();
    bool getIsVisible();
    bool detectBorder();
    void createAmmo();
    void removeAmmo();
};
#endif /* defined(__Fighter__Ammo__) */
