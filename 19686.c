/*
问题描述
从 1∼n 这 n 个正整数中随机选出 m 个，按字典序输出所有可能的
选择方案。

输入格式
输入一行，包含两个整数 n,m.(1≤n+(n−m)≤25,0≤m≤n)

输出格式
按字典序输出全部方案。
*/

#include <stdio.h>

int n, m;
int path[25];  // 题目约束 n+(n-m)<=25，所以 n 最大 25，数组开 25 够用

void dfs(int start, int depth) {
    // 已选够 m 个数，输出方案
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            if (i) printf(" ");
            printf("%d", path[i]);
        }
        printf("\n");
        return;
    }
    // 剪枝：剩余可选的数不够凑满 m 个时提前返回
    if (n - start + 1 < m - depth) return;
    for (int i = start; i <= n; i++) {
        path[depth] = i;
        dfs(i + 1, depth + 1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    dfs(1, 0);
    return 0;
}