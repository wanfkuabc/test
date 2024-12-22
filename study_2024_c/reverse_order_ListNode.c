#include"reverse_order_ListNode.h"

struct ListNode *init_ListNode()
{
    struct ListNode *head= (struct ListNode *)malloc(sizeof(struct ListNode));
    if(head==NULL)
    {
        return NULL;
    }
    head->data = -1;
    head->next=NULL;
    while(1)
    {
        printf("请输入要插入的节点数据,输入-1结束插入\n");
        int data = 0;
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        struct ListNode *newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
        newnode->data = data;
        newnode->next = head->next;
        head->next = newnode;
    }
    return head;
}
// 遍历链表
void printListNode(struct ListNode *head)
{
    if(head==NULL)
    {
        return;
    }
    struct ListNode *p = head->next;
    while(p!=NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
// 链表反转
struct ListNode *reverseListNode(struct ListNode *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    struct ListNode *pCurrent = head->next;
    struct ListNode *qPre = NULL;
    while(pCurrent!=NULL)
    {
        struct ListNode *pNext = pCurrent->next;
        pCurrent->next = qPre;
        qPre = pCurrent;
        pCurrent = pNext;
    }

}

int main()
{
    struct ListNode *head = init_ListNode();
    reverseListNode(head);
    printListNode(head);
   

    return 0;
}