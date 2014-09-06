//
//  BigEnemysView.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/6/14.
//
//

#include "BigEnemysView.h"
#include "Constants.h"
BigEnemysView::BigEnemysView():
enemysArray(NULL)
{
    
}

BigEnemysView::~BigEnemysView()
{
    CC_SAFE_RELEASE(enemysArray);
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool BigEnemysView::init()
{
    enemysArray = CCArray::create();
    enemysArray->retain();
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BigEnemysView::onCreateEnemy), ADD_BIG_ENEMY, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BigEnemysView::onMoveStep), MOVE_BIG_ENEMY, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BigEnemysView::onRemoveEnemy), REMOVE_BIG_ENEMY, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BigEnemysView::onCrashEnemy), CRASH_BIG_ENEMY, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BigEnemysView::onHitten), HIT_BIG_ENEMY, NULL);
    return true;
}

void BigEnemysView::onCreateEnemy(CCObject* setPoint)
{
    CCSprite* sprite = CCSprite::createWithSpriteFrameName("enemy3_n1.png");
    //CCLOG("The small bouding box %f, %f, %f, %f", sprite->boundingBox().getMaxX(), sprite->boundingBox().getMaxY(), sprite->boundingBox().getMinX(), sprite->boundingBox().getMinY());
    enemysArray->addObject(sprite);
    CCPoint startPoint = *(CCPoint*)setPoint;
    sprite->setPosition(startPoint);
    //CCMoveTo* moveTo = CCMoveTo::create(SMALL_ENEMY_SPEED, ccp(startPoint.x, -1));
    //sprite->runAction(moveTo);
    this->addChild(sprite);
}

void BigEnemysView::onMoveStep()
{
    //CCLOG("Move it!");
    //CCLOG("The number of enmey %d", enemysArray->count());
    for(int i=0; i<enemysArray->count(); i++)
    {
        CCSprite* big = (CCSprite*)enemysArray->objectAtIndex(i);
        CCPoint currentPos = big->getPosition();
        big->setPosition(ccp(currentPos.x, currentPos.y-FRAME_INTERVAL*BIG_ENEMY_SPEED));
    }
}

void BigEnemysView::onRemoveEnemy(CCObject* index)
{
    //CCLOG("Remove it!");
    int reIndex = *(int*)index;
    CCSprite* sprite = (CCSprite*)enemysArray->objectAtIndex(reIndex);
    enemysArray->removeObjectAtIndex(reIndex);
    this->removeChild(sprite);
}

//Think about the CCObject pointer index, why to use the local variable pointer
void BigEnemysView::onCrashEnemy(CCObject* index)
{
    int reIndex = *(int*)index;
    CCSprite* sprite = (CCSprite*)enemysArray->objectAtIndex(reIndex);
    CCArray* aniFrames = CCArray::createWithCapacity(BIG_ENEMY_BLOW_COUNT);
    for(int i = 0; i<BIG_ENEMY_BLOW_COUNT; i++)
    {
        char name[30] = {0};
        sprintf(name, "enemy3_down%d.png", i+1);
        CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);
        CC_BREAK_IF(!spriteFrame);
        aniFrames->addObject(spriteFrame);
    }
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(aniFrames, 0.05f);
    CCAnimate* animate = CCAnimate::create(animation);
    CCSequence* sequence = CCSequence::create(animate, CCCallFuncN::create(this, callfuncN_selector(BigEnemysView::remove)), NULL);
    sprite->runAction(sequence);
    enemysArray->removeObjectAtIndex(reIndex);
    //CCDirector::sharedDirector()->pause();
}

void BigEnemysView::onHitten(CCObject* index)
{
    int reIndex = *(int*)index;
    CCSprite* sprite = (CCSprite*)enemysArray->objectAtIndex(reIndex);
    CCArray* aniFrames = CCArray::createWithCapacity(2);
    for(int i=0; i<BIG_ENEMY_HIT_COUNT; i++)
    {
        char name[30] = {0};
        sprintf(name, "enemy3_hit.png");
        CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);
        CC_BREAK_IF(!spriteFrame);
        aniFrames->addObject(spriteFrame);
    }
    CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("enemy3_n1.png");
    aniFrames->addObject(spriteFrame);
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(aniFrames, 0.05f);
    CCAnimate* animate = CCAnimate::create(animation);
    //CCSequence* sequence = CCSequence::create(animate, NULL);
    sprite->runAction(animate);
}

void BigEnemysView::remove(CCNode* node)
{
    if(node!=0) node->removeFromParentAndCleanup(true);
}
