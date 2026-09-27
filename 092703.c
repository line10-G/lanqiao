/*
问题描述
新生入学后，图书馆将 N 本书摆在一条书架上。书的编号为 1,2,…,N。
目前，这些书的顺序可能是乱的。管理员希望通过调整书的位置，使书架
最终变为：第 1 个位置放编号 1 的书，第 2 个位置放编号 2 的书，
依次类推。
书架前安装了一台轨道机械臂。每次操作时，小蓝可以选择三个连续的位
置，机械臂会交换第一个位置和第三个位置上的书，中间位置上的书保持
不动。
例如，当前书架顺序为 1,2,3,4,5。选择第 2 至第 4 个位置后，编号
为 2 和 4 的书会交换，书架变为 1,4,3,2,5。
现在给出书架上 N 本书的当前顺序，请你计算，至少需要进行多少次操
作，才能将书架恢复为 1,2,…,N 的顺序。如果无论如何都无法完成，
输出 −1。

输入格式
第一行包含一个整数 N（3≤N≤2000），表示书的数量。
第二行包含 N 个整数 A1 ,A2 ,…,AN ，表示书架当前从左到右的顺序。
保证 A 是 1∼N 的排列。

输出格式
输出一个整数，表示恢复书架顺序所需的最少操作次数；如果无法完成，
输出 −1。
*/

#include <stdio.h>

long long count_inv(int a[], int n) {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) res++;
        }
    }
    return res;
}

long long solve_subseq(int a[], int n, int start) {
    for (int i = 0; i < n; i++) {
        if ((a[i] % 2) != ((start + 2 * i) % 2)) {
            return -1;
        }
    }
    return count_inv(a, n);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int odd[2005] = {0};
    int even[2005] = {0};
    int o = 0, e = 0;
    
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (i % 2 == 1) {
            odd[o++] = x;
        } else {
            even[e++] = x;
        }
    }
    
    long long odd_res = solve_subseq(odd, o, 1);
    long long even_res = solve_subseq(even, e, 2);
    
    if (odd_res == -1 || even_res == -1) {
        printf("-1\n");
    } else {
        printf("%lld\n", odd_res + even_res);
    }
    
    return 0;
}