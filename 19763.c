/*
问题描述
这是一道练习题。
给定若干行数据，每行数据为一个正整数，该正整数范围在 int 范围内。
你的任务是将这些数据全部输出。

输入格式
输入若干行数据，每行一个正整数。

输出格式
输出这些数据。
*/
#include <stdio.h>
int main(int argc, char *argv[]){
    int i=0;
    while(scanf("%d",&i)==1){
        printf("%d\n",i);
    }
    return 0;
}