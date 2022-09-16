/*
 * @Author: yin-qiyu
 * @Date: 2022-09-01 12:07:31
 * @LastEditTime: 2022-09-15 23:56:40
 * @Description: 顺序栈的基本操作 用数组实现
 */

#include <iostream>
#include <vector>
using namespace std;
#define maxsize = 50

typedef struct SqStack
{
    int data[50];   //存放栈的元素
    int top;        //定义顶指针
};

//初始化
void initStack(SqStack &s){
    s.top = -1;
}

//判空
bool stcakEmpty(SqStack s){
    if (s.top == -1)
        return true;    //空
    else
        return false;   //不空
}

//元素入栈
bool push(SqStack &s,int x){
    if(s.top == -1)         //栈满 报错
        return false;   
    s.data[++s.top] = x;    //指针先+1，再入栈
    return true;
}

//元素出栈
bool pop(SqStack &s, int &x){
    if (s.top == -1) 
        return false;
    x = s.data[s.top--];    //先出栈，指针再-1
}

//读栈顶元素
int GetPop(SqStack s,int &x){
    if(s.top == -1)
        return false;
    x = s.data[s.top];
    return x;
}



