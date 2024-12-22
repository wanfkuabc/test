#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "config.c"

int main()
{
    int line = getFileLine("hero.txt");
    printf("文件有效行数： %d\n", line);

    //将文件中的数据解析，并且放到数组中
    struct ConfigInfo *ConfigInfo=NULL;
    parseFile("hero.txt", &ConfigInfo, line);

    //根据key获取value值
    printf("heroId=%s\n", getValueByKey(ConfigInfo, line, "heroId"));
    printf("heroName=%s\n", getValueByKey(ConfigInfo, line, "heroName"));
    printf("heroAtk=%s\n", getValueByKey(ConfigInfo, line, "heroAtk"));
    printf("heroDef=%s\n", getValueByKey(ConfigInfo, line, "heroDef"));
    printf("heroInfo=%s\n", getValueByKey(ConfigInfo, line, "heroInfo"));

    //释放空间
    freeSpace(ConfigInfo, line);
    return 0;
}