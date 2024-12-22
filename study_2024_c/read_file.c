#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int getFileLines(FILE *file)
{
    if (file == NULL)
    {
        return -1;
    }
    char buf[1024];
    int lines = 0;
    while (fgets(buf, 1024, file))
    {
        lines++;
        printf("%s\n", buf);
    }
    // 将文件光标置首
    fseek(file, 0, SEEK_SET);
    return lines;
}

void readFileData(FILE *file, char **pArray, int len)
{
    if (file == NULL || pArray == NULL || len <= 0)
    {
        return;
    }
    char buf[1024];
    int i = 0;
    while (fgets(buf, 1024, file))
    {
        // 计算开辟的每个字符串大小
        int currentlen = strlen(buf) + 1;
        //将字符串最后一个字符改为\0
        buf[strlen(buf) - 1] = '\0';
        // 开辟堆区空间
        char *currentp = (char *)malloc(sizeof(char) * currentlen);
        // 将从文件中读取的内容开辟到新空间中
        strcpy(currentp, buf);
        // 将新空间的地址放入到pArray中

        pArray[i++] = currentp;
        // 清空buf
        memset(buf, 0, 1024);
    }
}

void shwoFileData(char **pArray, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d行的数据为:  %s\n", i+1 , pArray[i]);
    }
}
void freeSpace(char **pArray,int len)
{
    for (int i = 0; i < len;i++)
    {
        if(pArray[i]!=NULL)
        {
            printf("%s被释放了\n", pArray[i]);
            free(pArray[i]);
            pArray[i] = NULL;
        }
    }
}
void test01()
{

    // 打开文件
    FILE *file = fopen("c.txt", "r");
    if (file == NULL)
    {
        printf("文件打开失败");
        return;
    }

    // 获取有效行数
    int len = getFileLines(file);
    printf("文件有效行数为： %d\n", len);
    char **pArray = (char **)malloc(sizeof(char *) * len);

    // 将文件的数据放入到pArray的数组中
    readFileData(file, pArray, len);

    // 打印数组
    shwoFileData(pArray, len);
    
    //释放堆区空间
    freeSpace(pArray,len);

    //关闭文件
    fclose(file);
}

int main()
{
    test01();
    system("pause");
    return 0;
}