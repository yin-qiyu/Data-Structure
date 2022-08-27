#include <iostream>
#include <vector>
using namespace std;

//第一个元素为pivot
int partition(int a[], int l, int r){
    int pivot = a[l];   //设表中第一个元素为pivot
    while (l < r)
    {
        while(l < r && a[r] >= pivot) r--; //如果r大于pivot，指针左移
        a[l] = a[r];    //r < povot交换lr位置
        while(l < r && a[l] <= pivot) l++;
        
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


// //随机pivot
// int random_partitioin(int a[], int l, int r){
//     int i = rand() % (r - l + 1) + l;
//     int pivot = a[i];   //设表中第一个元素为pivot
//     while (l < r)
//     {
//         while(l < r && a[r] >= pivot) r--; //如果r大于pivot，指针左移
//         a[l] = a[r];    //r < povot交换lr位置
//         while(l < r && a[l] <= pivot) l++;
        
//     }
//     a[l] = pivot;
//     return l;

// }

// void random_quicksort(int a[],int l, int r){
//     if(l < r){
//         int pos = random_partitioin(a, l, r);
//         random_quicksort(a, l, pos-1);
//         random_quicksort(a, pos + 1, r);
//     }
// }


int main(int argc, char const *argv[])
{
    int arr[] = {5, 2, 3, 1};
   // random_quicksort(arr, 0, sizeof(arr)/sizeof(int)-1);

    quicksort(arr, 0, sizeof(arr)/sizeof(int) - 1);

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}
