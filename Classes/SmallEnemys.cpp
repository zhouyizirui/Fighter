//
//  SmallEnemys.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#include "SmallEnemys.h"
#include "Constants.h"

SmallEnemys::SmallEnemys()
{
}

SmallEnemys::~SmallEnemys()
{
    CC_SAFE_RELEASE(smallEnemyArray);
}

bool SmallEnemys::init()
{
    smallEnemyArray = CCArray::create();
    smallEnemyArray->retain();
    return true;
}

void SmallEnemys::createEnemy()
{
    int xLocation = rand()%380+50;
    int yLocation = 800;
    CCPoint point = ccp(xLocation, yLocation);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(ADD_SMALL_ENEMY, (CCObject*)&point);
}

void SmallEnemys::detectBorder()
{
    
}

void SmallEnemys::onMessage(const string& msg)
{
    
}