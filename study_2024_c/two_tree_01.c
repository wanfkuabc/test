#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//二叉树节点
struct BinaryNode
{
    char ch;

    struct BinaryNode *lChild;//左孩子

    struct BinaryNode *rChild;//右孩子
};
//递归函数
void recursion(struct BinaryNode *root)
{
    if(root==NULL)
    {
        return;
    }
    //前序遍历
    //再左
    recursion(root->lChild);
    
    //再右
    recursion(root->rChild);
    // 先根
    printf("%c ", root->ch);
}

void test01()
{
    //创建节点
    struct BinaryNode nodeA={'A',NULL,NULL};
    struct BinaryNode nodeB={'B',NULL,NULL};
    struct BinaryNode nodeC={'C',NULL,NULL};
    struct BinaryNode nodeD={'D',NULL,NULL};
    struct BinaryNode nodeE={'E',NULL,NULL};
    struct BinaryNode nodeF={'F',NULL,NULL};
    struct BinaryNode nodeG={'G',NULL,NULL};
    struct BinaryNode nodeH={'H',NULL,NULL};

    //建立关系
    nodeA.lChild=&nodeB;
    nodeA.rChild=&nodeF;

    nodeB.rChild=&nodeC;

    nodeC.lChild=&nodeD;
    nodeC.rChild=&nodeE;

    nodeF.rChild=&nodeG;

    nodeG.lChild=&nodeH;

    //通过递归函数实现遍历二叉树
    recursion(&nodeA);
}

int main()
{
    test01();
    return 0;
}