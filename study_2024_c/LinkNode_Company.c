#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 节点结构体
struct ListNode
{
    // 指针域
    struct ListNode *next;
};
//链表结构体
struct LinkNode
{
    // 头指针
    struct ListNode *head;
    // 链表大小
    int m_size;
};

typedef void *LinkList;

struct Person
{
    // struct ListNode node;
    int *a;
    char name[64];
    int age;
};
// 初始化链表
LinkList init_LinkList()
{
    // 申请链表结构体空间
    struct LinkNode *pLinkList = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    if (pLinkList == NULL)
    {
        printf("申请链表结构体空间失败\n");
        return NULL;
    }
    // 头指针初始化
    pLinkList->head = NULL;
    // 链表大小初始化
    pLinkList->m_size = 0;
    return pLinkList;
}

//插入链表
void insert_LinkList(LinkList pLinkList, int index, void *data)
{
    if (pLinkList == NULL)
    {
        return;
    }
    if (data == NULL)
    {
        return;
    }
    struct LinkNode *mylist = (struct LinkNode *)pLinkList;
    if (index < 0 || index > mylist->m_size-1)
    {
        index=mylist->m_size;

    }
    struct ListNode *myNode = (struct ListNode *)data;
    struct ListNode *pCurrent =(struct ListNode *) &mylist->head;
    for (int i = 0;i<index;i++)
    {
        pCurrent = pCurrent->next;
    }
    myNode->next = pCurrent->next;
    pCurrent->next = myNode;
    mylist->m_size++;
}
// 遍历链表
void foreach_LinkList(LinkList pLinkList, void (*myPrint)(void *))
{
    if (pLinkList == NULL)
    {
        return;
    }
    if (myPrint == NULL)
    {
        return;
    }
    struct LinkNode *mylist = (struct LinkNode *)pLinkList;
    struct ListNode *pCurrent = mylist->head;
    for (int i = 0; i < mylist->m_size; i++)
    {
        myPrint(pCurrent);
        pCurrent = pCurrent->next;
    }
}
//删除 按位置
void delete_LinkList(LinkList pLinkList, int index)
{
    if (pLinkList == NULL)
    {
        return;
    }
    struct LinkNode *mylist = (struct LinkNode *)pLinkList;
    if (index < 0 || index > mylist->m_size - 1)
    {
        return;
    }
    struct ListNode *pCurrent = mylist->head;
    for (int i = 0; i < index; i++)
    {
        pCurrent = pCurrent->next;
    }
    struct ListNode *pNext = pCurrent->next;
    pCurrent->next = pNext->next;
    //free(pNext);
    mylist->m_size--;

}
//删除按值
void removeByValue_LinkList(LinkList list,void *data,int(*compare)(void*,void *))
{
    if(list==NULL)
    {
        return;
    }
    if(data==NULL)
    {
        return;
    }
    struct LinkNode *mylist = (struct LinkNode *)list;
    struct ListNode *pCurrent = mylist->head;
    for (int i = 0; i < mylist->m_size; i++)
    {
        if(compare(pCurrent->next,data)==0)
        {
            struct ListNode *pNext = pCurrent->next;
            pCurrent->next = pNext->next;
            //free(pNext);
            mylist->m_size--;
        }
        pCurrent = pCurrent->next;
    }

}
//回调函数
int compare(void *data1, void *data2)
{
    struct Person *p1 = (struct Person *)data1;
    struct Person *p2 = (struct Person *)data2;
    return strcmp(p1->name, p2->name);
}

//销毁链表
void destory_LinkList(LinkList pLinkList)
{
    if (pLinkList == NULL)
    {
        return;
    }
    struct LinkNode *mylist = (struct LinkNode *)pLinkList;
    struct ListNode *pCurrent = mylist->head;
    for (int i = 0; i < mylist->m_size; i++)
    {
        struct ListNode *pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
    free(mylist);
    mylist = NULL;
}

//回调函数打印
void myPrint(void *data)
{
    struct Person *p = (struct Person *)data;
    printf("name=%s age=%d\n", p->name, p->age);
}

void test01()
{
    // 初始化链表
    LinkList pLinkList = init_LinkList();

    // 创建节点
    struct Person p1 = {NULL,"aaa", 10};
    struct Person p2 = {NULL,"bbb", 20};
    struct Person p3 = {NULL,"ccc", 30};
    struct Person p4 = {NULL,"ddd", 40};
    struct Person p5 = {NULL,"eee", 50};

    //插入数据
    insert_LinkList(pLinkList, 0, &p1);
    insert_LinkList(pLinkList, 0, &p2);
    insert_LinkList(pLinkList, 1, &p3);
    insert_LinkList(pLinkList, -1, &p4);
    insert_LinkList(pLinkList, 0, &p5);

    foreach_LinkList(pLinkList, myPrint);

    //删除bbb
    printf("----------------------\n");
    delete_LinkList(pLinkList, 0);
    foreach_LinkList(pLinkList, myPrint);

    //按值删除
    printf("----------------------\n");
    struct Person p = {NULL, "ddd", 40};
    removeByValue_LinkList(pLinkList, &p, compare);
    foreach_LinkList(pLinkList, myPrint);

    //销毁链表
    //destory_LinkList(pLinkList);
    printf("----------------------\n");

    // 遍历链表
    foreach_LinkList(pLinkList, myPrint);
}


int main()
{
    test01();
    return 0;
}