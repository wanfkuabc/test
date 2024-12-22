#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(void *arr, int eleSize,int len,int (*cmp)(void *,void *))

{
    char *tmp = (char *)malloc(eleSize);
    for (int i = 0; i < len; i++)
    {
        int min = i;
        for (int j = i+1; j < len; j++)
        {
            //获取j元素首地址
            char *pJ = (char *)arr+j*eleSize;
            //获取min元素首地址
            char *pMin = (char *)arr+min*eleSize;
            //比较两个元素大小
            if (cmp(pJ,pMin))
            {
                min = j;
            }
        }
        if (min!=i)
        {
            //交换元素
            
            memcpy(tmp,(char *)arr+min*eleSize,eleSize);
            memcpy((char *)arr+min*eleSize,(char *)arr+i*eleSize,eleSize);
            memcpy((char *)arr+i*eleSize,tmp,eleSize);
        }
    }
    if(tmp!=NULL)
    {
        free(tmp);
        tmp = NULL;
    }
}
int cmp(void *p1,void *p2)
{
    int *a = (int *)p1;
    int *b = (int *)p2;

    if(*a<*b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void test01()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, sizeof(int), len, cmp);

    for (int i = 0; i < len; i++)
    {
        printf("%d\n",arr[i]);
    }
}
//结构体数组排列
struct Person
{
    char name[64];
    int age;
};
//按照年龄降序排列
int comparePerson(void *date1,void *date2)
{
    struct Person *p1 = (struct Person *)date1;
    struct Person *p2 = (struct Person *)date2;

    return p1->age<p2->age;
}
void test02()
{
    struct Person arr[]={
        {"zhangsan",21},
        {"lisi",20},
        {"wangwu",30},
        {"zhaoliu",40},
    };
    int len = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, sizeof(struct Person), len, comparePerson);

    for (int i = 0; i < len; i++)
    {
        printf("name=%s,age=%d\n",arr[i].name,arr[i].age);
    }
}
int main()
{
    //test01();
    test02();
    return 0;
}