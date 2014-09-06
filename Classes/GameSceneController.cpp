//
//  GameSceneController.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/1/14.
//
//

#include "GameSceneController.h"

GameSceneController::GameSceneController()
{
}

GameSceneController::~GameSceneController()
{
    CC_SAFE_RELEASE(pView);
    CC_SAFE_RELEASE(pObject);
    this->unscheduleAllSelectors();
    //CC_SAFE_RELEASE(pPlayer);
    //CC_SAFE_RELEASE(pSmallEnemys);
    
}

void GameSceneController::createSmallEnemys()
{
    //CCLOG("Create a enemy!");
    pObject->getSmallEnemys()->createEnemy();
    //pSmallEnemys->createEnemy();
}

void GameSceneController::createMiddleEnemys()
{
    pObject->getMiddleEnemys()->createEnemy();
}

void GameSceneController::createBigEnemys()
{
    pObject->getBigEnemys()->createEnemy();
}

void GameSceneController::createBullets()
{
    //CCLOG("Create a bullet!");
    CCPoint point = *(pObject->getPlayer()->getPosition());
    pObject->getBullets()->createBullet(point);
}

void GameSceneController::createAmmo()
{
    pObject->getAmmo()->createAmmo();
}

void GameSceneController::update(float dt)
{
    pObject->update(dt);
}

bool GameSceneController::init()
{
    if(CCLayer::init())
    {
        /*
        pPlayer = new Player();
        pPlayer->retain();
        
        pSmallEnemys = new SmallEnemys();
        pSmallEnemys->retain();
        */
        
        pView = GameSceneView::create();
        pView->initWithDelegate(this);
        pView->retain();
        
        pObject = new GameObject();
        pObject->init();
        pObject->retain();
        pObject->getPlayer()->setPosition();
        
        this->addChild(pView, 0);
        this->schedule(schedule_selector(GameSceneController::update));
        this->schedule(schedule_selector(GameSceneController::createBullets), 0.15f);
        this->schedule(schedule_selector(GameSceneController::createSmallEnemys), 0.7f);
        //this->schedule(schedule_selector(GameSceneController::createMiddleEnemys), 10.0f);
        //this->schedule(schedule_selector(GameSceneController::createBigEnemys), 20.0f);
        //this->schedule(schedule_selector(GameSceneController::createAmmo), 8.0f);
    }
    return true;
}

CCScene* GameSceneController::scene()
{
    CCScene* scene = NULL;
    do{
        scene = CCScene::create();
        CC_BREAK_IF(!scene);
        GameSceneController* controlLayer = GameSceneController::create();
        CC_BREAK_IF(!controlLayer);
        scene->addChild(controlLayer);
    }while(0);
    return scene;
}

void GameSceneController::dealWithTouchBegan(CCPoint startPoint)
{
    
}

void GameSceneController::dealWithTouchMove(CCPoint duraPoint)
{
    //Judge the point whether exceeds the border or not
    //CCLOG("Move the scene controller");
    pObject->getPlayer()->movePosition(duraPoint);
}