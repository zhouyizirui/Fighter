//
//  MusicEffect.h
//  Fighter
//
//  Created by zhouyizirui on 9/7/14.
//
//

#ifndef __Fighter__MusicEffect__
#define __Fighter__MusicEffect__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "Constants.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace CocosDenshion;

class MusicEffect:public CCObject
{
public:
    MusicEffect();
    ~MusicEffect();
    void playBackgroundMusic();
    void playBulletEmit();
    void playSmallEnemyCrash();
    void playMiddleEnemyCrash();
    void playBigEnemyCrash();
    void playAllCrash();
    void playGetBomb();
    void playGetAmmo();
    void playGameOver();
};
#endif /* defined(__Fighter__MusicEffect__) */
