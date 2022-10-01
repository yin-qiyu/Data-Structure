/*
 * @Author: yin-qiyu
 * @Date: 2022-09-30 22:44:02
 * @LastEditTime: 2022-09-30 23:49:08
 * @Description: 
 已知一个带有表头结点的单链表，结点结构为
    |data|link|
假设该链表只给出了头指针list。在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点（k为正整数）。若查找成功，算法输出该结点的data域的值，并返回1；否则，只返回0。要求：
1）描述算法的基本设计思想。
2）描述算法的详细实现步骤。
3）根据设计思想和实现步骤，采用程序设计语言描述算法（使用C、C++或Java语言实现），关键之处请给出简要注释。
 * 
 */


#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *link;
}*Linklist;


//
int ans(Linklist l, int k){
    Linklist p = l->link, q = l->link;
    int count = 0;
    while (p != NULL){              //循环一遍
        if (count < k)count ++;     //pq间隔k同步向后移动
        else q = q->link;
        p = p->link;
    }
    if (count < k){             // 
        return 0;
    }else{
        cout<<q->data<<endl;
        return 1;
    }
}




