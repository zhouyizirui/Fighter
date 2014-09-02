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
}

void GameSceneController::update(float dt)
{
    
}

bool GameSceneController::init()
{
    if(CCLayer::init())
    {
        player = new Player();
        pView = GameSceneView::create();
        pView->initWithDelegate(this);
        //pView->initWithPlayer();
        this->addChild(pView, 0);
        this->schedule(schedule_selector(GameSceneController::update));
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
    
}