/*
问题描述
迎新晚会的会场已经布置完成。为了方便工作人员快速引导同学，小蓝
决定按照蜗牛形路线为会场中的座位编号。
会场中的座位呈正方形排列，共有 N 行、N 列。

编号从左上角开始，左上角的座位编号为 1。随后沿第一行从左向右编
号，再沿最右列从上向下编号，接着沿最下一行从右向左编号，最后沿
最左列从下向上编号，完成最外层一圈。
完成外围一圈后，再对剩余的内部座位按照相同的方式继续编号，直到
所有座位都完成编号。
例如，对于一个 5×5 的会场，编号如下：
    1  2  3  4  5
    16 17 18 19 6
    15 24 25 20 7
    14 23 22 21 8
    13 12 11 10 9
已知小蓝的座位位于第 i 行、第 j 列。为了方便找到自己的座位，小
蓝想提前知道这个位置对应的编号是多少，请你帮他计算出来。

输入格式
输入一行，包含三个整数 N,i,j（1≤N≤10^9,1≤i,j≤N）。

输出格式
输出一个整数，表示目标座位的编号。
*/
#include <stdio.h>

long long min3(long long a, long long b, long long c) {

    long long m = a < b ? a : b;
    return m < c ? m : c;
}

int main(void) {
    long long N, i, j;
    scanf("%lld %lld %lld", &N, &i, &j);

    long long k = i - 1;
    if (j - 1 < k) k = j - 1;
    if (N - i < k) k = N - i;
    if (N - j < k) k = N - j;

    long long L = N - 2 * k;
    long long start = 1 + 4 * k * (N - k);
    long long ans;

    if (L == 1) {
        ans = start;
    } else {
        long long r = i - (k + 1);
        long long c = j - (k + 1);
        if (r == 0)            ans = start + c;
        else if (c == L - 1)   ans = start + L - 1 + r;
        else if (r == L - 1)   ans = start + 3 * L - 3 - c;
        else                   ans = start + 4 * L - 4 - r;
    }

    printf("%lld\n", ans);
    return 0;
}