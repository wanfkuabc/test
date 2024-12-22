#include "listNode2.h"

// 函数返回值是创建好的链表头节点
struct ListNode *init_ListNode()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(head==NULL)
    {
        return NULL;
    }
    //头节点不维护数据域
    head->num = -1;
    head->next = NULL;
    //创建尾节点指针，用于记录链表尾部节点位置，尾插
    struct ListNode *tail = head;
    
    while(1)
    {
        printf("请输入要插入的节点数据,输入-1结束插入\n");
        int data = 0;
        scanf("%d", &data);
        if(data==-1)
        {
            break;
        }

        //创建新节点
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->num = data;
        newNode->next = NULL;
        //更新节点指向
        tail->next = newNode;
        //更新尾节点位置
        tail = newNode;
    }

    return head;
}

// 遍历链表
void foreach_ListNode(struct ListNode *head)
{
    if (head==NULL)
    {
        return;
    }
    //当前节点指向第一个真实数据节点
    struct ListNode *p = head->next;
    while(p!=NULL)
    {
        printf("%d\n ", p->num);
        p = p->next;
    }
}
// 插入节点功能
void insert_ListNode(struct ListNode *head, int oldVal, int newVal)
{
    if(head==NULL)
    {
        return;
    }
    //创建两个临时指针插入
    struct ListNode *pPrev = head;
    struct ListNode *pCurrent = head->next;
    while(pCurrent!=NULL)
    {
        if(pCurrent->num==oldVal)
        {
            break;
        }
        //两个辅助指针后移
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }
    //创建新节点
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->num = newVal;
    newNode->next = NULL;
    //插入节点
    pPrev->next = newNode;
    newNode->next = pCurrent;  
}
// 删除节点
void delete_ListNode(struct ListNode *head, int delval)
{
    if(head==NULL)
    {
        return;
    }
    //创建两个临时指针插入
    struct ListNode *pPrev = head;
    struct ListNode *pCurrent = head->next;
    while(pCurrent!=NULL)
    {
        if(pCurrent->num==delval)
        {
            break;
        }
        //两个辅助指针后移
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }
    if (pCurrent==NULL)
    {
       // 没有找到要删除的节点
       return;
    }
    pPrev->next = pCurrent->next;

    free(pCurrent);
    pCurrent = NULL;
}
// 清空节点
void clear_ListNode(struct ListNode *head)
{
    if(head==NULL)
    {
        return;
    }
    //创建临时指针
    struct ListNode *pCurrent = head->next;
    while(pCurrent!=NULL)
    {
        //保存下一个节点位置
        struct ListNode *pNext = pCurrent->next;
        //释放当前节点
        free(pCurrent);
        //更新当前节点位置
        pCurrent = pNext;
    }
    head->next = NULL;
}
// 销毁节点
void destroy_ListNode(struct ListNode *head)
{
    if(head==NULL)
    {
        return;
    }
    //清空节点
    clear_ListNode(head);

    //释放头节点
    free(head);
    head = NULL;
}

// 反转列表
void reverse_ListNode(struct ListNode *head)
{   
    if(head==NULL)
    {
        return;
    }
    //创建三个临时指针
    struct ListNode *pPrev = NULL;
    struct ListNode *pCurrent = head->next;
    struct ListNode *pNext = NULL;
    while(pCurrent!=NULL)
    {
        //保存下一个节点位置
        pNext = pCurrent->next;
        //更新当前节点指向
        pCurrent->next = pPrev;
        //更新三个指针位置
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    //更新头节点指向
    head->next = pPrev;
}

// 统计链表个数
int count_ListNode(struct ListNode *head)
{
    if(head==NULL)
    {
        return 0;
    }
    //创建临时指针
    struct ListNode *pCurrent = head->next;
    int count = 0;
    while(pCurrent!=NULL)
    {
        count++;
        pCurrent = pCurrent->next;
    }
    return count;
}