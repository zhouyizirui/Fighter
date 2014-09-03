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
}

bool GameObject::init()
{
    player = new Player();
    player->retain();
    
    smallEnemys = new SmallEnemys();
    smallEnemys->init();
    smallEnemys->retain();
    
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
        EnemyPoint* enemy = (EnemyPoint*)smallEnemys->getSmallArray()->objectAtIndex(i);
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
}

void GameObject::update(float dt)
{
    player->update(dt);
    smallEnemys->update(dt);
    collisionDetection();
}