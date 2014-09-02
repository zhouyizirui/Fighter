//
//  GameControlLayer.h
//  Fighter
//
//  Created by zhouyizirui on 8/31/14.
//
//

#ifndef __Fighter__GameControlLayer__
#define __Fighter__GameControlLayer__

#include <iostream>
#include "GameLayer.h"
#include "GameBoardView.h"
#include "Protocols.h"

class GameBoardController:public CCLayer, public GameBoardViewDelegate
{
private:
    GameBoardView* pView;
    
public:
    GameBoardController();
    virtual ~GameBoardController();
    virtual void dealWithTouchBegan(CCPoint startPoint, int flag);
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(GameBoardController);
    void update(float dt);
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
};
#endif /* defined(__Fighter__GameControlLayer__) */
