//
//  Bullets.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/4/14.
//
//

#include "Bullets.h"

Bullets::Bullets()
{
    
}

Bullets::~Bullets()
{
    CC_SAFE_RELEASE(bullets);
}

bool Bullets::init()
{
    bullets = CCArray::create();
    bullets->retain();
    bulletType = NORMAL_BULLET;
    return true;
}

void Bullets::createBullet(CCPoint playerPos)
{
    if(bulletType==NORMAL_BULLET)
    {
        CCLOG("The bullet position %f, %f", playerPos.x, playerPos.y+50);
        ModelPoint* bullet = new ModelPoint();
        CCPoint point = ccp(playerPos.x, playerPos.y+50);
        bullet->setPoint(point.x, point.y);
        bullet->setSize(BULLET_WIDTH, BuLLET_HEIGHT);
        bullets->addObject(bullet);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(ADD_NORMAL_BULLET, (CCObject*)&point);
    }
    else
    {
        
    }
}

void Bullets::moveBullet()
{
    //CCLOG("The number of enmey %d", smallEnemyArray->count());
    for(int i=0; i<bullets->count(); i++)
    {
        ModelPoint* bullet = (ModelPoint*)bullets->objectAtIndex(i);
        bullet->setPoint(bullet->getPointX(), bullet->getPointY()-FRAME_INTERVAL*SMALL_ENEMY_SPEED);
    }
    CCNotificationCenter::sharedNotificationCenter()->postNotification(MOVE_NORMAL_BULLET);
    int removeIndex = detectBorder();
    if(removeIndex>=0) removeBullet(removeIndex);
}

int Bullets::detectBorder()
{
    int i=0;
    for(i=0; i<bullets->count(); i++)
    {
        ModelPoint* bullet = (ModelPoint*)bullets->objectAtIndex(i);
        if(bullet->getPointY()>800) return i;
    }
    return -1;
}

void Bullets::removeBullet(int index)
{
    bullets->removeObjectAtIndex(index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_NORMAL_BULLET, (CCObject*)&index);
}

void Bullets::update(float dt)
{
    moveBullet();
}