//
//  BigEnemys.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/6/14.
//
//

#include "BigEnemys.h"
#include "ModelPoint.h"
#include "Constants.h"

BigEnemys::BigEnemys()
{
    
}

BigEnemys::~BigEnemys()
{
    CC_SAFE_RELEASE(bigEnemyArray);
}

CCArray* BigEnemys::getBigArray()
{
    return bigEnemyArray;
}

bool BigEnemys::init()
{
    bigEnemyArray = CCArray::create();
    bigEnemyArray->retain();
    return true;
}

void BigEnemys::createEnemy()
{
    int xLocation = rand()%380+50;
    int yLocation = 850;
    CCPoint point = ccp(xLocation, yLocation);
    ModelPoint *enemyPoint = new ModelPoint(30);
    enemyPoint->setPoint(point.x, point.y);
    enemyPoint->setSize(BIG_ENEMY_WIDTH, BIG_ENEMY_HEIGHT);
    bigEnemyArray->addObject(enemyPoint);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(ADD_BIG_ENEMY, (CCObject*)&point);
}

void BigEnemys::moveEnemy()
{
    //CCLOG("The number of enmey %d", smallEnemyArray->count());
    for(int i=0; i<bigEnemyArray->count(); i++)
    {
        ModelPoint* enemy = (ModelPoint*)bigEnemyArray->objectAtIndex(i);
        enemy->setPoint(enemy->getPointX(), enemy->getPointY()-FRAME_INTERVAL*BIG_ENEMY_SPEED);
    }
    CCNotificationCenter::sharedNotificationCenter()->postNotification(MOVE_BIG_ENEMY);
    int removeIndex = detectBorder();
    if(removeIndex>=0) removeEnemy(removeIndex);
}

void BigEnemys::removeEnemy(int index)
{
    bigEnemyArray->removeObjectAtIndex(index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_BIG_ENEMY, (CCObject*)&index);
}

int BigEnemys::detectBorder()
{
    int i=0;
    for(i=0; i<bigEnemyArray->count(); i++)
    {
        ModelPoint* enemy = (ModelPoint*)bigEnemyArray->objectAtIndex(i);
        if(enemy->getPointY()<0) return i;
    }
    return -1;
}

void BigEnemys::hitPlayer(int index)
{
    CCLOG("In the hit player");
    //ModelPoint* enemy = (ModelPoint*)middleEnemyArray->objectAtIndex(index);
    bigEnemyArray->removeObjectAtIndex(index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(CRASH_BIG_ENEMY,(CCObject*)&index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(SET_SCORE, (CCObject*)BIG_ENEMY_SCORE);
}

void BigEnemys::hitBullet(int index)
{
    CCLOG("In the hit bullet");
    ModelPoint* enemy = (ModelPoint*)bigEnemyArray->objectAtIndex(index);
    enemy->minusLife();
    if(enemy->getLife()==0)
    {
        bigEnemyArray->removeObjectAtIndex(index);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(CRASH_BIG_ENEMY,(CCObject*)&index);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(SET_SCORE, (CCObject*)BIG_ENEMY_SCORE);
    }
    else
    {
        //CCLOG("INFLJASDJFKLASDJKLGJAKLJFKLJADSLKFJLKADSJFLKJASDLKFJLAJFLJALFJ");
        CCNotificationCenter::sharedNotificationCenter()->postNotification(HIT_BIG_ENEMY, (CCObject*)&index);
    }
}

void BigEnemys::onMessage(const string& msg)
{
    
}

void BigEnemys::update(float dt)
{
    moveEnemy();
}

