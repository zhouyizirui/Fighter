//
//  PlayerView.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#include "PlayerView.h"
#include "Constants.h"
PlayerView::PlayerView()
{
}

PlayerView::~PlayerView()
{
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool PlayerView::init()
{
    if(!CCSprite::init())
    {
        return false;
    }
    
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(PlayerView::onSetup), PLANE_SET, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(PlayerView::onMoveTo), PLANE_MOVE, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(PlayerView::onBroken), PLANE_BROKEN, NULL);
    //CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(PlayerView::onBroken), , cocos2d::CCObject *obj)
    return true;
}

void PlayerView::onSetup(CCObject* setPoint)
{
    CCSprite::createWithSpriteFrameName("hero1.png");
    this->setPosition(*(CCPoint*)setPoint);
    //CCLOG("The player bouding box %f, %f, %f, %f", this->boundingBox().getMaxX(), this->boundingBox().getMaxY(), this->boundingBox().getMinX(), this->boundingBox().getMinY());
    CCArray* aniFrames = CCArray::createWithCapacity(2);
    for(int i = 0; i<PLAYER_FRAME_COUNT; i++)
    {
        char name[10] = {0};
        sprintf(name, "hero%d.png", i+1);
        CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);
        CC_BREAK_IF(!spriteFrame);
        aniFrames->addObject(spriteFrame);
    }
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(aniFrames, 0.1f);
    CCAnimate* animate = CCAnimate::create(animation);
    this->runAction(CCRepeatForever::create(animate));
}

void PlayerView::onMoveTo(CCObject* destPoint)
{
    //CCLOG("Receive the move message");
    this->setPosition(*(CCPoint*)destPoint);
}

void PlayerView::onBroken()
{
    this->stopAllActions();
    CCArray* aniFrames = CCArray::createWithCapacity(2);
    for(int i = 0; i<PLAYER_BLOW_COUNT; i++)
    {
        char name[30] = {0};
        sprintf(name, "hero_blowup_n%d.png", i+1);
        CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);
        CC_BREAK_IF(!spriteFrame);
        aniFrames->addObject(spriteFrame);
    }
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(aniFrames, 0.05f);
    CCAnimate* animate = CCAnimate::create(animation);
    CCSequence* sequence = CCSequence::create(animate, CCCallFunc::create(this,callfunc_selector(PlayerView::remove)), NULL);
    this->runAction(sequence);
}

void PlayerView::remove()
{
    CCLog("Remove all children");
    this->removeAllChildren();
    CCDirector::sharedDirector()->pause();
}