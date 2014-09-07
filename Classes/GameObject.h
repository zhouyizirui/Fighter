//
//  GameObject.h
//  Fighter
//
//  Created by zhouyizirui on 8/31/14.
//
//

#ifndef __Fighter__GameObject__
#define __Fighter__GameObject__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Protocols.h"
#include "Player.h"
#include "Bullets.h"
#include "SmallEnemys.h"
#include "MiddleEnemys.h"
#include "BigEnemys.h"
#include "Background.h"
#include "Ammo.h"
#include <iostream>
#include <string>

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

class GameObject:public CCObject, public Updateable
{
private:
    Player* player;
    SmallEnemys* smallEnemys;
    MiddleEnemys* middleEnemys;
    BigEnemys* bigEnemys;
    Bullets* bullets;
    Ammo* ammo;
    Background* background;
    bool isOver;
    //int score;
public:
    GameObject();
    Player* getPlayer();
    SmallEnemys* getSmallEnemys();
    MiddleEnemys* getMiddleEnemys();
    BigEnemys* getBigEnemys();
    Bullets* getBullets();
    Ammo* getAmmo();
    Background* getBackground();
    void collisionDetection();
    bool isGameOver();
    void statusRefresh();
    virtual ~GameObject();
    virtual bool init();
    bool isIntersect(CCPoint* aPoint, ModelSize* aSize, CCPoint* bPoint, ModelSize* bSize);
    virtual void update(float dt);
    void onMessage(const string& msg);
};

#endif /* defined(__Fighter__GameObject__) */
