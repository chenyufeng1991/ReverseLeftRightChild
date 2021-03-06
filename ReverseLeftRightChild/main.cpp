//
//  main.cpp
//  ReverseLeftRightChild
//
//  Created by chenyufeng on 10/1/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct BTNode{
    int data;
    struct BTNode *lChild;
    struct BTNode *rChild;
}BiTNode;

//先序创建二叉树
int CreateBiTree(BiTNode **T)
{
    int ch;
    cin >> ch;
    if (ch == -1)
    {
        *T = NULL;
        return 0;
    }
    else
    {
        *T = new BiTNode;
        if (T == NULL)
        {
            cout << "failed" << endl;
            return 0;
        }
        else
        {
            (*T)->data = ch;
            cout << "输入" << ch << "的左子节点:";
            CreateBiTree(&((*T)->lChild));
            cout << "输入" << ch << "的右子节点:";
            CreateBiTree((&(*T)->rChild));
        }
    }

    return 1;
}

//先序遍历二叉树
void PreOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        cout << T->data << " ";
        PreOrderBiTree(T->lChild);
        PreOrderBiTree(T->rChild);
    }
}

//中序遍历二叉树
void MiddleOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        MiddleOrderBiTree(T->lChild);
        cout << T->data << " ";
        MiddleOrderBiTree(T->rChild);
    }
}

//后续遍历二叉树
void PostOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        PostOrderBiTree(T->lChild);
        PostOrderBiTree(T->rChild);
        cout << T->data << " ";
    }
}

// 交换左右子树
void ReverseLeftRightChild(BiTNode **T)
{
    // 如果是叶子节点，则递归结束
    if (*T == NULL)
    {
        return;
    }

    swap((*T)->lChild, (*T)->rChild); // 直接使用swap交换函数比较方便，直接交换指针；
    ReverseLeftRightChild(&((*T)->lChild));
    ReverseLeftRightChild(&((*T)->rChild));
}

int main(int argc, const char * argv[])
{
    BiTNode *T;
    cout << "请输入第一个节点的值，-1表示没有叶节点：" << endl;
    CreateBiTree(&T);

    cout << "先序遍历二叉树：";
    PreOrderBiTree(T);
    cout << endl;

    ReverseLeftRightChild(&T);
    cout << "交换左右子树后,先序遍历二叉树：";
    PreOrderBiTree(T);
    cout << endl;

    cout << "交换左右子树后,中序遍历二叉树：";
    MiddleOrderBiTree(T);
    cout << endl;

    cout << "交换左右子树后，后续遍历二叉树：" ;
    PostOrderBiTree(T);
    cout << endl;

    return 0;
}
