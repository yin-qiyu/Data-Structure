/*
 * @Author: yin-qiyu
 * @Date: 2022-09-01 12:09:34
 * @LastEditTime: 2022-09-01 14:38:47
 * @Description: 链栈的基本操作  栈顶在链头，栈顶在链尾
 */

#include <iostream>
#include <vector>
using namespace std;

//-----start栈顶在链头-----
//单链表实现
typedef struct SNode{			//定义单链表结点类型
    int data;				        //每个节点存放一个数据元素
    struct SNode *next;			//指针指向下一个节点
}SNode, *LiStack;


//初始化一个链栈（单链表实现，栈顶在链头）
bool InitStack(LiStack &S) {
    S = (SNode *) malloc(sizeof(SNode)); //分配一个头结点
    S->next = NULL;         //头结点之后暂时还没有节点
    return true;
}


//判断栈是否为空
bool(LiStack s){
    if(s->next == NULL)
        return true;
    else
        return false;
}

//入栈（本质上是单链表的“头插法”）
bool Push (LiStack &S, int x){
    SNode * p = (SNode *) malloc(sizeof(SNode));    //新分配一个结点
    p->data = x;     //存入新元素
    p->next = S->next;
    S->next = p;     //新结点插入到头结点后面
    return true;
}

//出栈
bool Pop (LiStack &S, int &x){
    if (StackEmpty(S))      //栈空，出栈操作失败
        return false;

    SNode * p = S->next;     //栈不空，链头结点出栈
    x = p->data;             //x返回栈顶元素
    S->next = p->next;       //头删法，栈顶元素"断链"
    free(p);                 //释放结点
    return true;
}

//-----end栈顶在链头-----


//-----start栈顶在链尾-----
//双链表实现
typedef struct DBNode
{
    /* data */
};
//初始化一个链栈（单链表实现，栈顶在链头
//判断栈是否为空
//入栈（在双链表链尾插入）
//出栈（删除双链表链尾元素）


//-----end栈顶在链尾-----