//
//  Ammo.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/6/14.
//
//

#include "Ammo.h"

Ammo::Ammo()
{

}
Ammo::~Ammo()
{
    CC_SAFE_RELEASE(ammo);
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool Ammo::init()
{
    ammo = new ModelPoint(1);
    ammo->setSize(AMMO_WIDTH, AMMO_HEIGHT);
    isVisible = false;
    return true;
}

void Ammo::update(float dt)
{
    moveAmmo();
}

ModelPoint* Ammo::getAmmo()
{
    return ammo;
}

void Ammo::createAmmo()
{
    CCLOG("Create the ammo");
    int xLocation = rand()%380+50;
    int yLocation = 800;
    CCPoint point = ccp(xLocation, yLocation);
    ammo->setPoint(point.x, point.y);
    isVisible = true;
    CCNotificationCenter::sharedNotificationCenter()->postNotification(ADD_AMMO, (CCObject*)&point);
}

void Ammo::moveAmmo()
{
    if(isVisible)
    {
        ammo->setPoint(ammo->getPointX(), ammo->getPointY()-FRAME_INTERVAL*AMMO_SPEED);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(MOVE_AMMO);
        if(detectBorder()) removeAmmo();
    }
}

void Ammo::removeAmmo()
{
    CCLOG("Remove the ammo");
    isVisible = false;
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_AMMO);
}

bool Ammo::detectBorder()
{
    if(ammo->getPointY()<0) return true;
    return false;
}

void Ammo::hitPlayer()
{
    CCLOG("Ammo hit player");
    isVisible = false;
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_AMMO, (CCObject*)&index);
}

bool Ammo::getIsVisible()
{
    return isVisible;
}