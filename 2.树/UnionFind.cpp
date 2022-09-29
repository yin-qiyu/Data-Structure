/*
 * @Author: yin-qiyu
 * @Date: 2022-09-29 18:05:43
 * @LastEditTime: 2022-09-29 18:24:49
 * @Description: 并查集，用双亲表示法
 * 
 */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX_TREE_SIZE 100

//双亲表示法，每个节点中你保存指向双亲的指针
typedef struct 
{
    int data;
    int parent;
}PTNode;
typedef struct 
{
    PTNode nodes[MAX_TREE_SIZE];
    int n;
}PTtree;

#define SIZE 13
int UFSets[SIZE];

//初始化并查集
void initial(int s[]){
    for (int i = 0; i < SIZE; i++)
    {
        s[i] = -1;
    }   
}

/**
 * @description: root2连接到root1下面,o(1)
 * @param {int} s
 * @param {int} root1
 * @param {int} root2
 */
void Union(int s[], int root1, int root2){
    //要求root1和root2不是同一个集合
    if(root1 == root2)return;
    //root2连接到root1下面
    s[root2] = root1;
    
}



/**
 * @description: 查 o(n)
 * @param {int} s
 * @param {int} x
 * @return x所属的根节点
 */
int Find(int s[], int x){
    while (s[x]>0)
    {
        x = s[x];
    }
    return x;
}