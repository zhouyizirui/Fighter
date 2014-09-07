//
//  BombView.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/7/14.
//
//

#include "BombView.h"
BombView::BombView()
{
    
}

BombView::~BombView()
{
    CC_SAFE_RELEASE(bomb);
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool BombView::init()
{
    bomb = CCSprite::create();
    bomb->retain();
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BombView::onCreateBomb), ADD_BOMB, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BombView::onMoveStep), MOVE_BOMB, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BombView::onRemoveBomb), REMOVE_BOMB, NULL);
    return true;
}

void BombView::onMoveStep()
{
    CCPoint currentPos = bomb->getPosition();
    bomb->setPosition(ccp(currentPos.x, currentPos.y-FRAME_INTERVAL*BOMB_SPEED));
}

void BombView::onRemoveBomb()
{
    this->removeChild(bomb);
}

void BombView::onCreateBomb(CCObject* setPoint)
{
    bomb = CCSprite::createWithSpriteFrameName("ufo2.png");
    bomb->setPosition(*(CCPoint*)setPoint);
    this->addChild(bomb);
}
