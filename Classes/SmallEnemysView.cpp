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
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(SmallEnemysView::onMoveStep), SMALL_ENEMY_MOVE, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(SmallEnemysView::onRemoveEnemy), REMOVE_ENEMY, NULL);
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

void SmallEnemysView::onMoveStep()
{
    //CCLOG("Move it!");
    //CCLOG("The number of enmey %d", enemysArray->count());
    for(int i=0; i<enemysArray->count(); i++)
    {
        CCSprite* small = (CCSprite*)enemysArray->objectAtIndex(i);
        CCPoint currentPos = small->getPosition();
        small->setPosition(ccp(currentPos.x, currentPos.y-FRAME_INTERVAL*SMALL_ENEMY_SPEED));
    }
}

void SmallEnemysView::onRemoveEnemy(CCObject* index)
{
    CCLOG("Remove it!");
    int reIndex = *(int*)index;
    CCSprite* sprite = (CCSprite*)enemysArray->objectAtIndex(reIndex);
    enemysArray->removeObjectAtIndex(reIndex);
    this->removeChild(sprite);
}
