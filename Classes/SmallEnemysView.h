//
//  SmallEnemysView.h
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#ifndef __Fighter__SmallEnemysView__
#define __Fighter__SmallEnemysView__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class SmallEnemysView:public CCLayer
{
private:
    CCArray* enemysArray;
public:
    SmallEnemysView();
    ~SmallEnemysView();
    void onMoveStep();
    void onEnemyMove();
    void remove(CCNode* node);
    void onRemoveEnemy(CCObject* index);
    void onCrashEnemy(CCObject* index);
    void onCreateEnemy(CCObject* setPoint);
    bool init();
    CREATE_FUNC(SmallEnemysView);
};
#endif /* defined(__Fighter__SmallEnemysView__) */
