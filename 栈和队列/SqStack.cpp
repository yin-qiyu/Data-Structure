/*
 * @Author: yin-qiyu
 * @Date: 2022-09-01 12:07:31
 * @LastEditTime: 2022-09-01 14:39:03
 * @Description: 顺序栈的基本操作
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

void initStack(SqStack &s){
    s.top = -1;
}

bool stcakEmpty(SqStack s){
    if (s.top == -1)
    {
       return true;
    }
}

//元素入栈
bool push(SqStack &s,int x){
    if(s.top == -1)
        return false;
    s.data[++s.top] = x;
    return true;
}

//元素出栈
bool pop(SqStack &s, int &x){
    if (s.top == -1) 
        return false;
    x = s.data[s.top--];
}

//读栈顶元素
int GetPop(SqStack s,int &x){
    if(s.top == -1)
        return false;
    x = s.data[s.top];
    return x;
}



