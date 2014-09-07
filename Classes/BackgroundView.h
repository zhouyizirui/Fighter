//
//  BackgroundView.h
//  Fighter
//
//  Created by zhouyizirui on 9/2/14.
//
//

#ifndef __Fighter__BackgroundView__
#define __Fighter__BackgroundView__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class BackgroundView: public CCSprite
{
private:
    CCSpriteBatchNode* batchNode;
    CCSprite* backPicture1;
    CCSprite* backPicture2;
    CCSprite* bomb;
    CCLabelBMFont* bmFont;
    CCSprite* pauseButton;
public:
    BackgroundView();
    ~BackgroundView();
    bool init();
    virtual void update(float delta);
    void changeBombVisible();
    CREATE_FUNC(BackgroundView);
};

#endif /* defined(__Fighter__BackgroundView__) */
