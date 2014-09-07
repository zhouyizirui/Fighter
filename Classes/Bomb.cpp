//
//  Bomb.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/7/14.
//
//

#include "Bomb.h"

Bomb::Bomb()
{
    
}
Bomb::~Bomb()
{
    CC_SAFE_RELEASE(bomb);
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool Bomb::init()
{
    bomb = new ModelPoint(1);
    bomb->setSize(BOMB_WIDTH, BOMB_HEIGHT);
    isVisible = false;
    return true;
}

void Bomb::update(float dt)
{
    moveBomb();
}

ModelPoint* Bomb::getBomb()
{
    return bomb;
}

void Bomb::createBomb()
{
    CCLOG("Create the Bomb");
    int xLocation = rand()%380+50;
    int yLocation = 800;
    CCPoint point = ccp(xLocation, yLocation);
    bomb->setPoint(point.x, point.y);
    isVisible = true;
    CCNotificationCenter::sharedNotificationCenter()->postNotification(ADD_BOMB, (CCObject*)&point);
}

void Bomb::moveBomb()
{
    if(isVisible)
    {
        bomb->setPoint(bomb->getPointX(), bomb->getPointY()-FRAME_INTERVAL*BOMB_SPEED);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(MOVE_BOMB);
        if(detectBorder()) removeBomb();
    }
}

void Bomb::removeBomb()
{
    CCLOG("Remove the Bomb");
    isVisible = false;
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_BOMB);
}

bool Bomb::detectBorder()
{
    if(bomb->getPointY()<0) return true;
    return false;
}

void Bomb::hitPlayer()
{
    CCLOG("Bomb hit player");
    isVisible = false;
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_BOMB, (CCObject*)&index);
    //CCNotificationCenter::sharedNotificationCenter()->postNotification(STORE_BOMB);
}

bool Bomb::getIsVisible()
{
    return isVisible;
}