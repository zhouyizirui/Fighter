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
    CC_SAFE_RELEASE(smallEnemys);
    CC_SAFE_RELEASE(bullets);
}

bool GameObject::init()
{
    player = new Player();
    player->retain();
    
    smallEnemys = new SmallEnemys();
    smallEnemys->init();
    smallEnemys->retain();
    
    bullets = new Bullets();
    bullets->init();
    bullets->retain();
    
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

Bullets* GameObject::getBullets()
{
    return bullets;
}

bool GameObject::isIntersect(CCPoint* aPoint, ModelSize* aSize, CCPoint* bPoint, ModelSize* bSize)
{
    CCRect aRect = CCRectMake(aPoint->x-aSize->getWidth()/2, aPoint->y-aSize->getHeight()/2, aSize->getWidth(), aSize->getHeight());
    CCRect bRect = CCRectMake(bPoint->x-bSize->getWidth()/2, bPoint->y-bSize->getHeight()/2, bSize->getWidth(), bSize->getHeight());
    //CCLOG("The a arect %f, %f", aRect.getMaxX(), aRect.getMaxY());
    //CCLOG("The b arect %f, %f", bRect.getMaxX(), bRect.getMaxY());
    return aRect.intersectsRect(bRect);
}

void GameObject::collisionDetection()
{
    for(int i=0; i<smallEnemys->getSmallArray()->count(); i++)
    {
        ModelPoint* enemy = (ModelPoint*)smallEnemys->getSmallArray()->objectAtIndex(i);
        //CCLOG("enemy size %f, %f", enemy->getSize()->getWidth(), enemy->getSize()->getHeight());
        //CCLOG("HAHAHHA enemy point %f, %f", enemy->getPosition()->x, enemy->getPosition()->y);
        //CCLOG("Player point %f, %f", player->getPosition()->x, player->getPosition()->y);
        if(isIntersect(enemy->getPosition(), enemy->getSize(), player->getPosition(), player->getSize()))
        {
            //CCDirector::sharedDirector()->pause();
            player->hitEnemy();
            smallEnemys->hitPlayer(i);
            break;
        }
        //if(player->getPosition())
    }
    for(int i=0; i<bullets->getBulletArray()->count(); i++)
    {
        ModelPoint* bullet = (ModelPoint*)bullets->getBulletArray()->objectAtIndex(i);
        for(int j=0; j<smallEnemys->getSmallArray()->count(); j++)
        {
            ModelPoint* smallEnemy = (ModelPoint*)smallEnemys->getSmallArray()->objectAtIndex(j);
            if(isIntersect(bullet->getPosition(), bullet->getSize(), smallEnemy->getPosition(), smallEnemy->getSize()))
            {
                bullets->hitEnemy(i);
                smallEnemys->hitBullet(j);
            }
        }
    }
}

void GameObject::update(float dt)
{
    player->update(dt);
    smallEnemys->update(dt);
    bullets->update(dt);
    collisionDetection();
}