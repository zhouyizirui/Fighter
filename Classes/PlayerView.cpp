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
}

bool PlayerView::init()
{
    if(!CCSprite::init())
    {
        return false;
    }
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCSprite::createWithSpriteFrameName("hero1.png");
    this->setPosition(ccp(size.width/2, 100));
    //this->addChild(pPlayer, 1);
    
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
    return true;
}

void PlayerView::onMoveTo(CCPoint destPoint)
{
    this->setPosition(destPoint);
}