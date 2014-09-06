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
    CCTextureCache::sharedTextureCache()->removeTextureForKey("background.png");
}

bool BackgroundView::init()
{
    if(!CCSprite::init())
    {
        return false;
    }
    CCTextureCache::sharedTextureCache()->addImage("background.png");
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCSprite* backPicture1 = CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("background.png"));
    //CCSprite* backPicture2 = CCSprite::createWithSpriteFrameName("background.png");
    backPicture1->setPosition(ccp(size.width/2, size.height/2));
    //backPicture2->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(backPicture1, 0);
    //this->addChild(backPicture2, 0);
    //CCLOG("In the background view");
    return true;
}