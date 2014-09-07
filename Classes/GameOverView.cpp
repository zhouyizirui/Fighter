//
//  GameOverView.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/7/14.
//
//

#include "GameOverView.h"

GameOverView::GameOverView()
{

}

GameOverView::~GameOverView()
{

}

CCScene * GameOverView::scene()
{
    CCScene * scene = NULL;
    do
    {
        scene = CCScene::create();
        GameOverView * layer = GameOverView::create();
        scene->addChild(layer);
    }
    while(0);
    return scene;
}

bool GameOverView::init()
{
    if(!CCLayer::init()) return false;
    CCSprite * background = CCSprite::create("overback_opt.png");
    background->setScale(1.5f);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    background->setPosition(ccp(winSize.width/2,winSize.height/1.8));
    this->addChild(background, 0);
    
    CCSize contentSize = background->getContentSize();
    CCMenuItemImage* itemImage = CCMenuItemImage::create("yes_opt.png", "yes_opt.png", this, menu_selector(GameOverView::onYesClicked));
    CCMenu* menu = CCMenu::create(itemImage, NULL);
    menu->setPosition(ccp(winSize.width/2, winSize.height/2.2));
    this->addChild(menu, 1);
    
    this->setTouchEnabled(true);
    
    return true;
}

void GameOverView::onYesClicked()
{
    CCLOG("Yes!");
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