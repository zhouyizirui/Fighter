//
//  GameSceneView.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/1/14.
//
//

#include "GameSceneView.h"
#include "Constants.h"

bool GameSceneView::init()
{
    if(!CCLayer::init())
    {
        return false;
    }
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("backgrounds.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("elements.plist");
    
    makePlayer();
    makeBackground();
    makeSmallEnemys();
    makeBullets();
    
    setTouchEnabled(true);
    setAccelerometerEnabled(true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    return true;
}

void GameSceneView::makeBackground()
{
    pBackground = BackgroundView::create();
    this->addChild(pBackground, 0);
}

void GameSceneView::makePlayer()
{
    pPlayer = PlayerView::create();
    this->addChild(pPlayer, 1);
}

void GameSceneView::makeSmallEnemys()
{
    pSmallEnemys = SmallEnemysView::create();
    this->addChild(pSmallEnemys, 1);
}

void GameSceneView::makeBullets()
{
    pBullets = BulletsView::create();
    this->addChild(pBullets, 1);
}

void GameSceneView::initWithDelegate(GameSceneViewDelegate* delegate)
{
    this->pDelegate = delegate;
    CCLOG("Init the scene delegate");
}

bool GameSceneView::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLOG("Scene touch the screen");
    return true;
}

void GameSceneView::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLOG("Scene move the screen");
    CCPoint delta = pTouch->getDelta();
    CCPoint newPosition = ccp(pPlayer->getPosition().x+delta.x, pPlayer->getPosition().y+delta.y);
    this->pDelegate->dealWithTouchMove(newPosition);
}