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
    
    setTouchEnabled(true);
    setAccelerometerEnabled(true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    return true;
}

void GameSceneView::makeBackground()
{
    /*
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCSprite* backPicture1 = CCSprite::createWithSpriteFrameName("background.png");
    CCSprite* backPicture2 = CCSprite::createWithSpriteFrameName("background.png");
    backPicture1->setPosition(ccp(size.width/2, size.height/2));
    backPicture2->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(backPicture1, 0);
    this->addChild(backPicture2, 0);
     */
    pBackground = BackgroundView::create();
    this->addChild(pBackground, 0);
}

void GameSceneView::makePlayer()
{
    /*
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    pPlayer = CCSprite::createWithSpriteFrameName("hero1.png");
    pPlayer->setPosition(ccp(size.width/2, 100));
    this->addChild(pPlayer, 1);
    
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
    pPlayer->runAction(CCRepeatForever::create(animate));
     */
    pPlayer = PlayerView::create();
    this->addChild(pPlayer, 1);
}

void GameSceneView::initWithDelegate(GameSceneViewDelegate* delegate)
{
    this->pDelegate = delegate;
    CCLOG("Init the scene delegate");
}
/*
void GameSceneView::initWithPlayer(Player *player)
{
    this->pPlayer = player;
}
 */

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

/*
void GameSceneView::changePosition(CCPoint destPoint)
{
    pPlayer->setPosition(destPoint);
}
*/