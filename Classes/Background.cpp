//
//  Background.cpp
//  Fighter
//
//  Created by zhouyizirui on 9/7/14.
//
//

#include "Background.h"

Background::Background()
{

}

Background::~Background()
{
    CC_SAFE_RELEASE(pausePoint);
    CC_SAFE_RELEASE(bombPoint);
}

bool Background::init()
{
    pausePoint = new ModelPoint(1);
    pausePoint->retain();
    pausePoint->setPoint(30, 800-25);
    pausePoint->setSize(PAUSE_WIDTH, PAUSE_HEIGHT);
    bombPoint = new ModelPoint(1);
    bombPoint->retain();
    bombPoint->setPoint(30, 28);
    bombPoint->setSize(BOMB_WIDTH, BOMB_HEIGHT);
    isPaused = false;
    //totalScore = 0;
    totalBomb = 0;
    return true;
}

bool Background::getIsPaused()
{
    return isPaused;
}

int Background::judgePause(CCPoint tapPoint)
{
    CCLOG("Judge pause intersect");
    CCRect rect = CCRectMake(pausePoint->getPointX()-pausePoint->getSize()->getWidth()/2, pausePoint->getPointY()-pausePoint->getSize()->getHeight()/2, pausePoint->getSize()->getWidth(), pausePoint->getSize()->getHeight());
    if(rect.containsPoint(tapPoint) && !isPaused) {
        CCLOG("Pause");
        isPaused = true;
        return -1;
    }
    if(isPaused) {
        CCLOG("Resume");
        isPaused = false;
        return 1;
    }
    else return 0;
}

bool Background::judgeUseBomb(CCPoint tapPoint)
{
    CCLOG("Judge pause intersect");
    if(totalBomb==0) return false;
    CCRect rect = CCRectMake(bombPoint->getPointX()-bombPoint->getSize()->getWidth()/2, bombPoint->getPointY()-bombPoint->getSize()->getHeight()/2, bombPoint->getSize()->getWidth(), bombPoint->getSize()->getHeight());
    return rect.containsPoint(tapPoint);
}

/*
void Background::setScore(int score)
{
    totalScore+=score;
    CCNotificationCenter::sharedNotificationCenter()->postNotification(SET_SCORE, (CCObject*)&totalScore);
}
 */

void Background::useBomb()
{
    totalBomb-=1;
    if(totalBomb==0) CCNotificationCenter::sharedNotificationCenter()->postNotification(CHANGE_BOMB_VISIBLE);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(USE_BOMB, (CCObject*)&totalBomb);
}

void Background::storeBomb()
{
    totalBomb+=1;
    if(totalBomb==1) CCNotificationCenter::sharedNotificationCenter()->postNotification(CHANGE_BOMB_VISIBLE);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(STORE_BOMB, (CCObject*)&totalBomb);
}