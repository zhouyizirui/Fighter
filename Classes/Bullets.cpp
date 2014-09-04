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

CCArray* Bullets::getBulletArray()
{
    return bullets;
}

void Bullets::createBullet(CCPoint playerPos)
{
    if(bulletType==NORMAL_BULLET)
    {
        //CCLOG("The bullet position %f, %f", playerPos.x, playerPos.y+50);
        ModelPoint* bullet = new ModelPoint(1);
        CCPoint point = ccp(playerPos.x, playerPos.y+50);
        bullet->setPoint(point.x, point.y);
        bullet->setSize(BULLET_WIDTH, BULLET_HEIGHT);
        bullets->addObject(bullet);
        CCLOG("The number of bullets in createBullet %d", bullets->count());
        CCNotificationCenter::sharedNotificationCenter()->postNotification(ADD_NORMAL_BULLET, (CCObject*)&point);
    }
    else
    {
        
    }
}

void Bullets::moveBullet()
{
    //CCLOG("The number of bullets in moveBullet %d", bullets->count());
    for(int i=0; i<bullets->count(); i++)
    {
        ModelPoint* bullet = (ModelPoint*)bullets->objectAtIndex(i);
        bullet->setPoint(bullet->getPointX(), bullet->getPointY()+FRAME_INTERVAL*BULLET_SPEED);
    }
    CCNotificationCenter::sharedNotificationCenter()->postNotification(MOVE_NORMAL_BULLET);
    int removeIndex = detectBorder();
    if(removeIndex>=0) removeBullet(removeIndex);
}

int Bullets::detectBorder()
{
    int i=0;
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    //CCLOG("The number of bullets in detectBorder %d", bullets->count());
    for(i=0; i<bullets->count(); i++)
    {
        ModelPoint* bullet = (ModelPoint*)bullets->objectAtIndex(i);
        if(bullet->getPointY()>size.height)
        {
            CCLOG("The size of the height %f", size.height);
            CCLOG("Bullet exceeds the border");
            return i;
        }
    }
    return -1;
}

void Bullets::removeBullet(int index)
{
    bullets->removeObjectAtIndex(index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_NORMAL_BULLET, (CCObject*)&index);
}

void Bullets::hitEnemy(int index)
{
    ModelPoint* bullet = (ModelPoint*)bullets->objectAtIndex(index);
    bullet->minusLife();
    if(bullet->getLife()==0)
    {
    bullets->removeObjectAtIndex(index);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_NORMAL_BULLET, (CCObject*)&index);
    }
}

void Bullets::update(float dt)
{
    moveBullet();
}