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
    
}

bool Background::init()
{
    pausePoint = new ModelPoint(1);
    pausePoint->setPoint(30, 800-25);
    pausePoint->setSize(PAUSE_WIDTH, PAUSE_HEIGHT);
    isPaused = false;
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

void Background::setScore(int score)
{
    CCNotificationCenter::sharedNotificationCenter()->postNotification(SET_SCORE, (CCObject*)&score);
}