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

void GameObject::collisionDetection()
{
    
}

void GameObject::update(float dt)
{
    player->update(dt);
    smallEnemys->update(dt);
}