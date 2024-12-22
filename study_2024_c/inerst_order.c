#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//插入排序
void insertSort(int arr[], int len)
{
    for (int i = 1; i < len;i++)
    {
        if(arr[i]<arr[i-1])
        {
            int temp = arr[i];
            int j = i - 1;
            for (; j >= 0 && temp < arr[j]; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;

        }
    }
}


void test01()
{
    int arr[] = {1, 4, 5, 3, 2};
    int len = sizeof(arr) / sizeof(arr[0]);

    insertSort(arr, len);

    // 打印排序后的数组
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    test01();
    return 0;
}