/*
 * @Author: yin-qiyu
 * @Date: 2022-09-29 18:05:43
 * @LastEditTime: 2022-09-29 20:48:33
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

//合并root2连接到root1下面,o(1)
void Union(int s[], int root1, int root2){
    //要求root1和root2不是同一个集合
    if(root1 == root2)return;
    //root2连接到root1下面
    s[root2] = root1;
    
}

/*union优化，小树合并到到大树
用根节点的绝对值表示树的节点树
*/
void Union2(int s[], int root1, int root2){
    if (s[root2] > s[root1])//root2节点更少
    {
        s[root1] += s[root2];//累加节点数
        s[root2] = root1;//小树合并大树
    }
    else{   
        s[root2] += s[root1];
        s[root1] = root2;
    } 
    
}

//查
int Find(int s[], int x){
    while (s[x]>0)
    {
        x = s[x];
    }
    return x;
}

/*优化查找
压缩路径
*/
int find2(int s[], int x){
    int root = x;
    while (s[root] >= 0)
    {
        root = s[root]; //循环找到根节点
    }
    while (x != root)   //压缩路径
    {
        int t = s[x];   //t指向x的父结点
        s[x] = root;    //x直接挂到根节点下
        x = t;
    }
    return x;   //返回根节点编号
}