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
#define ADD_BIG_ENEMY "AddBigEnemy"
#define MOVE_BIG_ENEMY "MoveBigEnemy"
#define REMOVE_BIG_ENEMY "RemoveBigEnemy"
#define CRASH_BIG_ENEMY "CrashBigEnemy"
#define HIT_BIG_ENEMY "HitBigEnemy"
#define CHANGE_BOMB_VISIBLE "ChangeBombVisible"

#define ADD_NORMAL_BULLET "AddNormalBullet"
#define MOVE_BULLET "BulletMove"
#define REMOVE_BULLET "RemoveBullet"
#define ADD_SUPER_BULLET "AddSuperBullet"
#define ADD_AMMO "AddAmmo"
#define MOVE_AMMO "MoveAmmo"
#define REMOVE_AMMO "RemoveAmmo"
#define SET_SCORE "SetScore"
#define ADD_BOMB "AddBomb"
#define MOVE_BOMB "MoveBomb"
#define REMOVE_BOMB "RemoveBomb"
#define STORE_BOMB "StoreBomb"
#define USE_BOMB "UseBomb"

#define PLAY_BACKGROUND_MUSIC "PlayBackground"
#define PLAY_BULLET_EFFECT "PlayBulletEffect"
#define PLAY_SMALL_CRASH_EFFECT "PlaySmallEffect"
#define PLAY_MIDDLE_CRASH_EFFECT "PlayMiddleEffect"
#define PLAY_BIG_CRASH_EFFECT "PlayBigEffect"
#define PLAY_ALL_CRASH_EFFECT "PlayAllCrash"
#define PLAY_GET_BOMB_EFFECT "PlayGetBomb"
#define PLAY_GET_AMMO_EFFECT "PlayGetAmmo"
#define PLAY_GAME_OVER_EFFECT "PlayGameOver"
//#define MOVE_SUPER_BULLET "SuperBulletMove"
//#define REMOVE_SUPER_BULLET "RemoveSuperBullet"

#define FRAME_INTERVAL 0.017*2

#define SMALL_ENEMY_SPEED 190
#define MIDDLE_ENEMY_SPEED 120
#define BIG_ENEMY_SPEED 70
#define BULLET_SPEED 1000
#define AMMO_SPEED 400
#define BOMB_SPEED 400

#define SMALL_ENEMY_WIDTH 57
#define SMALL_ENEMY_HEIGHT 43
#define MIDDLE_ENEMY_WIDTH 69
#define MIDDLE_ENEMY_HEIGHT 99
#define BIG_ENEMY_WIDTH 169
#define BIG_ENEMY_HEIGHT 258
#define PLAYER_WIDTH 70
#define PLAYER_HEIGHT 100
#define BULLET_WIDTH 8
#define BULLET_HEIGHT 20
#define AMMO_WIDTH 58
#define AMMO_HEIGHT 88
#define BOMB_WIDTH 63
#define BOMB_HEIGHT 57
#define PAUSE_WIDTH 60
#define PAUSE_HEIGHT 45

#define PLAYER_FRAME_COUNT 2
#define PLAYER_BLOW_COUNT 4
#define SMALL_ENEMY_BLOW_COUNT 4
#define MIDDLE_ENEMY_BLOW_COUNT 4
#define MIDDLE_ENEMY_HIT_COUNT 1
#define BIG_ENEMY_BLOW_COUNT 6
#define BIG_ENEMY_HIT_COUNT 1
#define LOAD_ENEMY_COUNT 4

#define SMALL_ENEMY_SCORE 1000
#define MIDDLE_ENEMY_SCORE 5000
#define BIG_ENEMY_SCORE 20000

#define UPGRADE_SUPER_COUNT 100

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
