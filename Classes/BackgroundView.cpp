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
    CCTextureCache::sharedTextureCache()->removeTextureForKey("bomb.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("game_pause_nor.png");
}


bool BackgroundView::init()
{
    if(!CCSprite::init())
    {
        return false;
    }
    CCDirector::sharedDirector()->getScheduler()->scheduleUpdateForTarget(this,0,false);
    CCTextureCache::sharedTextureCache()->addImage("background.png");
    CCTextureCache::sharedTextureCache()->addImage("bomb.png");
    CCTextureCache::sharedTextureCache()->addImage("game_pause_nor.png");
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
    
    bomb = CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("bomb.png"));
    bomb->setPosition(ccp(31, 28));
    bomb->setVisible(false);
    this->addChild(bomb, 0);
    
    bmFont = CCLabelBMFont::create("X0", "font.fnt");
    bmFont->setPosition(ccp(90, 28));
    bmFont->setVisible(false);
    this->addChild(bmFont, 0);
    
    pauseButton = CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("game_pause_nor.png"));
    pauseButton->setPosition(ccp(30, 800-25));
    this->addChild(pauseButton);
    
    
    return true;
}

void BackgroundView::changeBombVisible()
{
    bomb->setVisible(!bomb->isVisible());
    bmFont->setVisible(!bmFont->isVisible());
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