//
//  GameObject.cpp
//  Fighter
//
//  Created by zhouyizirui on 8/31/14.
//
//

#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
    CC_SAFE_RELEASE(player);
    CC_SAFE_RELEASE(background);
    CC_SAFE_RELEASE(smallEnemys);
    CC_SAFE_RELEASE(middleEnemys);
    CC_SAFE_RELEASE(bigEnemys);
    CC_SAFE_RELEASE(bullets);
    CC_SAFE_RELEASE(ammo);
    CC_SAFE_RELEASE(bomb);
}

bool GameObject::init(MusicEffect* musicEffect) //FIX ME
{
    player = new Player();
    player->retain();
    
    background = new Background();
    background->init();
    background->retain();
    
    smallEnemys = new SmallEnemys();
    smallEnemys->init();
    smallEnemys->retain();
    
    middleEnemys = new MiddleEnemys();
    middleEnemys->init();
    middleEnemys->retain();
    
    bigEnemys = new BigEnemys();
    bigEnemys->init();
    bigEnemys->retain();
    
    bullets = new Bullets();
    bullets->init();
    bullets->retain();
    
    ammo = new Ammo();
    ammo->init();
    ammo->retain();
    
    bomb = new Bomb();
    bomb->init();
    bomb->retain();
    
    this->musicEffect = musicEffect;
    //this->musicEffect->playBackgroundMusic(); //FIX ME
    CCNotificationCenter::sharedNotificationCenter()->postNotification(PLAY_BACKGROUND_MUSIC);
    
    isOver = false;
    
    return true;
}

Player* GameObject::getPlayer()
{
    return player;
}

SmallEnemys* GameObject::getSmallEnemys()
{
    return smallEnemys;
}

MiddleEnemys* GameObject::getMiddleEnemys()
{
    return middleEnemys;
}

BigEnemys* GameObject::getBigEnemys()
{
    return bigEnemys;
}

Bullets* GameObject::getBullets()
{
    return bullets;
}

Background* GameObject::getBackground()
{
    return background;
}

void GameObject::clearDesktop()
{
    int smallCount = smallEnemys->getSmallArray()->count();
    int middleCount = middleEnemys->getMiddleArray()->count();
    int bigCount = bigEnemys->getBigArray()->count();
    for(int i=0; i<smallCount; i++)
    {
        smallEnemys->hitPlayer(0);
    }
    for(int i=0; i<middleCount; i++)
    {
        middleEnemys->hitPlayer(0);
    }
    for(int i=0; i<bigCount; i++)
    {
        bigEnemys->hitPlayer(0);
    }
    background->useBomb();
    //musicEffect->playAllCrash(); //FIX ME
    CCNotificationCenter::sharedNotificationCenter()->postNotification(PLAY_ALL_CRASH_EFFECT);
}

bool GameObject::isGameOver()
{
    //musicEffect->playGameOver(); //FIX ME
    if(isOver) CCNotificationCenter::sharedNotificationCenter()->postNotification(PLAY_GAME_OVER_EFFECT);
    return isOver;
}

bool GameObject::isIntersect(CCPoint* aPoint, ModelSize* aSize, CCPoint* bPoint, ModelSize* bSize)
{
    CCRect aRect = CCRectMake(aPoint->x-aSize->getWidth()/2, aPoint->y-aSize->getHeight()/2, aSize->getWidth(), aSize->getHeight());
    CCRect bRect = CCRectMake(bPoint->x-bSize->getWidth()/2, bPoint->y-bSize->getHeight()/2, bSize->getWidth(), bSize->getHeight());
    return aRect.intersectsRect(bRect);
}

