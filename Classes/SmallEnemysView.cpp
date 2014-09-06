//
//  SmallEnemysView.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#include "SmallEnemysView.h"
#include "Constants.h"

SmallEnemysView::SmallEnemysView():
enemysArray(NULL)
{

}

SmallEnemysView::~SmallEnemysView()
{
    CC_SAFE_RELEASE(enemysArray);
    CC_SAFE_RELEASE(batchNode);
    CCTextureCache::sharedTextureCache()->removeTextureForKey("enemy1.png");
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool SmallEnemysView::init()
{
    CCTextureCache::sharedTextureCache()->addImage("enemy1.png");
    batchNode = CCSpriteBatchNode::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("enemy1.png"));
    batchNode->setPosition(CCPointZero);
    batchNode->retain();
    this->addChild(batchNode);
    
    enemysArray = CCArray::create();
    enemysArray->retain();
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(SmallEnemysView::onCreateEnemy), ADD_SMALL_ENEMY, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(SmallEnemysView::onMoveStep), MOVE_SMALL_ENEMY, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(SmallEnemysView::onRemoveEnemy), REMOVE_SMALL_ENEMY, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(SmallEnemysView::onCrashEnemy), CRASH_SMALL_ENEMY, NULL);
    return true;
}

void SmallEnemysView::onCreateEnemy(CCObject* setPoint)
{
    //CCSprite* sprite = CCSprite::createWithSpriteFrameName("enemy1.png");
    CCSprite* sprite = CCSprite::createWithTexture(batchNode->getTexture());
    //CCLOG("The small bouding box %f, %f, %f, %f", sprite->boundingBox().getMaxX(), sprite->boundingBox().getMaxY(), sprite->boundingBox().getMinX(), sprite->boundingBox().getMinY());
    enemysArray->addObject(sprite);
    CCPoint startPoint = *(CCPoint*)setPoint;
    sprite->setPosition(startPoint);
    //CCMoveTo* moveTo = CCMoveTo::create(SMALL_ENEMY_SPEED, ccp(startPoint.x, -1));
    //sprite->runAction(moveTo);
    //this->addChild(sprite);
    batchNode->addChild(sprite);
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
    //CCLOG("Remove it!");
    int reIndex = *(int*)index;
    CCSprite* sprite = (CCSprite*)enemysArray->objectAtIndex(reIndex);
    enemysArray->removeObjectAtIndex(reIndex);
    //this->removeChild(sprite);
    batchNode->removeChild(sprite, true);
}

//Think about the CCObject pointer index, why to use the local variable pointer
void SmallEnemysView::onCrashEnemy(CCObject* index)
{
    int reIndex = *(int*)index;
    CCSprite* sprite = (CCSprite*)enemysArray->objectAtIndex(reIndex);
    
    CCSprite* aniSprite = CCSprite::createWithSpriteFrameName("enemy1_down1.png");
    aniSprite->setPosition(sprite->getPosition());
    this->addChild(aniSprite);
    CCArray* aniFrames = CCArray::createWithCapacity(SMALL_ENEMY_BLOW_COUNT);
    
    for(int i = 0; i<SMALL_ENEMY_BLOW_COUNT; i++)
    {
        char name[30] = {0};
        sprintf(name, "enemy1_down%d.png", i+1);
        CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);
        CC_BREAK_IF(!spriteFrame);
        aniFrames->addObject(spriteFrame);
    }
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(aniFrames, 0.05f);
    CCAnimate* animate = CCAnimate::create(animation);
    CCSequence* sequence = CCSequence::create(animate, CCCallFuncN::create(this, callfuncN_selector(SmallEnemysView::remove)), NULL);
    aniSprite->runAction(sequence);
    
    batchNode->removeChild(sprite, true);
    enemysArray->removeObjectAtIndex(reIndex);
    //CCDirector::sharedDirector()->pause();
}

void SmallEnemysView::remove(CCNode* node)
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
