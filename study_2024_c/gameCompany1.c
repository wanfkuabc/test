#include"gameCompany1.h"

// 初始化游戏   参数一： 人物指针   参数二： 人物姓名：
void INIT_GAME_COMPANY1(void **pl, char *name)
{
    struct Player*player=(struct Player*)malloc(sizeof(struct Player));
    if(player==NULL)
    {
        return;
    }
    *pl=player;
    strcpy(player->name, name); // 给玩家姓名赋值
    player->exp=0;
    player->level=0;
}


// 核心战斗  如果战斗胜利 返回一   参数一：玩家  参数二： 副本难度
int FIGHT_GAME_COMPANY1(void *p, int gameDiff)
{
    struct Player*player=(struct Player*)p;

    int addExp=0;//给玩家增加经验

    switch (gameDiff)
    {
    case 1://传入胜率
        addExp=isWin(90, 1);
        break;
    case 2:
        addExp = isWin(50, 2);
        break;
    case 3:
        addExp = isWin(30, 3);
        break;

    default:
        break;
    }
    // 给玩家增加经验
    player->exp += addExp;
    // 玩家升级
    player->level = player->exp / 10;
    if(addExp==0)
    {
        // 失败

        return 0;
    }
    else
    {
        // 胜利
        return 1;
    }

}
// 判断玩家是否胜利
int isWin(int winRate, int gameDiff)
{
    // 生成随机数
    int randomNum=rand()%100+1;
    if(randomNum<=winRate)
    {
        // 胜利
        return gameDiff * 10;
    }
    else
    {
        // 失败
        return 0;
    }


}
// 查看玩家信息
void PRINT_GAME_COMPANY1(void *p)
{
    struct Player *player = (struct Player *)p;
    printf("玩家姓名：<%s>-----------当前等级<%d>----------当前经验<%d>\n", player->name, player->level, player->exp);
}

// 离开游戏
void EXIT_GAME_COMPANY1(void *player)
{
    if(player==NULL)
    {
        return;
    }
    free(player);
    player=NULL;
}