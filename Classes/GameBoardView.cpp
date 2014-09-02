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
    backPicture->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(backPicture, 0);
    
    CCSprite* titleIcon = CCSprite::createWithSpriteFrameName("shoot_copyright.png");
    titleIcon->setPosition(ccp(size.width/2, size.height/1.4f));
    this->addChild(titleIcon, 1);
    /*
    CCLabelTTF* startLabel = CCLabelTTF::create(S_START, "thonburi", 36);
    CCMenuItemLabel* startItem = CCMenuItemLabel::create(startLabel, this, menu_selector(GameBoardView::startGameCallback));
    startItem->setPosition(ccp(0, 50));
    CCLabelTTF* exitLabel = CCLabelTTF::create(S_EXIT, "Marker Felt", 36);
    CCMenuItemLabel * exitItem = CCMenuItemLabel::create(exitLabel, this, menu_selector(GameBoardView::exitGameCallback));
    exitItem->setPosition(ccp(0, -50));
    CCMenu* menu = CCMenu::create(startItem, exitItem, NULL);
    menu->setPosition(ccp(size.width/2, size.height/2.5));
    this->addChild(menu, 0);
     */
    beginSprite = CCSprite::create("begin_game.png");
    beginSprite->setPosition(ccp(size.width/2, size.height/2.2));
    this->addChild(beginSprite);
    
    quitSprite = CCSprite::create("quit_game.png");
    quitSprite->setPosition(ccp(size.width/2, size.height/3.2));
    this->addChild(quitSprite);
    
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
    //CCPoint location = CCDirector::sharedDirector()->convertToGL(pTouch->getLocation());
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