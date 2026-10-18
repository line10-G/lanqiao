/*
问题描述
周末，摄影社准备组织一次校外采风，共有 N 名同学报名。社团为这次活动
准备了 B 元经费，由社长小蓝统一安排，门票、午餐和租车费用都由社团承
担。
活动需要支付以下两项费用：
游玩费用：第 i 名同学的门票和午餐需 Ai元，只为实际参加的同学支付这
笔费用。
租车费用：采风地点离学校较远，参加的同学需要统一乘车往返。每辆车最
多乘坐 K 名同学，租金为 C 元。
小蓝可以租用多辆车，但必须保证所有参加的同学都有座位；即使车辆没有
坐满，也要支付整辆车的租金。

小蓝计划从报名的同学中任选一些人参加采风。现在，请你帮助他计算，在
总费用不超过 B 元的情况下，最多能安排多少名同学参加。

输入格式
第一行包含四个整数 N,K,C,B（1≤N,K≤10^5,1≤C≤10^9,0≤B≤10^14），分
别表示报名人数、每辆车的座位数、每辆车的租金和可用经费。
第二行包含 N 个整数 A1,A2,…,AN（1≤Ai≤10^9），其中 Ai  表示社团为
第 i 名同学支付的门票和午餐费用。

输出格式
输出一个整数，表示最多能安排参加采风的同学人数。
*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return (*(long long*)a>*(long long*)b) - (*(long long*)a<*(long long*)b);
}

int main(void){
    int n,k;
    long long c,b;
    scanf("%d %d %lld %lld",&n,&k,&c,&b);
    long long a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }

    qsort(a,n,sizeof(long long),cmp);

    int number=0;
    long long total = 0;
    for(int i=0;i<n;i++){
        int cars = (i+1+k-1)/k;
        long long cost = total + a[i] + (long long)cars * c;

        if(cost<=b){
            total+=a[i];
            number++;
        }else{
            break;
        }
    }

    printf("%d\n",number);

    return 0;
}