//
//  GameSceneView.h
//  Fighter
//
//  Created by zhouyizirui on 9/1/14.
//
//

#ifndef __Fighter__GameSceneView__
#define __Fighter__GameSceneView__

#include <iostream>
#include "cocos2d.h"
#include "Protocols.h"
#include "PlayerView.h"
#include "BackgroundView.h"
USING_NS_CC;

class GameSceneView:public CCLayer
{
private:
    PlayerView* pPlayer;
    BackgroundView* pBackground;
    GameSceneViewDelegate* pDelegate;
public:
    virtual bool init();
    //virtual void changePosition(CCPoint destPoint);
    void initWithDelegate(GameSceneViewDelegate* delegate);
    //void initWithPlayer(Player* player);
    CREATE_FUNC(GameSceneView);
    void makeBackground();
    void makePlayer();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
};

#endif /* defined(__Fighter__GameSceneView__) */
