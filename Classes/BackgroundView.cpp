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
    
}

bool BackgroundView::init()
{
    if(!CCSprite::init())
    {
        return false;
    }
    //CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    //CCSprite* backPicture1 = CCSprite::createWithSpriteFrameName("background.png");
    //CCSprite* backPicture2 = CCSprite::createWithSpriteFrameName("background.png");
    //backPicture1->setPosition(ccp(size.width/2, size.height/2));
    //backPicture2->setPosition(ccp(size.width/2, size.height/2));
    //this->addChild(backPicture1, 0);
    //this->addChild(backPicture2, 0);
    CCLOG("In the background view");
    return true;
}