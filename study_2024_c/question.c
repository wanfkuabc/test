#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct Person
{
    char* name;
    int age;
};
struct Person** allocateSpace()
{
    struct Person **temp = (struct Person **)malloc(sizeof(struct Person *) * 3);
    for (int i = 0;i<3;i++)
    {
        temp[i] = (struct Person *)malloc(sizeof(struct Person));
        temp[i]->name = (char *)malloc(sizeof(char) * 64);
        sprintf(temp[i]->name, "name_%d", i + 1);
        temp[i]->age = rand() % 100;
    }
    return temp;

}

void printPerson(struct Person **pArr, int len)
{
    for (int i = 0;i<len;i++)
    {
        printf("name = %s, age = %d\n", pArr[i]->name, pArr[i]->age);
    }
}
void freeSpace(struct Person **pArr, int len)
{
 if(pArr == NULL||len<=0)
 {
     return;
 }
 for (int i = 0;i<len;i++)
 {
     if (pArr[i]->name != NULL)
     {
         printf("%s释放成功\n", pArr[i]->name);
         free(pArr[i]->name);
         pArr[i]->name = NULL;
       
     }
     if(pArr[i]!=NULL)
     {
         free(pArr[i]);
         pArr[i] = NULL;
  
     }
 }
    free(pArr);
    pArr = NULL;
}

void test01()
{
    struct Person **pArr = NULL; //(struct Person **)malloc(sizeof(struct Person *) * 3);
    pArr = allocateSpace();
    printPerson(pArr, 3);
    //释放堆区数据
    freeSpace(pArr, 3);
    pArr = NULL;
}

int main()
{
    srand((unsigned int)time(NULL));
    test01();
    return 0;
}