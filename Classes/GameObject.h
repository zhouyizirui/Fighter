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
#include "SmallEnemys.h"
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
public:
    GameObject();
    Player* getPlayer();
    SmallEnemys* getSmallEnemys();
    void collisionDetection();
    virtual ~GameObject();
    virtual bool init();
    virtual void update(float dt);
    void onMessage(const string& msg);
};

#endif /* defined(__Fighter__GameObject__) */
