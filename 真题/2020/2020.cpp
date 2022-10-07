/*
 * @Author: yin-qiyu
 * @Date: 2022-09-28 22:40:56
 * @LastEditTime: 2022-10-07 12:44:56
 * @Description: 2020
 * 定义三元组(a，b，c)（a，b，c均为正数）的距离D = |a – b| + |b – c| + |c – a|。给定3个非空整数集合S1、S2和S3，按升序分别存储在3个数组中。请设计一个尽可能高效的算法，计算并输出所有可能的三元组(a，b，c)（a∈S1，b∈S2，c∈S3）中的最小距离。例如 S1 = {–1，0，9}，S2 = {–25，–10，10，11}，S3 ={2，9，17，30，41}，则最小距离为2，相应的三元组为(9，10，9)。要求：
（1）给出算法的基本设计思想。
（2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
（3）说明你所设计算法的时间复杂度和空间复杂度。
 */



#include <iostream>
#include <limits.h>
using namespace std;


void ans(int a[], int n1,int b[], int n2, int c[], int n3){
    int min = INT_MAX, D = 0;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            for (int k = 0; k < n3; k++){
                D = abs(a[i] - b[j]) + abs(b[j] - c[k]) + abs(c[k] - a[i]);
                if(D<min) min = D;
            }
    cout<<min;
    
}

int main(int argc, char const *argv[])
{
    int s1[] = {-1, 0, 9};
    int s2[] = {-25, -10, 10, 11};
    int s3[] = {2, 9, 17, 30, 41};
    ans(s1, 3, s2, 4, s3, 5);
    return 0;
}
