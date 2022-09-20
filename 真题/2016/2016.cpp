/*
 * @Author: yin-qiyu
 * @Date: 2022-09-16 22:43:18
 * @LastEditTime: 2022-09-16 23:34:54
 * @Description: 2016年
 * 
 */


#include <iostream>
#include <vector>
using namespace std;

//quicksort
int partition(int a[], int l, int r){
    int pivot = a[l];   //设表中第一个元素为pivot
    while (l < r)
    {
        while(l < r && a[r] >= pivot) r--; //如果r大于pivot，指针左移
        a[l] = a[r];    //r < pivot交换lr位置
        while(l < r && a[l] <= pivot) l++;
        a[r] = a[l];
    }
    a[l] = pivot;   //枢轴元素放到最终位置
    return l;       //返回枢轴最终位置
}


int randomized_partition(int a[], int l, int r){
    int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元,(r-l)防止溢出
    swap(a[l], a[i]);
    return partition(a, l, r);
}


void randomized_quicksort(int a[],int l, int r){
    if(l < r){
        int pos = randomized_partition(a, l, r);
        randomized_quicksort(a, l, pos-1);
        randomized_quicksort(a, pos + 1, r);
    }
}


void ans(int a[], int n){
    randomized_quicksort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for (int i = 0; i <= n/2 - 1; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for (int i = n/2; i <= n-1; i++)    //奇数中间数发给s2
    {
        printf("%d ",a[i]);
    }
    
}

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5,6,7};
    int n = 7;
    ans(a, n);
    return 0;
}
