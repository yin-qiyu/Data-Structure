/*
 * @Author: yin-qiyu
 * @Date: 2022-09-16 23:43:10
 * @LastEditTime: 2022-09-28 22:56:55
 * @Description: 2018年
 * 找出数组中未出现的最小正整数
 * 给定一个含n（n≥1）个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。例如，数组{-5, 3, 2, 3}中未出现的最小正整数是1；数组{1, 2, 3}中未出现的最小正整数是4。要求：
（1）给出算法的基本设计思想。
（2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
（3）说明你所设计算法的时间复杂度和空间复杂度。
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
    int i = 0;
    while (i < n && a[i] <= 0){
        i++;
    }
    if(i == n){
            cout<<1;
            cout<<"\n";
            return;
            }   
    //到这里a[i]是数组中最小的正数
    int t = 1;
    if(a[i] != t){
        cout<< t ;
        cout<<"\n";
        return;
    }
    for (int j = i; j < n; j++){
        if(t == a[j]){
            continue;
        }
        if(t+1 == a[j]){
            t++;
        }
        else{
            cout<<t + 1;
            cout<<"\n";
            return;
        }
    }
    cout<<t+1;
    cout<<"\n";
}


int main(int argc, char const *argv[])
{
    int a1[] = {-5, 3, 2, 3};
    ans(a1, 4);
    for (int i = 0; i < 4; i++)
    {
        cout<<a1[i] ;
    }
    
    cout<<"\n";
    int a2[] = {1, 2 ,3};
    ans(a2, 3);
    for (int i = 0; i < 3; i++)
    {
        cout<<a2[i] ;
    }

    cout<<"\n";
    int a3[] = {-1, 0 ,1, 2, 3 };
    ans(a3, 5);
    for (int i = 0; i < 5; i++)
    {
        cout<<a3[i] ;
    }

    cout<<"\n";
    int a4[] = {-5, -4, -3, -2, -1 };
    ans(a4, 5);
    for (int i = 0; i < 5; i++)
    {
        cout<<a4[i] ;
    }
    return 0;
}
