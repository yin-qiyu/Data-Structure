/*
 * @Author: yin-qiyu
 * @Date: 2022-08-23 21:19:19
 * @LastEditTime: 2022-09-28 22:58:15
 * @Description: 2011
 * 一个长度为L（L≥1）的升序序列S，处在第 ëL/2ù 个位置的数称为S的中位数。例如，若序列S1 = (11, 13, 15, 17, 19)，则S1的中位数是15，两个序列的中位数是含它们所有元素的升序序列的中位数。例如，若S2 = (2, 4, 6, 8, 20)，则S1和S2的中位数是11。现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。要求：
（1）给出算法的基本设计思想。
（2）根据设计思想，采用C、C++或Java语言描述算法，关键之处给出注释。
（3）说明你所设计算法的时间复杂度和空间复杂度。
 * 
 */
#include <iostream>
using namespace std;

//打印数组
void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

//start快排
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

void quicksort(int a[],int l, int r){
    if(l < r){
        int pos = partition(a, l, r);
        quicksort(a, l, pos-1);
        quicksort(a, pos + 1, r);
    }
}
//end快排


void ans(int a[], int b[], int n){
    int c[2 * n];
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i];
        c[n + i] = b[i];

    }
    print_arr(c, 2 * n);
    quicksort(c, 0, 2 * n - 1);

    print_arr(c,2 * n);
    printf("%d",c[n - 1]); 

}


int main(int argc, char const *argv[])
{
    int a[] = {11, 13, 15, 17, 19};
    int b[] = {2, 4, 6, 8, 20};
    ans(a, b, 5);
    return 0;
}
