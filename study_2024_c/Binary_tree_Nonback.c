#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 二叉树节点
struct BinaryNode
{
    char ch;

    struct BinaryNode *lChild; // 左孩子

    struct BinaryNode *rChild; // 右孩子

    int flag;//标志
};
// 非递归遍历
void nonrecursion(struct BinaryNode *root)
{
    struct BinaryNode *stack[100];
    int top = -1;
    struct BinaryNode *p = root;
    while (p!= NULL || top!= -1)
    {
        while (p!= NULL)
        {
            stack[++top] = p;
            p = p->lChild;
        }
        if (top!= -1)
        {
            p = stack[top--];
            printf("%c ", p->ch);
            p = p->rChild;
        }
    }
}


void test01()
{
    // 创建节点
    struct BinaryNode nodeH = {'H', NULL, NULL,0};
    struct BinaryNode nodeA = {'A', NULL, NULL,0};
    struct BinaryNode nodeB = {'B', NULL, NULL,0};
    struct BinaryNode nodeC = {'C', NULL, NULL,0};
    struct BinaryNode nodeD = {'D', NULL, NULL,0};
    struct BinaryNode nodeE = {'E', NULL, NULL,0};
    struct BinaryNode nodeF = {'F', NULL, NULL,0};
    struct BinaryNode nodeG = {'G', NULL, NULL,0};

    // 建立关系
    nodeA.lChild = &nodeB;
    nodeA.rChild = &nodeF;

    nodeB.rChild = &nodeC;

    nodeC.lChild = &nodeD;
    nodeC.rChild = &nodeE;

    nodeF.rChild = &nodeG;

    nodeG.lChild = &nodeH;

    //非递归遍历
    nonrecursion(&nodeA);
}

int main()
{
    test01();
    return 0;
}