//
//  Player.h
//  Fighter
//
//  Created by zhouyizirui on 9/1/14.
//
//

#ifndef __Fighter__Player__
#define __Fighter__Player__

#include <iostream>
#include <string>
#include "cocos2d.h"
#include "Protocols.h"
#include "Constants.h"

USING_NS_CC;
using namespace std;

class Player:public CCObject, public Updateable
{
public:
    Player();
    ~Player();
    virtual void update(float dt);
    void setPosition();
    void movePosition(CCPoint destPoint);
    void onMessage(const string& msg);
private:
    CCPoint currentLocation;
    PLAYER_STATE playerState;
};

#endif /* defined(__Fighter__Player__) */
