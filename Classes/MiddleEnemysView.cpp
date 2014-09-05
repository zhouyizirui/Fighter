//
//  MiddleEnemysView.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/5/14.
//
//

#include "MiddleEnemysView.h"
#include "Constants.h"
MiddleEnemysView::MiddleEnemysView():
enemysArray(NULL)
{
    
}

MiddleEnemysView::~MiddleEnemysView()
{
    CC_SAFE_RELEASE(enemysArray);
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool MiddleEnemysView::init()
{
    enemysArray = CCArray::create();
    enemysArray->retain();
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(MiddleEnemysView::onCreateEnemy), ADD_MIDDLE_ENEMY, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(MiddleEnemysView::onMoveStep), MOVE_MIDDLE_ENEMY, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(MiddleEnemysView::onRemoveEnemy), REMOVE_MIDDLE_ENEMY, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(MiddleEnemysView::onCrashEnemy), CRASH_MIDDLE_ENEMY, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(MiddleEnemysView::onHitten), HIT_MIDDLE_ENEMY, NULL);
    return true;
}

void MiddleEnemysView::onCreateEnemy(CCObject* setPoint)
{
    CCSprite* sprite = CCSprite::createWithSpriteFrameName("enemy2.png");
    //CCLOG("The small bouding box %f, %f, %f, %f", sprite->boundingBox().getMaxX(), sprite->boundingBox().getMaxY(), sprite->boundingBox().getMinX(), sprite->boundingBox().getMinY());
    enemysArray->addObject(sprite);
    CCPoint startPoint = *(CCPoint*)setPoint;
    sprite->setPosition(startPoint);
    //CCMoveTo* moveTo = CCMoveTo::create(SMALL_ENEMY_SPEED, ccp(startPoint.x, -1));
    //sprite->runAction(moveTo);
    this->addChild(sprite);
}

void MiddleEnemysView::onMoveStep()
{
    //CCLOG("Move it!");
    //CCLOG("The number of enmey %d", enemysArray->count());
    for(int i=0; i<enemysArray->count(); i++)
    {
        CCSprite* middle = (CCSprite*)enemysArray->objectAtIndex(i);
        CCPoint currentPos = middle->getPosition();
        middle->setPosition(ccp(currentPos.x, currentPos.y-FRAME_INTERVAL*MIDDLE_ENEMY_SPEED));
    }
}

void MiddleEnemysView::onRemoveEnemy(CCObject* index)
{
    //CCLOG("Remove it!");
    int reIndex = *(int*)index;
    CCSprite* sprite = (CCSprite*)enemysArray->objectAtIndex(reIndex);
    enemysArray->removeObjectAtIndex(reIndex);
    this->removeChild(sprite);
}

//Think about the CCObject pointer index, why to use the local variable pointer
void MiddleEnemysView::onCrashEnemy(CCObject* index)
{
    int reIndex = *(int*)index;
    CCSprite* sprite = (CCSprite*)enemysArray->objectAtIndex(reIndex);
    CCArray* aniFrames = CCArray::createWithCapacity(2);
    for(int i = 0; i<MIDDLE_ENEMY_BLOW_COUNT; i++)
    {
        char name[30] = {0};
        sprintf(name, "enemy2_down%d.png", i+1);
        CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);
        CC_BREAK_IF(!spriteFrame);
        aniFrames->addObject(spriteFrame);
    }
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(aniFrames, 0.05f);
    CCAnimate* animate = CCAnimate::create(animation);
    CCSequence* sequence = CCSequence::create(animate, CCCallFuncN::create(this, callfuncN_selector(MiddleEnemysView::remove)), NULL);
    sprite->runAction(sequence);
    enemysArray->removeObjectAtIndex(reIndex);
    //CCDirector::sharedDirector()->pause();
}

void MiddleEnemysView::onHitten(CCObject* index)
{
    int reIndex = *(int*)index;
    CCSprite* sprite = (CCSprite*)enemysArray->objectAtIndex(reIndex);
    CCArray* aniFrames = CCArray::createWithCapacity(2);
    for(int i=0; i<MIDDLE_ENEMY_HIT_COUNT; i++)
    {
        char name[30] = {0};
        sprintf(name, "enemy2_hit.png");
        CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);
        CC_BREAK_IF(!spriteFrame);
        aniFrames->addObject(spriteFrame);
    }
    CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("enemy2.png");
    aniFrames->addObject(spriteFrame);
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(aniFrames, 0.05f);
    CCAnimate* animate = CCAnimate::create(animation);
    //CCSequence* sequence = CCSequence::create(animate, NULL);
    sprite->runAction(animate);
}

void MiddleEnemysView::remove(CCNode* node)
{
    //CCLOG("HAHAHAH REMOVE The fucking ");
    if(node!=0) node->removeFromParentAndCleanup(true);
    /*
     int reIndex = *(int*)index;
     CCSprite* sprite = (CCSprite*)enemysArray->objectAtIndex(reIndex);
     enemysArray->removeObjectAtIndex(reIndex);
     this->removeChild(sprite);
     */
}
