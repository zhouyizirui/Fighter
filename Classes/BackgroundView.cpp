//
//  BackgroundView.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#include "BackgroundView.h"
#include "Constants.h"

BackgroundView::BackgroundView()
{
}

BackgroundView::~BackgroundView()
{
    CC_SAFE_RELEASE(batchNode);
    CCTextureCache::sharedTextureCache()->removeTextureForKey("background.png");
}


bool BackgroundView::init()
{
    if(!CCSprite::init())
    {
        return false;
    }
    CCDirector::sharedDirector()->getScheduler()->scheduleUpdateForTarget(this,0,false);
    CCTextureCache::sharedTextureCache()->addImage("background.png");
    batchNode = CCSpriteBatchNode::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("background.png"));
    batchNode->setPosition(CCPointZero);
    this->addChild(batchNode);
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    backPicture1 = CCSprite::createWithTexture(batchNode->getTexture());
    backPicture2 = CCSprite::createWithTexture(batchNode->getTexture());
    CCLOG("The size of the size %f, %f", size.width, size.height);
    backPicture1->setPosition(ccp(240, 852/2));
    backPicture2->setPosition(ccp(240, 852/2));
    batchNode->addChild(backPicture1, 0);
    batchNode->addChild(backPicture2, 0);
    return true;
}

void BackgroundView::update(float delta)
{
    backPicture1->setPositionY(backPicture1->getPositionY()-2);
    backPicture2->setPositionY(backPicture1->getPositionY()+852);
    if(backPicture2->getPositionY()<=852/2)
    {
        backPicture1->setPositionY(852/2);
    }
}