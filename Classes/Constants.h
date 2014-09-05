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
#define MOVE_SMALL_ENEMY "SmallEnemyMove"
#define REMOVE_SMALL_ENEMY "RemoveSmallEnemy"
#define CRASH_SMALL_ENEMY "CrashSmallEnemy"
#define ADD_MIDDLE_ENEMY "AddMiddleEnemy"
#define MOVE_MIDDLE_ENEMY "MoveMiddleEnemy"
#define REMOVE_MIDDLE_ENEMY "RemoveMiddleEnemy"
#define CRASH_MIDDLE_ENEMY "CrashMiddleEnemy"
#define HIT_MIDDLE_ENEMY "HitMiddleEnemy"
#define ADD_NORMAL_BULLET "AddNormalBullet"
#define MOVE_NORMAL_BULLET "NormalBulletMove"
#define REMOVE_NORMAL_BULLET "RemoveNormalBullet"

#define FRAME_INTERVAL 0.017

#define SMALL_ENEMY_SPEED 200
#define MIDDLE_ENEMY_SPEED 130
#define BIG_ENEMY_SPEED 100
#define BULLET_SPEED 1300

#define SMALL_ENEMY_WIDTH 57
#define SMALL_ENEMY_HEIGHT 43
#define MIDDLE_ENEMY_WIDTH 69
#define MIDDLE_ENEMY_HEIGHT 99
#define PLAYER_WIDTH 70
#define PLAYER_HEIGHT 100
#define BULLET_WIDTH 5
#define BULLET_HEIGHT 20

#define PLAYER_FRAME_COUNT 2
#define PLAYER_BLOW_COUNT 4
#define SMALL_ENEMY_BLOW_COUNT 4
#define MIDDLE_ENEMY_BLOW_COUNT 4
#define MIDDLE_ENEMY_HIT_COUNT 1

enum PLAYER_STATE{
    PLAYER_STABLE = 1,
    PLAYER_MOVE,
    PLAYER_CRASH
};

enum BULLET_TYPE{
    NORMAL_BULLET = 1,
    SUPER_BULLET = 2
};


#endif
