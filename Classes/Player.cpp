//
//  Player.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/1/14.
//
//

#include "Player.h"
#include "Constants.h"

Player::Player()
:playerState(PLAYER_STABLE),
currentLocation()
{
    
}

Player::~Player()
{
}

void Player::setPosition()
{
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint setPoint = ccp(size.width/2, 100);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(PLANE_SET, (CCObject*)&setPoint);
    currentLocation = setPoint;
    playerState = PLAYER_STABLE;
}

void Player::movePosition(CCPoint destPoint)
{
    if(destPoint.y<80) destPoint.y = 80;
    if(destPoint.x<50) destPoint.x = 50;
    if(destPoint.x>480-50) destPoint.x = 480-50;
    if(destPoint.y>800-50) destPoint.y = 800-50;
    CCNotificationCenter::sharedNotificationCenter()->postNotification(PLANE_MOVE, (CCObject*)&destPoint);
    currentLocation = destPoint;
    playerState = PLAYER_MOVE;
}

void Player::onMessage(const string &msg)
{
    
}

void Player::update(float dt)
{
    
}