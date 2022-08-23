#include <iostream>
using namespace std;

//

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;

//==================================
/**
* show 初始化一个单链表（带头结点）
* <p>show 方法的详细说明第一行<br>
* show 方法的详细说明第二行
* @param L true 表示显示，false 表示隐藏
* @return 没有返回值
*/
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)          //内存不足，分配失败
        return false;
    L->next = NULL;         //头结点后暂时还没有节点
    return true;
}

//=====测试=========
void test(){
    LinkList L; //声明一个指向单链表的指针
    
    InitList(L);
}

//头插法（链表的逆置）
LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));    //创建头结点
    L->next = NULL;
    printf("输入节点的值");
    scanf("%d",&x);
    while (x != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;                        //将新节点插入表中，L为头指针
        scanf("%d",&x); 
    }
    return L;
    
}

int main(){
    return 0;
}
