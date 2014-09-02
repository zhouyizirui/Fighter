//
//  GameControlLayer.cpp
//  Fighter
//
//  Created by zhouyizirui on 8/31/14.
//
//

#include "GameBoardController.h"
#include "GameSceneController.h"

GameBoardController::GameBoardController()
{
}

GameBoardController::~GameBoardController()
{
    CC_SAFE_RELEASE(pView);
}

bool GameBoardController::init()
{
    if(CCLayer::init())
    {
        pView = GameBoardView::create();
        pView->initWithDelegate(this);
        pView->retain();
        this->addChild(pView, 0);
        this->schedule(schedule_selector(GameBoardController::update));
        //this->setTouchEnabled(true);
    }
    return true;
}

CCScene* GameBoardController::scene()
{
    CCScene* scene = NULL;
    do{
        scene = CCScene::create();
        CC_BREAK_IF(!scene);
        GameBoardController* controlLayer = GameBoardController::create();
        CC_BREAK_IF(!controlLayer);
        scene->addChild(controlLayer);
    }while(0);
    return scene;
}

void GameBoardController::update(float dt)
{
    
}

bool GameBoardController::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLOG("The fucking touch began");
    return true;
}

void GameBoardController::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLOG("The fucking touch moved");
}

void GameBoardController::dealWithTouchBegan(CCPoint startPoint, int flag)
{
    if(flag==1)
    {
        CCLOG("Begin the game!");
        CCDirector::sharedDirector()->replaceScene(GameSceneController::scene());
    }
    else if(flag==-1)
    {
        CCLOG("Quit the game!");
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
            CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    #else
            CCDirector::sharedDirector()->end();
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            exit(0);
    #endif
    #endif
    }
}
