#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include"gameCompany1.c"
#include<time.h>
// 初始化游戏   参数一： 人物指针   参数二： 人物姓名：
typedef void (*INIT_GAME)(void **player, char *name);

// 核心战斗  如果战斗胜利 返回一   参数一：玩家  参数二： 副本难度
typedef int (*FIGHT_GAME)(void *player, int gameDiff);

// 查看玩家信息
typedef void (*PRINT_GAME)(void *player);

// 离开游戏
typedef void (*EXIT_GAME)(void *player);

// 甲方功能实现
void playGame(INIT_GAME init, FIGHT_GAME fight, PRINT_GAME printGame, EXIT_GAME exitGame)
{
    // 初始化游戏
    void *player = NULL;
    printf("请输入玩家姓名： \n");
    char buf[1024];
    scanf("%s", buf);
    init(&player, buf);

    int diff = 0;
    while (1)
    {
        getchar();
        system("cls");
        // 游戏难度
        printf("请选择游戏难度：\n ");
        printf("1.简单\n");
        printf("2.困难\n");
        printf("3.地狱\n");

        scanf("%d", &diff);
        getchar();
        int ret = fight(player, diff);
        if (ret == 0)
        {
            printf("游戏结束，再接再厉\n");
            break;
        }
        else
        {
            printf("胜利\n");
            // 查看玩家当前状态
            printGame(player);
        }
    }
    
    
    // 退出游戏
    exitGame(player);
}

int main()
{
    srand((unsigned int)time(NULL));
    playGame(INIT_GAME_COMPANY1, FIGHT_GAME_COMPANY1, PRINT_GAME_COMPANY1, EXIT_GAME_COMPANY1);
    return 0;
}