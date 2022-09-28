/*
 * @Author: yin-qiyu
 * @Date: 2022-09-16 22:43:18
 * @LastEditTime: 2022-09-28 22:57:15
 * @Description: 2016年
 * 已知由n（n≥2）个正整数构成的一个集合A = {ak|0≤k < n}，将其划分为两个不相交的子集A1和A2，元素个数分别是n1和n2，A1和A2中元素之和分别为S1和S2。设计一个尽可能高效的划分算法，满足|n1-n2|最小且|S1-S2|最大。要求：	
（1）给出算法的基本设计思想。
（2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
（3）说明你所设计算法的平均时间复杂度和空间复杂度。
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
