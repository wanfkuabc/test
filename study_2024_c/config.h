#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//配置信息结构体
struct ConfigInfo
{
    char key[64];
    char value[64];
};

//获取文件有效行数
int getFileLine(const char *filePath);

// 判断传入字符是否为有效行
int isinvalidLine(char *str);

//文件解析
void parseFile(const char *filePath, struct ConfigInfo **pArray, int len);

//根据key获取value值
char *getValueByKey(struct ConfigInfo *pArray, int len, char *key);

//释放空间
void freeSpace(struct ConfigInfo *pArray, int len);