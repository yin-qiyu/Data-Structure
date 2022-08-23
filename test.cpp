#include <iostream>

int main() {
    int i= 1,s = 1;
    while(s<100)
        s+=++i;
    printf("%d",i);
}

#define SIZE 100
int UFSets[SIZE];

//初始化
void initial(int s[]){
    for (int i = 0; i < SIZE; i++)
    {
        s[i] = -1;
    }
}

//并	o(1)
void Union(int s[], int root1, int root2){
  if (root1 == root2)   return;
  s[root2] = root1;   //把root2连到root1下面
}
//并优化
void Union2(int s[], int root1, int root2){
    if (s[root2]>s[root1])
    {   
        s[root1] += s[root2];
        s[root2] = root1;
    }else{
        s[root2] += s[root1];
        s[root1] = root2;
    }
    
}


//查 o(n)
int Find(int s[], int x){
    while (s[x]>=0)
    {

        x = s[x];      //循环找x根
    }
    return x;   //返回根
    
}