/*
问题描述
小蓝最近对求和很着迷，给定一个正整数 n，他想求从 n 开始的连
续 25 个整数的和，即 n+(n+1)+(n+2)+⋯+(n+24)，请帮帮他吧。

输入格式
输入一行包含一个正整数 n。

输出格式
输出一行包含一个整数表示答案。
*/

#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int i,res=0;
    for(i=0;i<25;i++){
        res += n + i;
    }
    printf("%d",res);

    return 0;
}