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
    //totalScore = 0;
    //totalBomb = 0;
}

BackgroundView::~BackgroundView()
{
    /*
    CC_SAFE_RELEASE(batchNode);
    CC_SAFE_RELEASE(bomb);
    CC_SAFE_RELEASE(bmFont);
    CC_SAFE_RELEASE(scores);
     */
    CCTextureCache::sharedTextureCache()->removeTextureForKey("background.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("bomb.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("game_pause_nor.png");

    
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this); //Remove observers
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
    
    scores = CCLabelBMFont::create("0", "font.fnt");
    scores->setPosition(ccp(160, 800-25));
    this->addChild(scores);
    

    
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BackgroundView::onSetScore), SET_SCORE, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BackgroundView::onStoreBomb), STORE_BOMB, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BackgroundView::onUseBomb), USE_BOMB, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BackgroundView::changeBombVisible), CHANGE_BOMB_VISIBLE, NULL);
    return true;
}

void BackgroundView::changeBombVisible()
{
    bomb->setVisible(!bomb->isVisible());
    bmFont->setVisible(!bmFont->isVisible());
}

void BackgroundView::onSetScore(CCObject* score)
{
    int addScore = (int)score;
    int currentScore = atoi(scores->getString());
    int totalScore = addScore+currentScore;
    char newScore[10];
    sprintf(newScore, "%d", totalScore);
    scores->setString(newScore);
}

void BackgroundView::onStoreBomb(CCObject* bomb)
{
    int totalBomb = *(int*)bomb;
    char newBombs[10];
    sprintf(newBombs, "X%d", totalBomb);
    bmFont->setString(newBombs);
}

void BackgroundView::onUseBomb(CCObject* bomb)
{
    int totalBomb = *(int*)bomb;
    char newBombs[10];
    sprintf(newBombs, "X%d", totalBomb);
    bmFont->setString(newBombs);
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