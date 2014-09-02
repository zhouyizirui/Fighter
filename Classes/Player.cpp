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
    CCNotificationCenter::sharedNotificationCenter()->postNotification(MOVE_POS, (CCObject*)&destPoint);
}

void Player::onMessage(const string &msg)
{
    
}