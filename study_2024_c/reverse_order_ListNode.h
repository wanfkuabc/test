#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 节点设计
struct ListNode
{
    // 数据域
    int data;
    // 指针域
    struct ListNode *next;
};

// 初始化链表
struct ListNode *initListNode();

//遍历链表
void printListNode(struct ListNode *head);

//链表反转
struct ListNode *reverseListNode(struct ListNode *head);