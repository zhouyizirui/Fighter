//
//  AmmoView.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/6/14.
//
//

#include "AmmoView.h"

AmmoView::AmmoView()
{
    
}

AmmoView::~AmmoView()
{
    CC_SAFE_RELEASE(ammo);
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool AmmoView::init()
{
    ammo = CCSprite::create();
    ammo->retain();
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(AmmoView::onCreateAmmo), ADD_AMMO, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(AmmoView::onMoveStep), MOVE_AMMO, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(AmmoView::onRemoveAmmo), REMOVE_AMMO, NULL);
    return true;
}

void AmmoView::onMoveStep()
{
    CCPoint currentPos = ammo->getPosition();
    ammo->setPosition(ccp(currentPos.x, currentPos.y-FRAME_INTERVAL*AMMO_SPEED));
}

void AmmoView::onRemoveAmmo()
{
    this->removeChild(ammo);
}

void AmmoView::onCreateAmmo(CCObject* setPoint)
{
    ammo = CCSprite::createWithSpriteFrameName("ufo1.png");
    ammo->setPosition(*(CCPoint*)setPoint);
    this->addChild(ammo);
}

