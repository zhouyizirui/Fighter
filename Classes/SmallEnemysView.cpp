//
//  SmallEnemysView.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#include "SmallEnemysView.h"
#include "Constants.h"

SmallEnemysView::SmallEnemysView()
{

}

SmallEnemysView::~SmallEnemysView()
{
    CC_SAFE_RELEASE(enemysArray);
}

bool SmallEnemysView::init()
{
    enemysArray = CCArray::create();
    enemysArray->retain();
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(SmallEnemysView::onCreateEnemy), ADD_SMALL_ENEMY, NULL);
    return true;
}

void SmallEnemysView::onCreateEnemy(CCObject* setPoint)
{
    CCSprite* sprite = CCSprite::createWithSpriteFrameName("enemy1.png");
    enemysArray->addObject(sprite);
    CCPoint startPoint = *(CCPoint*)setPoint;
    sprite->setPosition(startPoint);
    CCMoveTo* moveTo = CCMoveTo::create(SMALL_ENEMY_SPEED, ccp(startPoint.x, -1));
    sprite->runAction(moveTo);
    this->addChild(sprite);
}
