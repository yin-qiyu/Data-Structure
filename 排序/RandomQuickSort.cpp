/*
 * @Author: yin-qiyu
 * @Date: 2022-08-30 16:08:18
 * @LastEditTime: 2022-09-01 14:39:58
 * @Description: 随机pivot快排。时间复杂度：基于随机选取主元的快速排序时间复杂度为期望 O(nlogn),空间复杂读：O(n)。
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @description: 划分操作，将未排序数组划分为左， pivot，右
 * @param {int} a 数组
 * @param {int} l 最小下标
 * @param {int} r 最大下标
 * @return {*} pivot
 */
int partition(int a[], int l, int r){
    int pivot = a[l];   //设表中第一个元素为pivot
    while (l < r)
    {
        while(l < r && a[r] >= pivot) r--; //如果r大于pivot，指针左移
        a[l] = a[r];    //r < povot交换lr位置
        while(l < r && a[l] <= pivot) l++;
        a[r] = a[l];
    }
    a[l] = pivot;
    return l;
}

/**
 * @description: 随机划分
 * @param {int} a 数组
 * @param {int} l 最小下标
 * @param {int} r 最大下标
 * @return {*}
 */
int randomized_partition(int a[], int l, int r){
    int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元,(r-l)防止溢出
    swap(a[l], a[i]);
    return partition(a, l, r);
}

/**
 * @description: 递归随机快排
 * @param {int} a 数组
 * @param {int} l 最小下标
 * @param {int} r 最大下标
 * @return {*} null
 */
void randomized_quicksort(int a[],int l, int r){
    if(l < r){
        int pos = randomized_partition(a, l, r);
        randomized_quicksort(a, l, pos-1);
        randomized_quicksort(a, pos + 1, r);
    }
}


int main(int argc, char const *argv[])
{
    int arr[] = {5,1,1,2,0,0};
    //int arr[] = {5,2,3,1,2};
    randomized_quicksort(arr, 0, sizeof(arr)/sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}