/*
问题描述
社团活动结束后，小蓝负责为参加活动的 N 名同学拍摄合影，其中第 i 
名同学的身高为 Hi 厘米。
小蓝准备让同学们站成一排。为了让画面更加协调，他希望参加同一张合
影的同学身高较为接近，因此要求最高者与最矮者的身高差不能超过 K 
厘米。
小蓝可以从这 N 名同学中任选一些人参加合影。请你帮助他计算，一张
合影中最多可以安排多少名同学。

输入格式
第一行包含两个整数 N,K（1≤N≤10^5,0≤K≤10^9），分别表示同学人数
和允许的最大身高差。
第二行包含 N 个整数 H1,H2,…,HN（1≤Hi≤10^9），表示每名同学的身
高。

输出格式
输出一个整数，表示一张合影中最多可以安排的同学人数。
*/

#include <stdio.h>
#include <stdlib.h>

#define ll long long

int cmp(const void *a,const void*b){
    return (*(ll*)a>*(ll*)b) - (*(ll*)a<*(ll*)b);
}

int main(void){
    int n;
    ll k;
    scanf("%d %lld",&n,&k);
    ll lst[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&lst[i]);
    }
    qsort(lst,n,sizeof(ll),cmp);

    int left = 0, right = 0;
    int max = 0;
    while(right<n){
        if(lst[right]-lst[left]<=k){
            right++;
            max = max>right-left?max:right-left;
        }else{
            left++;
        }
    }
    printf("%d\n",max);

    return 0;
}