//
//  BulletsView.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#include "BulletsView.h"

BulletsView::BulletsView()
{
}

BulletsView::~BulletsView()
{
    CC_SAFE_RELEASE(bulletsArray);
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool BulletsView::init()
{
    bulletsArray = CCArray::create();
    bulletsArray->retain();
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BulletsView::onCreateBullet), ADD_NORMAL_BULLET, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BulletsView::onMoveStep), MOVE_NORMAL_BULLET, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BulletsView::onRemoveEnemy), REMOVE_NORMAL_BULLET, NULL);
    return true;
}

void BulletsView::onCreateBullet(CCObject* setPoint)
{
    CCSprite* sprite = CCSprite::createWithSpriteFrameName("bullet1.png");
    //CCLOG("The small bouding box %f, %f, %f, %f", sprite->boundingBox().getMaxX(), sprite->boundingBox().getMaxY(), sprite->boundingBox().getMinX(), sprite->boundingBox().getMinY());
    bulletsArray->addObject(sprite);
    CCPoint startPoint = *(CCPoint*)setPoint;
    sprite->setPosition(startPoint);
    CCLOG("In the view create function %f, %f", startPoint.x, startPoint.y);
    //CCMoveTo* moveTo = CCMoveTo::create(SMALL_ENEMY_SPEED, ccp(startPoint.x, -1));
    //sprite->runAction(moveTo);
    this->addChild(sprite);
}

void BulletsView::onMoveStep()
{
    for(int i=0; i<bulletsArray->count(); i++)
    {
        CCSprite* bullet = (CCSprite*)bulletsArray->objectAtIndex(i);
        CCPoint currentPos = bullet->getPosition();
        bullet->setPosition(ccp(currentPos.x, currentPos.y+FRAME_INTERVAL*BULLET_SPEED));
    }
}

void BulletsView::onRemoveEnemy(CCObject * index)
{
    int reIndex = *(int*)index;
    CCSprite* sprite = (CCSprite*)bulletsArray->objectAtIndex(reIndex);
    bulletsArray->removeObjectAtIndex(reIndex);
    this->removeChild(sprite);
}