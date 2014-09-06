//
//  MiddleEnemysView.h
//  Fighter
//
//  Created by zhouyizirui on 9/5/14.
//
//

#ifndef __Fighter__MiddleEnemysView__
#define __Fighter__MiddleEnemysView__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class MiddleEnemysView:public CCLayer
{
private:
    CCArray* enemysArray;
    CCSpriteBatchNode* batchNode;
public:
    MiddleEnemysView();
    ~MiddleEnemysView();
    void onMoveStep();
    void onEnemyMove();
    void onHitten(CCObject* index);
    void remove(CCNode* node);
    void onRemoveEnemy(CCObject* index);
    void onCrashEnemy(CCObject* index);
    void onCreateEnemy(CCObject* setPoint);
    bool init();
    CREATE_FUNC(MiddleEnemysView);
};

#endif /* defined(__Fighter__MiddleEnemysView__) */
