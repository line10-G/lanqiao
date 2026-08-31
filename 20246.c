/*
问题描述
给定 n，求 n! 除以 1000000007 的余数。

其中 n! 表示 n 的阶乘，值为从 1 连乘到 n 的积，即 
n!=1×2×3×…×n。

输入格式
输入一行包含一个整数 n。

输出格式
输出一行，包含一个整数，表示答案。
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    long long n,res=1;
    scanf("%lld",&n);
    for(long long i=2;i<=n;i++){
        res = i*res%1000000007;
    }
    printf("%lld",res);
    return 0;
}