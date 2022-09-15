/*
 * @Author: yin-qiyu
 * @Date: 2022-09-15 23:14:51
 * @LastEditTime: 2022-09-15 23:20:36
 * @Description: 链栈 双链表 实现，栈顶在链尾
 */

#include <iostream>
#include <vector>
using namespace std;


//-----start栈顶在链尾-----
//定义栈结点
typedef struct DbSNode{			    //定义双链表结点类型
    int data;				        //每个节点存放一个数据元素
    struct DbSNode *last,*next;	    //指向前后两个结点
}DbSNode;

typedef struct DbLiStack{	        //双链表实现的栈（栈顶在链尾）
    struct DbSNode *head, *rear;    //两个指针，分别指向链头、链尾
}DbLiStack, *DbStack;

//初始化一个链栈（单链表实现，栈顶在链头）
bool InitDbStack(DbStack &S) {
    S = (DbLiStack *) malloc(sizeof(DbLiStack));    //初始化一个链栈（双链表实现，栈顶在链尾）
    DbSNode * p = (DbSNode *) malloc(sizeof(DbSNode)); //新建一个头结点
    p->next = NULL;         //头结点之后暂时还没有节点
    p->last = NULL;         //头结点之前没有节点

    S->head = p;
    S->rear = p;

    return true;
}

//判断栈是否为空
bool DbStackEmpty(DbStack S){
    if(S->head == S->rear)   //头指针和尾指针指向同一个结点
        return true;    //返回true，表示栈为空
    else
        return false;
}

//入栈（在双链表链尾插入）
bool DbPush (DbStack &S, int x){
    DbSNode * p = (DbSNode *) malloc(sizeof(DbSNode));     //新分配一个结点
    p->data = x;     //存入新元素
    p->next = NULL;
    p->last = S->rear;  //新结点插入链尾
    S->rear->next = p;
    S->rear = p;
    return true;
}

//出栈（删除双链表链尾元素）
bool DbPop (DbStack &S, int &x){
    if (DbStackEmpty(S))     //栈空，出栈操作失败
        return false;

    DbSNode * p = S->rear;    //栈不空，链尾结点出栈
    x = p->data;             //x返回栈顶元素
    S->rear = p->last;       //更新链尾指针
    S->rear->next = NULL;
    free(p);                 //释放结点
    return true;
}

//-----end栈顶在链尾-----