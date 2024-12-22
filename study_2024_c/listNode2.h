#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//节点结构体
struct ListNode
{
    //数据域
    int num;
    //指针域
    struct ListNode* next;
};

//初始化链表
//函数返回值是创建好的链表头节点
struct ListNode *init_ListNode();

//遍历链表
void foreach_ListNode(struct ListNode *head);

//插入节点功能
void insert_ListNode(struct ListNode *head, int oldVal, int newVal);

//删除节点
void delete_ListNode(struct ListNode *head, int delval);

//清空节点
void clear_ListNode(struct ListNode *head);

//销毁节点
void destroy_ListNode(struct ListNode *head);

//反转列表
void reverse_ListNode(struct ListNode *head);

//统计链表个数
int count_ListNode(struct ListNode *head);