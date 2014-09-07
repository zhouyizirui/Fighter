//
//  Bomb.h
//  Fighter
//
//  Created by zhouyizirui on 9/7/14.
//
//

#ifndef __Fighter__Bomb__
#define __Fighter__Bomb__

#include <iostream>
#include "cocos2d.h"
#include "Protocols.h"
#include "Constants.h"
#include "ModelPoint.h"

USING_NS_CC;

class Bomb:public CCObject, public Updateable
{
private:
    ModelPoint* bomb;
    bool isVisible;
public:
    Bomb();
    ~Bomb();
    virtual void update(float dt);
    bool init();
    void moveBomb();
    void hitPlayer();
    ModelPoint* getBomb();
    bool getIsVisible();
    bool detectBorder();
    void createBomb();
    void removeBomb();
};
#endif /* defined(__Fighter__Bomb__) */
