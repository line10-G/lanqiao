/*
问题描述
程序设计课上，共有 N 名学生按照座位顺序从左到右坐成一排。
第 i 名学生本周完成了 Ai 道练习题。
老师准备安排一次小组展示，对此，他需要选择 K 名座位连续的学生，
组成一个小组。
老师将小组内所有学生本周完成的练习题总数作为小组的活跃度。
现在，请你计算，在所有可能的连续小组中，活跃度的最大值是多少。

输入格式
第一行包含两个整数 N,K（1≤K≤N≤10^5），分别表示学生人数和小组人数。
第二行包含 N 个整数 A1,A2,…,AN（0≤Ai≤10^9 ），
其中 Ai 表示第 i 名学生本周完成的练习题数量。

输出格式
输出一个整数，表示小组能够达到的最大活跃度。
*/

#include <stdio.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[100001];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    long long maxSum = sum;
    for (int left = 1; left + k <= n; left++) {
        sum += a[left + k - 1] - a[left - 1];
        if (sum > maxSum) maxSum = sum;
    }
    printf("%lld\n", maxSum);
    return 0;
}