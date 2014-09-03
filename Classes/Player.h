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
//#include <string>
#include "cocos2d.h"
#include "Protocols.h"
#include "GameObject.h"
USING_NS_CC;
//using namespace std;

class Player:public GameObject
{
public:
    virtual void update(float dt);
    void movePosition(CCPoint destPoint);
    void onMessage(const string& msg);
private:
};

#endif /* defined(__Fighter__Player__) */
