/*
 * @Author: yin-qiyu yinqiyu66@163.com
 * @Date: 2022-08-27 19:12:42
 * @LastEditors: yin-qiyu yinqiyu66@163.com
 * @LastEditTime: 2022-08-27 20:25:10
 * @FilePath: /data-structure/查找/binary_search.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by yin-qiyu yinqiyu66@163.com, All Rights Reserved. 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @description: 
 * @param {int} target 目标函数
 * @param {int} arr 数组
 * @param {int} len 长度
 * @return {*} 找到 返回m下标，未找到返回-1
 */
int binary_search(int target, int arr[], int len){
    int l = 0, r = len - 1, mid;
    while (l < r)
    {
        mid = l + (r - l)/2; //防止int溢出
        if(arr[mid] < target)
            l = mid + 1;
        else if(target < arr[mid])
            r = mid -1;
        else
            return mid;
    }
    return -1;
    
}


int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 4, 6, 7, 10, 11, 19, 24, 30};
    int target = 4;
    int len = sizeof(arr)/sizeof(int) - 1;
    printf("target: %d, pos: %d\n", target, binary_search(target, arr, len));
    return 0;
}
