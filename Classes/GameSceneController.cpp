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
    CC_SAFE_DELETE(musicEffect);
    this->unscheduleAllSelectors();
    //CC_SAFE_RELEASE(pPlayer);
    //CC_SAFE_RELEASE(pSmallEnemys);
    
}

/*
 ccx在各平台的帧率控制方式不太一样。ios上应该是最稳定的，依赖系统回调。而android和winxp上则是一个loop不断地自消息循环，判断时间点，计算到满足两帧之间的时间片后则开始逐个节点visit，否则让出cpu时间片，等下个消息循环。
 
 现在多数情况是，在CPU计算或GLES显示的负荷比较大时，android版本会遇到帧率不稳定的情况，优化后可以解决，也有人去针对自己游戏修改掉帧率控制的代码而解决。这种情况我个人直觉上是每帧的duration在运行时或计算产生了一点量变，积累若干次后产生一个质变，直接跳过去一个小的时间片没有进入引擎逻辑。但这个地方我还没有深入去调试，基本上优化OK的游戏都没有报告这种情况。
 
 ios上则楼主是首次报告这个问题的。效率上的95%的情况都可以通过使用CCSpriteBatchNode优化来得以解决。或者是没有用CCSpriteBatchNode,或者是有用但用错的情况。注意addChild结构必须是 layer->batchNode->sprite, 不能layer->sprite, 而且应让同个batchNode里的sprite texture都处于同一张合并出来的纹理图里，这样才能用CCTextureAtlas里面的功能去实现性能优化
*/
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
    musicEffect->playBulletEmit();
}

void GameSceneController::createAmmo()
{
    pObject->getAmmo()->createAmmo();
}

void GameSceneController::createBomb()
{
    pObject->getBomb()->createBomb();
}

void GameSceneController::update(float dt)
{
    pObject->update(dt);
    if(pObject->isGameOver())
    {
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
        GameOverView* overView = GameOverView::create();
        pView->addLayer(overView);
    }
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
        musicEffect = new MusicEffect();
        musicEffect->playBackgroundMusic(); //FIX ME
        //musicEffect->playBulletEmit(); //FIX ME
        
        pView = GameSceneView::create();
        pView->initWithDelegate(this);
        pView->retain();
        
        pObject = new GameObject();
        pObject->init(musicEffect);   //FIX ME
        pObject->retain();
        pObject->getPlayer()->setPosition();
        

        //musicEffect->retain();
        
        this->addChild(pView, 0);
        this->schedule(schedule_selector(GameSceneController::update));
        this->schedule(schedule_selector(GameSceneController::createBullets), 0.15f);//0.15
        this->schedule(schedule_selector(GameSceneController::createSmallEnemys), 0.7f);
        this->schedule(schedule_selector(GameSceneController::createMiddleEnemys), 7.0f);
        this->schedule(schedule_selector(GameSceneController::createBigEnemys), 14.0f);
        this->schedule(schedule_selector(GameSceneController::createAmmo), 60.0f);
        this->schedule(schedule_selector(GameSceneController::createBomb), 40.0f);
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

void GameSceneController::pauseGame()
{
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    CCDirector::sharedDirector()->pause();
}

void GameSceneController::resumeGame()
{
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    CCDirector::sharedDirector()->resume();
}

void GameSceneController::dealWithTouchBegan(CCPoint startPoint)
{
    int indicator = pObject->getBackground()->judgePause(startPoint);
    if(indicator==-1) pauseGame();
    else if(indicator==1) resumeGame();
    
    bool clear = pObject->getBackground()->judgeUseBomb(startPoint);
    CCLOG("%d",clear);
    if(clear) pObject->clearDesktop();
}

void GameSceneController::dealWithTouchMove(CCPoint duraPoint)
{
    pObject->getPlayer()->movePosition(duraPoint);
}