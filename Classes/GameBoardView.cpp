//
//  GameScene.cpp
//  Fighter
//
//  Created by zhouyizirui on 8/31/14.
//
//

#include "GameBoardView.h"
#include "GameBoardController.h"
#include "Constants.h"

bool GameBoardView::init()
{
    if(!CCLayer::init())
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("backgrounds.plist");
    CCSprite* backPicture = CCSprite::createWithSpriteFrameName("background.png");
    CCTextureCache::sharedTextureCache()->addImage("corp.png");
    backPicture->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(backPicture, 0);
    
    CCSprite* titleIcon = CCSprite::createWithSpriteFrameName("shoot_copyright.png");
    titleIcon->setPosition(ccp(size.width/2, size.height/1.3f));
    this->addChild(titleIcon, 1);

    beginSprite = CCSprite::create("begin_game.png");
    beginSprite->setPosition(ccp(size.width/2, size.height/2.5));
    this->addChild(beginSprite);
    
    quitSprite = CCSprite::create("quit_game.png");
    quitSprite->setPosition(ccp(size.width/2, size.height/4));
    this->addChild(quitSprite);
    
    corp = CCSprite::create("corp.png");
    corp->setPosition(ccp(size.width-120, 40));
    corp->setScale(0.5f);
    this->addChild(corp);
    
    CCSprite* loadSprite = CCSprite::create();
    CCArray* aniFrames = CCArray::createWithCapacity(LOAD_ENEMY_COUNT);
    for(int i = 0; i<LOAD_ENEMY_COUNT; i++)
    {
        char name[30] = {0};
        sprintf(name, "game_loading%d.png", i+1);
        CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);
        CC_BREAK_IF(!spriteFrame);
        aniFrames->addObject(spriteFrame);
    }
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(aniFrames, 0.5f);
    CCAnimate* animate = CCAnimate::create(animation);
    loadSprite->setPosition(ccp(size.width/2, size.height/2+20));
    loadSprite->runAction(CCRepeatForever::create(animate));
    this->addChild(loadSprite);
    
    
    setTouchEnabled(true);
    setAccelerometerEnabled(true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    return true;
}

void GameBoardView::initWithDelegate(GameBoardViewDelegate* delegate)
{
    this->pDelegate = delegate;
    CCLOG("Init the board delegate");
}

bool GameBoardView::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLOG("Touch the screen");
    if((beginSprite->boundingBox()).containsPoint(pTouch->getLocation()))
    {
        this->pDelegate->dealWithTouchBegan(pTouch->getLocation(), 1);
    }
    else if((quitSprite->boundingBox()).containsPoint(pTouch->getLocation()))
    {
        this->pDelegate->dealWithTouchBegan(pTouch->getLocation(), -1);
    }
    return true;
}

void GameBoardView::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    
}

void GameBoardView::startGameCallback(CCObject *pSender)
{
    CCLOG("Start the game");
}

void GameBoardView::exitGameCallback(CCObject *pSender)
{
    CCLOG("Exit the game");
}