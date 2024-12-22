#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Player
{
    char name[64];
    int level;
    int exp;
};

// 初始化游戏   参数一： 人物指针   参数二： 人物姓名：
void  INIT_GAME_COMPANY1(void **pl, char *name);

// 核心战斗  如果战斗胜利 返回一   参数一：玩家  参数二： 副本难度
int FIGHT_GAME_COMPANY1(void *player, int gameDiff);

// 查看玩家信息
void PRINT_GAME_COMPANY1(void *player);

// 离开游戏
void EXIT_GAME_COMPANY1(void *player);

//判断玩家是否胜利
int isWin(int winRate, int gameDiff);