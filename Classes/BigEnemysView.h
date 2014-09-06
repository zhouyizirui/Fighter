//
//  BigEnemysView.h
//  Fighter
//
//  Created by zhouyizirui on 9/6/14.
//
//

#ifndef __Fighter__BigEnemysView__
#define __Fighter__BigEnemysView__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class BigEnemysView:public CCLayer
{
private:
    CCArray* enemysArray;
public:
    BigEnemysView();
    ~BigEnemysView();
    void onMoveStep();
    void onEnemyMove();
    void onHitten(CCObject* index);
    void remove(CCNode* node);
    void onRemoveEnemy(CCObject* index);
    void onCrashEnemy(CCObject* index);
    void onCreateEnemy(CCObject* setPoint);
    bool init();
    CREATE_FUNC(BigEnemysView);
};

#endif /* defined(__Fighter__BigEnemysView__) */
