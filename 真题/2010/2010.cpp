/*
 * @Author: yin-qiyu
 * @Date: 2022-08-18 19:38:40
 * @LastEditTime: 2022-09-27 20:38:04
 * @Description: 2010
 * 
 */
#include <iostream>
using namespace std;

void reverse(int R[], int from, int to){
    int i, temp;
    for ( i = 0; i < (to - from)/2; i++)
   {
        temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = temp;
    }
    
}

void converse(int R[], int n, int p){
    reverse(R, 0, p-1);
    reverse(R, p, n-1);
    reverse(R, 0, n-1);
}

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    converse(a, 10, 1);
    for (int i = 0; i < 10; i++)
    {
        
        printf("%d ",a[i]);
    }
}
