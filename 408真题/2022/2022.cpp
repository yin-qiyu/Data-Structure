/*
 * @Author: yin-qiyu
 * @Date: 2022-09-20 12:09:40
 * @LastEditTime: 2022-09-20 13:13:45
 * @Description: 2022 
 * 
 */


#include <iostream>
#include <vector>
using namespace std;

#define Rchild_SIZE  20

typedef struct 
{
    int SqBiTNode[Rchild_SIZE];
    int ElemNum;
}SqBiTree;


bool judgeBST(SqBiTree bt){
    int parent = 0, *Lchild ,*Rchild;
    Lchild = (int *)malloc(sizeof(int)*(bt.ElemNum));
    Rchild = (int *)malloc(sizeof(int)*(bt.ElemNum));
    for (int i = 0; i < bt.ElemNum; i++)
        Lchild[i] = Rchild[i] = bt.ElemNum;   //初始化
    for (int i = bt.ElemNum - 1; i > 0; i--)
        if (bt.SqBiTNode[i] != -1)
        {
            parent = (i -1)/2;
            if(i%2 == 1 && bt.SqBiTNode[parent]>Lchild[i]) //左孩子
                Lchild[parent] = Lchild[i];
            if(i%2 == 0 && bt.SqBiTNode[parent]>Lchild[i]) //右孩子
                Rchild[parent] = Rchild[i];
            else return false;
        }
        return true;
}



