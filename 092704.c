/*
问题描述
课程结课前，小蓝需要到校内打印店打印 Q 页学习资料。
打印店提供两种打印方式：
直接打印：每页需要支付 P 元。
使用打印卡：打印店提供 M 种打印卡。第 i 种打印卡需要花费 Ci 元，
购买后可以打印至多 Li 页。每种打印卡最多购买一次，小蓝可以同时购
买多种打印卡。
小蓝可以选择合适的打印方式完成全部 
Q 页资料的打印。打印卡未使用的打印页数不会退还费用。
现在，请你帮助小蓝计算，打印完全部 Q 页资料至少需要花费多少元。

输入格式
第一行包含三个整数 Q,P,M（1≤Q,P≤10^9 ，1≤M≤18），分别表示需要
打印的页数、普通打印的每页价格和可购买的预付打印卡数量。

接下来 M 行，每行包含两个整数 Li,Ci（1≤Li,Ci ≤10^9），表示第
 i 张打印卡能够打印的页数和购买价格。

输出格式
输出一个整数，表示打印完全部资料的最少花费。
*/

#include <stdio.h>
typedef long long ll;

int main(void) {
    ll Q, P; int M;
    scanf("%lld %lld %d", &Q, &P, &M);
    ll L[20], C[20];
    for (int i = 0; i < M; i++) scanf("%lld %lld", &L[i], &C[i]);

    ll ans = Q * P;
    for (int mask = 0; mask < (1 << M); mask++) {
        ll sumL = 0, sumC = 0;
        for (int i = 0; i < M; i++)
            if (mask >> i & 1) { sumL += L[i]; sumC += C[i]; }
        ll remain = Q - sumL;
        if (remain < 0) remain = 0;
        ll cost = sumC + remain * P;
        if (cost < ans) ans = cost;
    }
    printf("%lld\n", ans);
    return 0;
}