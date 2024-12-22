#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 节点结构体
struct LinkNode
{
    // 数据域
    void *data;
    // 指针域
    struct LinkNode *next;
};

// 链表结构体
struct LList
{
    struct LinkNode pHeader; // 头节点
    int m_Size;              // 链表长度
};

// void *别名
typedef void *LinkList;

// 初始化链表
LinkList init_LinkList()
{
    // 分配内存
    struct LList *mylist = (struct LList *)malloc(sizeof(struct LList));
    if (mylist == NULL)
    {
        return NULL;
    }
    // 头节点初始化
    mylist->pHeader.data = NULL;
    mylist->pHeader.next = NULL;
    mylist->m_Size = 0;

    return mylist;
}

// 插入一个节点
void insert_LinkList(LinkList list, int pos, void *data)
{
    if (list == NULL)
    {
        return;
    }
    if (data == NULL)
    {
        return;
    }
    struct LList *mylist = (struct LList *)list;
    if (pos < 0 || pos > mylist->m_Size)
    {
        // 无效位置
        pos = mylist->m_Size;
    }
    struct LinkNode *pCurrent = &mylist->pHeader;
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    struct LinkNode *newnode = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    newnode->data = data;
    newnode->next = NULL;
    // 建立节点之间的关系
    newnode->next = pCurrent->next;
    pCurrent->next = newnode;

    // 更新链表长度
    mylist->m_Size++;
}

// 遍历链表
void foreach_LinkList(LinkList list, void (*myPrint)(void *))
{
    if (list == NULL)
    {
        return;
    }
    struct LList *mylist = (struct LList *)list;
    struct LinkNode *pCurrent = mylist->pHeader.next;

    for (int i = 0; i < mylist->m_Size; i++)
    {
        // 回调函数
        myPrint(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

// 删除链表某节点
void removeByPos_LinkNode(LinkList list, int pos)
{
    if (list == NULL)
    {
        return;
    }

    struct LList *mylist = (struct LList *)list;
    if (pos < 0 || pos >= mylist->m_Size)
    {
        // 无效位置
        return;
    }

    struct LinkNode *pCurrent = &mylist->pHeader;

    // 找到要删除的节点的前一个节点
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }

    struct LinkNode *pDel = pCurrent->next; // 要删除的节点
    pCurrent->next = pDel->next;            // 删除操作        
    free(pDel);                             // 释放节点内存

    // 更新链表长度
    mylist->m_Size--;
}
//删除链表，按值删除
void removeByValue_LinkNode(LinkList list, void *data, int (*myCompare)(void *, void *))
{
    if (list == NULL)
    {
        return;
    }
    struct LList *mylist = (struct LList *)list;
    struct LinkNode *pCurrent = &mylist->pHeader;

    while (pCurrent->next!= NULL)
    {
        if (myCompare(pCurrent->next->data, data) == 0)
        {
            struct LinkNode *pDel = pCurrent->next;
            pCurrent->next = pDel->next;
            free(pDel);
            pDel = NULL;

            mylist->m_Size--;
        }
        else
        {
            pCurrent = pCurrent->next;
        }
    }

}
// // 释放链表内存
// void free_LinkList(LinkList list)
// {
//     if (list == NULL)
//     {
//         return;
//     }
//     struct LList *mylist = (struct LList *)list;
//     struct LinkNode *pCurrent = mylist->pHeader.next;
//     while (pCurrent != NULL) // 遍历剩余节点
//     {
//         struct LinkNode *toFree = pCurrent;
//         pCurrent = pCurrent->next;
//         free(toFree);       // 释放节点本身
//     }
//     free(mylist); // 释放链表结构本身
// }

// 定义人员结构
struct Person
{
    char name[64];
    int age;
};
//返回链表长度
int getSize_LinkList(LinkList list)
{
    if (list == NULL)
    {
        return 0;
    }
    struct LList *mylist = (struct LList *)list;
    return mylist->m_Size;
}
//清空链表
void clear_LinkList(LinkList list)
{
    if (list == NULL)
    {
        return;
    }
    struct LList *mylist = (struct LList *)list;
    struct LinkNode *pCurrent = mylist->pHeader.next;
    while (pCurrent!= NULL) // 遍历剩余节点
    {
        struct LinkNode *toFree = pCurrent;
        pCurrent = pCurrent->next;
        free(toFree);       // 释放节点本身
    }
    mylist->pHeader.next = NULL;
    mylist->m_Size = 0;
}
//销毁链表
void destroy_LinkList(LinkList list)
{
    if (list == NULL)
    {
        return;
    }
    clear_LinkList(list);
    free(list); // 释放链表结构本身
    list = NULL;
}


// 回调打印函数
void printPerson(void *data)
{
    struct Person *person = (struct Person *)data;
    printf("姓名：%s 年龄：%d\n", person->name, person->age);
}
int comparePerson(void *data1, void *data2)
{
    struct Person *person1 = (struct Person *)data1;
    struct Person *person2 = (struct Person *)data2;
    return strcmp(person1->name, person2->name);
}
void test01()
{
    // 初始化链表
    LinkList mylist = init_LinkList();

    struct Person p1 = {"张三", 18};
    struct Person p2 = {"李四", 19};
    struct Person p3 = {"王五", 20};
    struct Person p4 = {"赵六", 21};
    struct Person p5 = {"田七", 22};
    struct Person p6 = {"高老八", 23};

    insert_LinkList(mylist, 0, &p1);
    insert_LinkList(mylist, 0, &p2);
    insert_LinkList(mylist, 1, &p3);
    insert_LinkList(mylist, -1, &p4);
    insert_LinkList(mylist, 1, &p5);
    insert_LinkList(mylist, 100, &p6); // 插入到末尾

    // 遍历链表
    foreach_LinkList(mylist, printPerson);

    printf("------------------------------\n");

    // 删除链表某节点
    removeByPos_LinkNode(mylist, 4);
    // 遍历链表
    foreach_LinkList(mylist, printPerson);

    printf("------------------------------\n");
    struct Person p = {"王五", 20};
    removeByValue_LinkNode(mylist, &p, comparePerson);
    // 遍历链表
    foreach_LinkList(mylist, printPerson);

    printf("------------------------------\n");
    // 清空链表
    clear_LinkList(mylist);
    // 遍历链表
    foreach_LinkList(mylist, printPerson);

    printf("------------------------------\n");
    //销毁链表
    destroy_LinkList(mylist);
    mylist = NULL;
    printf("链表长度：%d\n", getSize_LinkList(mylist));

    // 释放链表内存
    //free_LinkList(mylist);
}

int main()
{
    test01();
    return 0;
}