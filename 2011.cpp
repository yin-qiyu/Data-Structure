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
