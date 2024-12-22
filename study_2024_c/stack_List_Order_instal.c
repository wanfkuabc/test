#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct LinkNode
{
    //只维护指针域
    struct LinkNode *next;
};

struct LStack
{
    struct LinkNode *pHeader;
    int m_size;
};

typedef void *LinkStack;
struct Person
{
    // struct ListNode node;
    int *a;
    char name[64];
    int age;
};
//初始化
LinkStack init_LinkStack()
{
    struct LStack *stack = (struct LStack *)malloc(sizeof(struct LStack));
    if(stack==NULL)
    {
        printf("申请栈空间失败\n");
        return NULL;
    }
    stack->pHeader = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    if(stack->pHeader==NULL)
    {
        printf("申请栈空间失败\n");
        return NULL;
    }
    stack->pHeader->next = NULL;
    stack->m_size = 0;
    return stack;
}
//入账
void push_LinkStack(LinkStack stack,void *data)
{
    if(stack==NULL)
    {
        return;
    }
    if(data==NULL)
    {
        return;
    }
    struct LStack *mystack = (struct LStack *)stack;
    struct LinkNode *myNode = (struct LinkNode *)data;
    if (myNode == NULL)
    {
        printf("申请栈空间失败\n");
        return;
    }
    myNode->next = mystack->pHeader->next;
    mystack->pHeader->next = myNode;
    mystack->m_size++;
   
}

//出栈
void pop_LinkStack(LinkStack stack)
{
    if(stack==NULL)
    {
        return;
    }
    struct LStack *mystack = (struct LStack *)stack;
    if(mystack->m_size==0)
    {
        printf("栈为空\n");
        return;
    }
    struct LinkNode *pNext = mystack->pHeader->next;

    mystack->pHeader->next = pNext->next;

    mystack->m_size--;
}

//返回栈顶
void* top_LinkStack(LinkStack stack)
{
    if(stack==NULL)
    {
        return NULL;
    }
    struct LStack *mystack = (struct LStack *)stack;
    if(mystack->m_size==0)
    {
        printf("栈为空\n");
        return NULL;
    }
    struct LinkNode *pNext = mystack->pHeader->next;
    return pNext;
}

//返回栈大小
int size_LinkStack(LinkStack stack)
{
    if (stack==NULL)

    {
        return -1;
    }
    struct LStack *mystack = (struct LStack *)stack;
    return mystack->m_size;
    
}

//判断栈是否为空
int is_empty_LinkStack(LinkStack stack)
{
    if(stack==NULL)
    {
        return -1;
    }
    struct LStack *mystack = (struct LStack *)stack;
    if(mystack->m_size==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//销毁栈
void destory_LinkStack(LinkStack stack)
{
    if(stack==NULL)
    {
        return;
    }
    free(stack);
    stack = NULL;
}


void test01()
{
    //初始化栈
    LinkStack myStack = init_LinkStack();

    // 创建节点
    struct Person p1 = {NULL, "aaa", 10};
    struct Person p2 = {NULL, "bbb", 20};
    struct Person p3 = {NULL, "ccc", 30};
    struct Person p4 = {NULL, "ddd", 40};
    struct Person p5 = {NULL, "eee", 50};

    // 入栈
    push_LinkStack(myStack, &p1);
    push_LinkStack(myStack, &p2);
    push_LinkStack(myStack, &p3);
    push_LinkStack(myStack, &p4);
    push_LinkStack(myStack, &p5);

    printf("栈的大小为： %d\n", size_LinkStack(myStack));

    while (is_empty_LinkStack(myStack) == 0)
    {
        // 返回栈顶
        struct Person *pTop = (struct Person *)top_LinkStack(myStack);
        printf("姓名： %s  年龄： %d\n", pTop->name, pTop->age);
        // 出栈
        pop_LinkStack(myStack);
    }
    printf("栈的大小为： %d\n", size_LinkStack(myStack));
}


int main()
{
    test01();
    return 0;

}