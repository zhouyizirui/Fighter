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
:playerState(PLAYER_STABLE)
{
    playerSize = new ModelSize();
    currentLocation = new CCPoint();
}

Player::~Player()
{
    CC_SAFE_DELETE(currentLocation);
    CC_SAFE_DELETE(playerSize);
}

ModelSize* Player::getSize()
{
    return playerSize;
}

void Player::setPosition()
{
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint setupPoint = ccp(size.width/2, 100);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(PLANE_SET, (CCObject*)&setupPoint);
    
    currentLocation->setPoint(setupPoint.x, setupPoint.y);
    playerSize->setSize(PLAYER_WIDTH, PLAYER_HEIGHT);
    playerState = PLAYER_STABLE;
}

CCPoint* Player::getPosition()
{
    return currentLocation;
}

void Player::movePosition(CCPoint destPoint)
{
    if(destPoint.y<80) destPoint.y = 80;
    if(destPoint.x<50) destPoint.x = 50;
    if(destPoint.x>480-50) destPoint.x = 480-50;
    if(destPoint.y>800-50) destPoint.y = 800-50;
    CCNotificationCenter::sharedNotificationCenter()->postNotification(PLANE_MOVE, (CCObject*)&destPoint);
    currentLocation->setPoint(destPoint.x, destPoint.y);
    playerState = PLAYER_MOVE;
}

void Player::hitEnemy()
{
    CCLOG("In the hit enemy");
    CCNotificationCenter::sharedNotificationCenter()->postNotification(PLANE_BROKEN);
    playerState = PLAYER_CRASH;
}

void Player::onMessage(const string &msg)
{
    
}

void Player::update(float dt)
{
    
}