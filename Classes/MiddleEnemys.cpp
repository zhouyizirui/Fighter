//
//  MiddleEnemys.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/5/14.
//
//

#include "MiddleEnemys.h"
#include "ModelPoint.h"
#include "Constants.h"

MiddleEnemys::MiddleEnemys()
{
    
}

MiddleEnemys::~MiddleEnemys()
{
    CC_SAFE_RELEASE(middleEnemyArray);
}

CCArray* MiddleEnemys::getMiddleArray()
{
    return middleEnemyArray;
}

bool MiddleEnemys::init()
{
    middleEnemyArray = CCArray::create();
    middleEnemyArray->retain();
    return true;
}

void MiddleEnemys::createEnemy()
{
    int xLocation = rand()%380+50;
    int yLocation = 800;
    CCPoint point = ccp(xLocation, yLocation);
    ModelPoint *enemyPoint = new ModelPoint(5);
    enemyPoint->setPoint(point.x, point.y);
    enemyPoint->setSize(MIDDLE_ENEMY_WIDTH, MIDDLE_ENEMY_HEIGHT);
    middleEnemyArray->addObject(enemyPoint);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(ADD_MIDDLE_ENEMY, (CCObject*)&point);
}

void MiddleEnemys::moveEnemy()
{
    //CCLOG("The number of enmey %d", smallEnemyArray->count());
    for(int i=0; i<middleEnemyArray->count(); i++)
    {
        ModelPoint* enemy = (ModelPoint*)middleEnemyArray->objectAtIndex(i);
        enemy->setPoint(enemy->getPointX(), enemy->getPointY()-FRAME_INTERVAL*MIDDLE_ENEMY_SPEED);
    }
    CCNotificationCenter::sharedNotificationCenter()->postNotification(MOVE_MIDDLE_ENEMY);
    int removeIndex = detectBorder();
    if(removeIndex>=0) removeEnemy(removeIndex);
}

void MiddleEnemys::removeEnemy(int index)
{
    middleEnemyArray->removeObjectAtIndex(index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_MIDDLE_ENEMY, (CCObject*)&index);
}

int MiddleEnemys::detectBorder()
{
    int i=0;
    for(i=0; i<middleEnemyArray->count(); i++)
    {
        ModelPoint* enemy = (ModelPoint*)middleEnemyArray->objectAtIndex(i);
        if(enemy->getPointY()<0) return i;
    }
    return -1;
}

void MiddleEnemys::hitPlayer(int index)
{
    CCLOG("In the hit player");
    //ModelPoint* enemy = (ModelPoint*)middleEnemyArray->objectAtIndex(index);
    middleEnemyArray->removeObjectAtIndex(index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(CRASH_MIDDLE_ENEMY,(CCObject*)&index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(SET_SCORE, (CCObject*)MIDDLE_ENEMY_SCORE);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(PLAY_MIDDLE_CRASH_EFFECT);
}

void MiddleEnemys::hitBullet(int index)
{
    CCLOG("In the hit bullet");
    ModelPoint* enemy = (ModelPoint*)middleEnemyArray->objectAtIndex(index);
    enemy->minusLife();
    if(enemy->getLife()==0)
    {
        middleEnemyArray->removeObjectAtIndex(index);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(CRASH_MIDDLE_ENEMY,(CCObject*)&index);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(SET_SCORE, (CCObject*)MIDDLE_ENEMY_SCORE);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(PLAY_MIDDLE_CRASH_EFFECT);
    }
    else
    {
        //CCLOG("INFLJASDJFKLASDJKLGJAKLJFKLJADSLKFJLKADSJFLKJASDLKFJLAJFLJALFJ");
        CCNotificationCenter::sharedNotificationCenter()->postNotification(HIT_MIDDLE_ENEMY, (CCObject*)&index);
    }
}

void MiddleEnemys::onMessage(const string& msg)
{
    
}

void MiddleEnemys::update(float dt)
{
    moveEnemy();
}

