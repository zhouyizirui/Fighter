//
//  Player.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/1/14.
//
//

#include "Player.h"
#include "Constants.h"

void Player::movePosition(CCPoint destPoint)
{
    if(destPoint.y<80) destPoint.y = 80;
    if(destPoint.x<50) destPoint.x = 50;
    if(destPoint.x>480-50) destPoint.x = 480-50;
    if(destPoint.y>800-50) destPoint.y = 800-50;
    CCNotificationCenter::sharedNotificationCenter()->postNotification(PLANE_MOVE, (CCObject*)&destPoint);
}

void Player::onMessage(const string &msg)
{
    
}

void Player::update(float dt)
{
    
}