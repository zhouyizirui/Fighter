//
//  GameSceneController.h
//  Fighter
//
//  Created by zhouyizirui on 9/1/14.
//
//

#ifndef __Fighter__GameSceneController__
#define __Fighter__GameSceneController__

#include <iostream>
#include "GameSceneView.h"
#include "Protocols.h"
#include "Player.h"
#include "SmallEnemys.h"
#include "GameObject.h"

class GameSceneController:public CCLayer, public GameSceneViewDelegate
{
private:
    GameSceneView* pView;
    GameObject* pObject;
public:
    GameSceneController();
    virtual ~GameSceneController();
    static CCScene* scene();
    virtual void dealWithTouchBegan(CCPoint startPoint);
    virtual void dealWithTouchMove(CCPoint duraPoint);
    virtual bool init();
    void update(float dt);
    void createMiddleEnemys();
    void createSmallEnemys();
    void createBullets();
    CREATE_FUNC(GameSceneController);
};
#endif /* defined(__Fighter__GameSceneController__) */
