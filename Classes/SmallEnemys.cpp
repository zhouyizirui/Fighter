//
//  SmallEnemys.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#include "SmallEnemys.h"
#include "EnemyPoint.h"
#include "Constants.h"

SmallEnemys::SmallEnemys()
{
    
}

SmallEnemys::~SmallEnemys()
{
    CC_SAFE_RELEASE(smallEnemyArray);
}

CCArray* SmallEnemys::getSmallArray()
{
    return smallEnemyArray;
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
    EnemyPoint *enemyPoint = new EnemyPoint();
    enemyPoint->setPoint(point.x, point.y);
    enemyPoint->setSize(SMALL_ENEMY_WIDTH, SMALL_ENEMY_HEIGHT);
    smallEnemyArray->addObject(enemyPoint);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(ADD_SMALL_ENEMY, (CCObject*)&point);
}

void SmallEnemys::moveEnemy()
{
    //CCLOG("The number of enmey %d", smallEnemyArray->count());
    for(int i=0; i<smallEnemyArray->count(); i++)
    {
        EnemyPoint* enemy = (EnemyPoint*)smallEnemyArray->objectAtIndex(i);
        enemy->setPoint(enemy->getPointX(), enemy->getPointY()-FRAME_INTERVAL*SMALL_ENEMY_SPEED);
    }
    CCNotificationCenter::sharedNotificationCenter()->postNotification(SMALL_ENEMY_MOVE);
    int removeIndex = detectBorder();
    if(removeIndex>=0) removeEnemy(removeIndex);
}

void SmallEnemys::removeEnemy(int index)
{
    smallEnemyArray->removeObjectAtIndex(index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_ENEMY, (CCObject*)&index);
}

int SmallEnemys::detectBorder()
{
    int i=0;
    for(i=0; i<smallEnemyArray->count(); i++)
    {
        EnemyPoint* enemy = (EnemyPoint*)smallEnemyArray->objectAtIndex(i);
        if(enemy->getPointY()<0) return i;
    }
    return -1;
}

void SmallEnemys::hitPlayer(int index)
{
    CCLOG("In the hit player");
    smallEnemyArray->removeObjectAtIndex(index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(CRASH_ENEMY,(CCObject*)&index);
}

void SmallEnemys::onMessage(const string& msg)
{
    
}

void SmallEnemys::update(float dt)
{
    //CCLOG("Update small enemy!");
    moveEnemy();
}