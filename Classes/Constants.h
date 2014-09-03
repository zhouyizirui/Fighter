//
//  Constants.h
//  Fighter
//
//  Created by zhouyizirui on 8/31/14.
//
//

#ifndef Fighter_Constants_h
#define Fighter_Constants_h


#define S_START "开始游戏"
#define S_EXIT "退出游戏"
#define PLANE_SET "Set"
#define PLANE_MOVE "Move"
#define PLANE_BROKEN "Broken"

#define ADD_SMALL_ENEMY "AddSmallEnemy"
#define SMALL_ENEMY_MOVE "SmallEnemyMove"
#define REMOVE_ENEMY "RemoveEnemy"

#define FRAME_INTERVAL 0.017

#define SMALL_ENEMY_SPEED 160
#define MIDDLE_ENEMY_SPEED 130
#define BIG_ENEMY_SPEED 100

#define PLAYER_FRAME_COUNT 2

enum PLAYER_STATE{
    PLAYER_STABLE = 1,
    PLAYER_MOVE,
    PLAYER_CRASH
};


#endif
