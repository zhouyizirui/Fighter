//
//  SmallEnemys.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#include "SmallEnemys.h"
#include "ModelPoint.h"
#include "Constants.h"

SmallEnemys::SmallEnemys():
life(1)
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
    ModelPoint *enemyPoint = new ModelPoint(1);
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
        ModelPoint* enemy = (ModelPoint*)smallEnemyArray->objectAtIndex(i);
        enemy->setPoint(enemy->getPointX(), enemy->getPointY()-FRAME_INTERVAL*SMALL_ENEMY_SPEED);
    }
    CCNotificationCenter::sharedNotificationCenter()->postNotification(MOVE_SMALL_ENEMY);
    int removeIndex = detectBorder();
    if(removeIndex>=0) removeEnemy(removeIndex);
}

void SmallEnemys::removeEnemy(int index)
{
    smallEnemyArray->removeObjectAtIndex(index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_SMALL_ENEMY, (CCObject*)&index);
}

int SmallEnemys::detectBorder()
{
    int i=0;
    for(i=0; i<smallEnemyArray->count(); i++)
    {
        ModelPoint* enemy = (ModelPoint*)smallEnemyArray->objectAtIndex(i);
        if(enemy->getPointY()<0) return i;
    }
    return -1;
}

void SmallEnemys::hitPlayer(int index)
{
    CCLOG("In the hit player");
    ModelPoint* enemy = (ModelPoint*)smallEnemyArray->objectAtIndex(index);
    enemy->minusLife();
    if(enemy->getLife()==0)
    {
        smallEnemyArray->removeObjectAtIndex(index);
        
        CCNotificationCenter::sharedNotificationCenter()->postNotification(CRASH_SMALL_ENEMY,(CCObject*)&index);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(SET_SCORE, (CCObject*)SMALL_ENEMY_SCORE);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(PLAY_SMALL_CRASH_EFFECT);
    }
}

void SmallEnemys::hitBullet(int index)
{
    CCLOG("In the hit bullet");
    ModelPoint* enemy = (ModelPoint*)smallEnemyArray->objectAtIndex(index);
    enemy->minusLife();
    if(enemy->getLife()==0)
    {
        smallEnemyArray->removeObjectAtIndex(index);
        
        CCNotificationCenter::sharedNotificationCenter()->postNotification(CRASH_SMALL_ENEMY,(CCObject*)&index);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(SET_SCORE, (CCObject*)SMALL_ENEMY_SCORE);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(PLAY_SMALL_CRASH_EFFECT);
    }
}

void SmallEnemys::onMessage(const string& msg)
{
    
}

void SmallEnemys::update(float dt)
{
    //CCLOG("Update small enemy!");
    moveEnemy();
}