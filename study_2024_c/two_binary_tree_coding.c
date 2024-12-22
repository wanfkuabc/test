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
};
//统计叶子数量
void calculateLeafNum(struct BinaryNode *root, int *num)
{
    if (root == NULL)
    {
        return;
    }
    if (root->lChild == NULL && root->rChild == NULL)
    {
        (*num)++;
    }
    calculateLeafNum(root->lChild, num);
    calculateLeafNum(root->rChild, num);
}
// 求二叉树的高度
int getTreeHeight(struct BinaryNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = getTreeHeight(root->lChild);
    int rightHeight = getTreeHeight(root->rChild);
    return leftHeight > rightHeight? leftHeight + 1 : rightHeight + 1;
}
// 拷贝二叉树
struct BinaryNode *copyTree(struct BinaryNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    // 创建新节点
    struct BinaryNode *newNode = (struct BinaryNode *)malloc(sizeof(struct BinaryNode));
    //先拷贝左子树
    newNode->lChild = copyTree(root->lChild);
    //再拷贝右子树
    newNode->rChild = copyTree(root->rChild);
    //将拷贝的左右子树放到新节点上
    newNode->lChild = copyTree(root->lChild);
    newNode->rChild = copyTree(root->rChild);
    newNode->ch = root->ch;
    
    
    return newNode;
}
// 递归函数
void recursion(struct BinaryNode *root)
{
    if (root == NULL)
    {
        return;
    }
    // 前序遍历
    // 先根
    printf("%c ", root->ch);
    // 再左
    recursion(root->lChild);

    // 再右
    recursion(root->rChild);
    
}
//释放树
void freeTree(struct BinaryNode *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->lChild);
    freeTree(root->rChild);
    //free(root);
}


void test01()
{
    // 创建节点
    struct BinaryNode nodeA = {'A', NULL, NULL};
    struct BinaryNode nodeB = {'B', NULL, NULL};
    struct BinaryNode nodeC = {'C', NULL, NULL};
    struct BinaryNode nodeD = {'D', NULL, NULL};
    struct BinaryNode nodeE = {'E', NULL, NULL};
    struct BinaryNode nodeF = {'F', NULL, NULL};
    struct BinaryNode nodeG = {'G', NULL, NULL};
    struct BinaryNode nodeH = {'H', NULL, NULL};

    // 建立关系
    nodeA.lChild = &nodeB;
    nodeA.rChild = &nodeF;

    nodeB.rChild = &nodeC;

    nodeC.lChild = &nodeD;
    nodeC.rChild = &nodeE;

    nodeF.rChild = &nodeG;

    nodeG.lChild = &nodeH;

    //统计二叉树的叶子数量
    int num = 0;
    calculateLeafNum(&nodeA, &num);
    printf("二叉树的叶子数量为：%d\n", num);

    //求二叉树的高度
    int height = getTreeHeight(&nodeA);
    printf("二叉树的高度为：%d\n", height);

    //拷贝二叉树
    struct BinaryNode *copyTree(struct BinaryNode * root);
    //递归
    recursion(&nodeA);

    //释放树
    freeTree(&nodeA);
    printf("释放树成功\n");
}

int main()
{
    test01();
    return EXIT_SUCCESS;
}
