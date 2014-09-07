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
    CC_SAFE_RELEASE(batchNode);
    //CC_SAFE_RELEASE(batchSuperNode);
    CCTextureCache::sharedTextureCache()->removeTextureForKey("bullet1.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("bullet2.png");
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool BulletsView::init()
{
    //CCLOG("In the bullets View");
    CCTextureCache::sharedTextureCache()->addImage("bullet1.png");
    CCTextureCache::sharedTextureCache()->addImage("bullet2.png");
    
    bulletsArray = CCArray::create();
    bulletsArray->retain();
    batchNode = CCSpriteBatchNode::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("bullet1.png"));
    batchNode->retain();
    batchNode->setPosition(CCPointZero);
    this->addChild(batchNode);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BulletsView::onCreateNormalBullet), ADD_NORMAL_BULLET, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BulletsView::onCreateSuperBullet), ADD_SUPER_BULLET, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BulletsView::onMoveStep), MOVE_BULLET, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BulletsView::onRemoveBullet), REMOVE_BULLET, NULL);
    
    return true;
}

void BulletsView::onCreateNormalBullet(CCObject* setPoint)
{
    //CCSprite* sprite = CCSprite::createWithSpriteFrameName("bullet1.png");
    
    batchNode->setTexture(CCTextureCache::sharedTextureCache()->textureForKey("bullet1.png"));
    
    CCSprite* sprite = CCSprite::createWithTexture(batchNode->getTexture());
    
    //CCLOG("The small bouding box %f, %f, %f, %f", sprite->boundingBox().getMaxX(), sprite->boundingBox().getMaxY(), sprite->boundingBox().getMinX(), sprite->boundingBox().getMinY());
    bulletsArray->addObject(sprite);
    CCPoint startPoint = *(CCPoint*)setPoint;
    sprite->setPosition(startPoint);
    //CCLOG("In the view create function %f, %f", startPoint.x, startPoint.y);
    //CCMoveTo* moveTo = CCMoveTo::create(SMALL_ENEMY_SPEED, ccp(startPoint.x, -1));
    //sprite->runAction(moveTo);
    
    //this->addChild(sprite);
    batchNode->addChild(sprite);
}

void BulletsView::onCreateSuperBullet(CCObject* setPoint)
{
    //CCSprite* spriteLeft = CCSprite::createWithSpriteFrameName("bullet2.png");
    //CCSprite* spriteRight = CCSprite::createWithSpriteFrameName("bullet2.png");
    
    batchNode->setTexture(CCTextureCache::sharedTextureCache()->textureForKey("bullet2.png"));
    
    CCSprite* spriteLeft = CCSprite::createWithTexture(batchNode->getTexture());
    CCSprite* spriteRight = CCSprite::createWithTexture(batchNode->getTexture());
    
    //CCLOG("The small bouding box %f, %f, %f, %f", sprite->boundingBox().getMaxX(), sprite->boundingBox().getMaxY(), sprite->boundingBox().getMinX(), sprite->boundingBox().getMinY());
    bulletsArray->addObject(spriteLeft);
    bulletsArray->addObject(spriteRight);
    CCPoint originPoint = *(CCPoint*)setPoint;
    CCPoint leftStartPoint = ccp(originPoint.x-28, originPoint.y+20);
    CCPoint rightStartPoint = ccp(originPoint.x+28, originPoint.y+20);
    spriteLeft->setPosition(leftStartPoint);
    spriteRight->setPosition(rightStartPoint);
    //CCLOG("In the view create function %f, %f", startPoint.x, startPoint.y);
    //CCMoveTo* moveTo = CCMoveTo::create(SMALL_ENEMY_SPEED, ccp(startPoint.x, -1));
    //sprite->runAction(moveTo);
    
    //this->addChild(spriteLeft);
    //this->addChild(spriteRight);
    
    batchNode->addChild(spriteLeft);
    batchNode->addChild(spriteRight);
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

void BulletsView::onRemoveBullet(CCObject * index)
{
    //CCLOG("Remove the bullet");
    int reIndex = *(int*)index;
    CCSprite* sprite = (CCSprite*)bulletsArray->objectAtIndex(reIndex);
    bulletsArray->removeObjectAtIndex(reIndex);
    
    //this->removeChild(sprite);
    batchNode->removeChild(sprite, true);
}