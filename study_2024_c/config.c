#include"config.h"

// 获取文件有效行数
int getFileLine(const char *filePath)
{
    FILE *file = fopen(filePath, "r");
    if(file==NULL)
    {
        return -1;
    }
    char buf[1024] = {0};
    int line = 0;
    while(fgets(buf,1024,file)!=NULL)
    {
        if(isinvalidLine(buf))
        {
            line++;
        }
        
    }
    return line;
}

// 判断传入字符是否为有效行
int isinvalidLine(char *str)
{
    if (str[0]=='\n'||strchr(str,':')==NULL)
    {
        return 0; 
    }
    
    return 1;
}
// 文件解析
void parseFile(const char *filePath, struct ConfigInfo **ConfigInfo, int len)
{
    struct ConfigInfo *config = (struct ConfigInfo *)malloc(sizeof(struct ConfigInfo) * len);
    if(config==NULL)
    {
        return;
    }
    FILE *file = fopen(filePath, "r");
    char buf[1024] = {0};//将读取的数据放入到buf中
    int index = 0;
    while (fgets(buf,1024,file)!=NULL)
    {
        if(isinvalidLine(buf))
        {
            memset(config[index].key, 0, 64);
            memset(config[index].value, 0, 64);
            char *pos=strchr(buf, ':');
            //截取key值
            strncpy(config[index].key, buf, pos - buf);
            //截取value值
            strncpy(config[index].value, strchr(buf, ':') + 1, strlen(pos+1)-1);
            //-1是为了不要换行符
            // printf("%s\n", config[index].key);
            // printf("%s\n", config[index].value);
            index++;
        }
        memset(buf, 0, 1024);
    }
    
    *ConfigInfo = config;
}
// 根据key获取value值
char *getValueByKey(struct ConfigInfo *pArray, int len, char *key)
{
    for (int i = 0; i < len; i++)
    {
        if (strcmp(pArray[i].key, key) == 0)
        {
            return pArray[i].value;
        }
    }
    return NULL;
}
// 释放空间
void freeSpace(struct ConfigInfo *pArray, int len)
{
    if (pArray!= NULL)
    {
        free(pArray);
        pArray = NULL;
    }
    free(pArray);
    pArray = NULL;

}