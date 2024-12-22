#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 动态数组结构体
struct dynamicArray
{
    // 真实在堆区开辟数组的指针
    void **pArray;
    // 数组容量
    int m_capacity;
    // 数组大小
    int m_size;
};

// 初始化数组        参数一： 数组容量  返回值： 数组指针
struct dynamicArray *init_dynamicArray(int capacity)
{
    if (capacity <= 0)
    {
        printf("数组容量不能小于等于0\n");
        return NULL;
    }
    // 申请数组结构体空间
    struct dynamicArray *pArr = (struct dynamicArray *)malloc(sizeof(struct dynamicArray));
    if (pArr == NULL)
    {
        printf("申请数组结构体空间失败\n");
        return NULL;
    }
    // 申请数组空间
    pArr->pArray = (void **)malloc(sizeof(void *) * capacity);
    // 容量初始化
    pArr->m_capacity = capacity;
    // 大小初始化
    pArr->m_size = 0;

    if (pArr->pArray == NULL)
    {
        printf("申请数组空间失败\n");
        return NULL;
    }
}

// 插入元素
void insert_dynamicArray(struct dynamicArray *pArr, int index, void *data)
{
    if (pArr == NULL)
    {
        return;
    }
    if (data == NULL)
    {
        return;
    }
    if (index < 0 || index > pArr->m_size)
    {
        return;
    }

    // 判断数组是否满了
    if (pArr->m_size == pArr->m_capacity)
    {
        // 数组满了，需要扩容
        // 申请新的数组空间
        void **newArray = (void **)malloc(sizeof(void *) * (pArr->m_capacity * 2));
        if (newArray == NULL)
        {
            printf("申请新的数组空间失败\n");
            return;
        }
        // 将旧数组中的数据拷贝到新数组中
        memcpy(newArray, pArr->pArray, sizeof(void *) * pArr->m_capacity);
        // 释放旧数组空间
        free(pArr->pArray);
        // 更新数组指针
        pArr->pArray = newArray;
        // 更新数组容量
        pArr->m_capacity = pArr->m_capacity * 2;
    }
    // 将新的元素插入到指定位置
    // 将index位置后面的元素向后移动
    for (int i = pArr->m_size - 1; i >= index; i--)
    {
        pArr->pArray[i + 1] = pArr->pArray[i];
    }
    // 将新的元素插入到指定位置
    pArr->pArray[index] = data;
    // 更新数组大小
    pArr->m_size++;
}

// 遍历数组
void foreach_dynamicArray(struct dynamicArray *pArr, void (*print)(void *))
{
    if (pArr == NULL)
    {
        return;
    }
    for (int i = 0; i < pArr->m_size; i++)
    {
        print(pArr->pArray[i]);
    }
}
struct Person
{
    char name[64];
    int age;
};

// 回调函数打印数据
void printPerson(void *data)
{
    struct Person *person = (struct Person *)data;
    printf("姓名： %s  年龄： %d\n", person->name, person->age);
}
void test01()
{
    struct dynamicArray *pArr = init_dynamicArray(5);
    // 插入元素
    struct Person p1 = {"张三", 18};
    struct Person p2 = {"李四", 19};
    struct Person p3 = {"王五", 20};
    struct Person p4 = {"赵六", 21};
    struct Person p5 = {"田七", 22};
    struct Person p6 = {"高老八", 23};

    printf("插入数据前---数组容量： %d\n", pArr->m_capacity);
    printf("插入数据前---数组大小： %d\n", pArr->m_size);

    // 插入数据
    insert_dynamicArray(pArr, 0, &p1);
    insert_dynamicArray(pArr, 1, &p2);
    insert_dynamicArray(pArr, 2, &p3);
    insert_dynamicArray(pArr, 3, &p4);
    insert_dynamicArray(pArr, 4, &p5);
    insert_dynamicArray(pArr, 5, &p6);

    // 遍历数组
    foreach_dynamicArray(pArr, printPerson);
    printf("插入数据后---数组容量： %d\n", pArr->m_capacity);
    printf("插入数据后---数组大小： %d\n", pArr->m_size);
}

int main()
{
    test01();
    return 0;
}