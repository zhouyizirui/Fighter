//
//  GameScene.h
//  Fighter
//
//  Created by zhouyizirui on 8/31/14.
//
//

#ifndef __Fighter__GameScene__
#define __Fighter__GameScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Protocols.h"
#include <iostream>

USING_NS_CC;
USING_NS_CC_EXT;

class GameBoardView:public CCLayer
{
private:
    CCSprite* beginSprite;
    CCSprite* quitSprite;
    CCSprite* corp;
    GameBoardViewDelegate* pDelegate;
public:
    virtual bool init();
    void initWithDelegate(GameBoardViewDelegate* delegate);
    CREATE_FUNC(GameBoardView);
    void startGameCallback(CCObject *pSender);
    void exitGameCallback(CCObject* pSender);
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
};

#endif /* defined(__Fighter__GameScene__) */
