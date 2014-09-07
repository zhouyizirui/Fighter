//
//  MusicEffect.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/7/14.
//
//

#include "MusicEffect.h"
//using namespace CocosDension;
MusicEffect::MusicEffect()
{
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.8);
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.8);
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("game_music.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("bullet.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("enemy1_down.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("enemy2_down.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("enemy3_down.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("use_bomb.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("get_bomb.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("get_double_laser.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("game_over.mp3");
}

MusicEffect::~MusicEffect()
{

}

void MusicEffect::playBackgroundMusic()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("game_music.mp3",true);
}

void MusicEffect::playBulletEmit()
{
    SimpleAudioEngine::sharedEngine()->playEffect("bullet.mp3",false);
}

void MusicEffect::playSmallEnemyCrash()
{
    SimpleAudioEngine::sharedEngine()->playEffect("enemy1_down.mp3",false);
}

void MusicEffect::playMiddleEnemyCrash()
{
    SimpleAudioEngine::sharedEngine()->playEffect("enemy2_down.mp3",false);
}

void MusicEffect::playBigEnemyCrash()
{
    SimpleAudioEngine::sharedEngine()->playEffect("enemy3_down.mp3",false);
}

void MusicEffect::playAllCrash()
{
    SimpleAudioEngine::sharedEngine()->playEffect("use_bomb.mp3",false);
}

void MusicEffect::playGetBomb()
{
    SimpleAudioEngine::sharedEngine()->preloadEffect("get_bomb.mp3");
}

void MusicEffect::playGetAmmo()
{
    SimpleAudioEngine::sharedEngine()->preloadEffect("get_double_laser.mp3");
}

void MusicEffect::playGameOver()
{
    SimpleAudioEngine::sharedEngine()->preloadEffect("game_over.mp3");
}