/*
 * @Author: yin-qiyu
 * @Date: 2022-08-31 20:01:02
 * @LastEditTime: 2022-09-28 22:57:30
 * @Description: 2013年
 * 已知一个整数序列A = (a0, a1,…, an-1)，其中0≤ai＜n（0≤i < n）。若存在ap1 = ap2 =…= apm= x且m > n/2（0≤pk < n, 1≤k≤m），则称x为A的主元素。例如A= (0, 5, 5, 3, 5, 7, 5, 5)，则5为主元素；又如A = (0, 5, 5, 3, 5, 1, 5, 7)，则A中没有主元素。假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A的主元素。若存在主元素，则输出该元素；否则输出-1。要求：
（1）给出算法的基本设计思想。
（2）根据设计思想，采用C、C++或Java语言描述算法，关键之处给出注释。
（3）说明你所设计算法的时间复杂度和空间复杂度。
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

/**
 * @description: 先快速排序得到升序序列，权值相同的元素都会相邻，
 * 扫描一趟数组，L是之前相邻的相同元素最左边的元素下标，i是此时正在扫描的元素下标，
 * 如果A[i]不等于A[L]则说明碰到了新的元素。
 * @param {int} a
 * @param {int} n
 * @return {*}
 */
void ans1(int a[], int n){
    randomized_quicksort(a, 0, n-1);
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[l])       //遇到元素a[i]
        {
            if (i-l>n/2)       //如果当前元素下标-上一个不相等元素下标 =（元素个数）> 总数一半
            {
                cout<<a[l];     
                return;
            }
            l = i;  //记录值不一样的元素
        }
    }
        cout<<-1;
        return;     
}

int main(int argc, char const *argv[])
{
    int a[] ={0, 5, 5, 3, 5, 1, 5, 7, 5};
    ans1(a, 9);
    return 0;
}
