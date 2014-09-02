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
    CC_SAFE_RELEASE(pPlayer);
    CC_SAFE_RELEASE(pSmallEnemys);
}

void GameSceneController::createEnemys()
{
    CCLOG("Create a enemy!");
    pSmallEnemys->createEnemy();
}

void GameSceneController::update(float dt)
{

}

bool GameSceneController::init()
{
    if(CCLayer::init())
    {
        pPlayer = new Player();
        pPlayer->retain();
        
        pView = GameSceneView::create();
        pView->initWithDelegate(this);
        pView->retain();
        
        pSmallEnemys = new SmallEnemys();
        pSmallEnemys->retain();
        
        this->addChild(pView, 0);
        this->schedule(schedule_selector(GameSceneController::update));
        this->schedule(schedule_selector(GameSceneController::createEnemys), 3);
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
    pPlayer->movePosition(duraPoint);
}