void GameObject::collisionDetection()
{
    //Detect player hit enemy
    for(int i=0; i<smallEnemys->getSmallArray()->count(); i++)
    {
        ModelPoint* enemy = (ModelPoint*)smallEnemys->getSmallArray()->objectAtIndex(i);
        if(isIntersect(enemy->getPosition(), enemy->getSize(), player->getPosition(), player->getSize()))
        {
            player->hitEnemy();
            smallEnemys->hitPlayer(i);
            isOver = true;
            break;
        }
    }
    for(int i=0; i<middleEnemys->getMiddleArray()->count(); i++)
    {
        ModelPoint* enemy = (ModelPoint*)middleEnemys->getMiddleArray()->objectAtIndex(i);
        if(isIntersect(enemy->getPosition(), enemy->getSize(), player->getPosition(), player->getSize()))
        {
            player->hitEnemy();
            middleEnemys->hitPlayer(i);
            isOver = true;
            break;
        }
    }
    for(int i=0; i<bigEnemys->getBigArray()->count(); i++)
    {
        ModelPoint* enemy = (ModelPoint*)bigEnemys->getBigArray()->objectAtIndex(i);
        if(isIntersect(enemy->getPosition(), enemy->getSize(), player->getPosition(), player->getSize()))
        {
            player->hitEnemy();
            bigEnemys->hitPlayer(i);
            isOver = true;
            break;
        }
    }
    
    //Detect bullet hit enemy
    for(int i=0; i<bullets->getBulletArray()->count(); i++)
    {
        bool jump = false;
        ModelPoint* bullet = (ModelPoint*)bullets->getBulletArray()->objectAtIndex(i);
        for(int j=0; j<smallEnemys->getSmallArray()->count(); j++)
        {
            ModelPoint* smallEnemy = (ModelPoint*)smallEnemys->getSmallArray()->objectAtIndex(j);
            if(isIntersect(bullet->getPosition(), bullet->getSize(), smallEnemy->getPosition(), smallEnemy->getSize()))
            {
                bullets->hitEnemy(i);
                smallEnemys->hitBullet(j);
                jump = true;
                break;
            }
        }
        CC_BREAK_IF(jump);
        for(int j=0; j<middleEnemys->getMiddleArray()->count(); j++)
        {
            ModelPoint* middleEnemy = (ModelPoint*)middleEnemys->getMiddleArray()->objectAtIndex(j);
            if(isIntersect(bullet->getPosition(), bullet->getSize(), middleEnemy->getPosition(), middleEnemy->getSize()))
            {
                bullets->hitEnemy(i);
                middleEnemys->hitBullet(j);
                jump = true;
                break;
            }
        }
        CC_BREAK_IF(jump);
        for(int j=0; j<bigEnemys->getBigArray()->count(); j++)
        {
            ModelPoint* bigEnemy = (ModelPoint*)bigEnemys->getBigArray()->objectAtIndex(j);
            if(isIntersect(bullet->getPosition(), bullet->getSize(), bigEnemy->getPosition(), bigEnemy->getSize()))
            {
                bullets->hitEnemy(i);
                bigEnemys->hitBullet(j);
                jump = true;
                break;
            }
        }
        CC_BREAK_IF(jump);
    }
    
    //Detect ammo hit player
    if(isIntersect(ammo->getAmmo()->getPosition(), ammo->getAmmo()->getSize(), player->getPosition(), player->getSize()) && ammo->getIsVisible())
    {
        CCLOG("In the intersect");
        //musicEffect->playGetAmmo(); //FIX ME
        CCNotificationCenter::sharedNotificationCenter()->postNotification(PLAY_GET_AMMO_EFFECT);
        bullets->upgradeSuper();
        ammo->hitPlayer();
    }
    
    //Dectect bomb hit player
    if(isIntersect(bomb->getBomb()->getPosition(), bomb->getBomb()->getSize(), player->getPosition(), player->getSize()) && bomb->getIsVisible())
    {
        CCLOG("In the intersect");
        //bullets->upgradeSuper();
        //musicEffect->playGetBomb(); //FIX ME
        CCNotificationCenter::sharedNotificationCenter()->postNotification(PLAY_GET_BOMB_EFFECT);
        background->storeBomb();
        bomb->hitPlayer();
    }
}

void GameObject::statusRefresh()
{
    if(bullets->getSuperCount()<=0)
    {
        //CCLOG("The lower boy");
        bullets->downgradeNormal();
    }
}

Ammo* GameObject::getAmmo()
{
    return ammo;
}

Bomb* GameObject::getBomb()
{
    return bomb;
}

void GameObject::update(float dt)
{
    player->update(dt);
    smallEnemys->update(dt);
    middleEnemys->update(dt);
    bigEnemys->update(dt);
    bullets->update(dt);
    ammo->update(dt);
    bomb->update(dt);
    collisionDetection();
    statusRefresh();
}