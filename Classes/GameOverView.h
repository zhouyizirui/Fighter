//
//  GameOverView.h
//  Fighter
//
//  Created by zhouyizirui on 9/7/14.
//
//

#ifndef __Fighter__GameOverView__
#define __Fighter__GameOverView__

#include <iostream>
#include "cocos2d.h"


USING_NS_CC;

class GameOverView:public CCLayer
{
private:
    
public:
    static CCScene * scene();
    GameOverView();
    ~GameOverView();
    bool init();
    CREATE_FUNC(GameOverView);
    void onYesClicked();
};

#endif /* defined(__Fighter__GameOverView__) */
