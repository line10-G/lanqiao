/*
问题描述
开学后，学校食堂迎来了许多前来就餐的新生。午餐高峰期，共有 N 份
订单依次送入后厨，第 i 份订单需要的备餐时间为 Ai 。
为了提高出餐效率，后厨会选取一段连续的订单组成一个备餐批次，并将
这个批次的第一份订单作为基准订单。备餐时间短于基准订单的其他订单
可以直接加入这一批次，不会影响原有的出餐安排。
如果某份后续订单的备餐时间大于或等于基准订单，就需要交给备用窗口
单独处理。由于食堂只开放了一个备用窗口，所以同一个批次中，这样的
后续订单最多只能有一份。
因此，对于一个由第 l 份到第 r 份订单组成的批次，如果在 l<i≤r 的
位置中，满足 Ai ≥Al 的订单不超过一份，就称这个备餐批次是可行的。
只包含一份订单的批次也视为可行的。
现在，请你帮助小蓝计算，一共有多少个连续的备餐批次是可行的。

输入格式
第一行包含一个整数 N（1≤N≤2×10^5），表示订单数量。
第二行包含 N 个整数 A1,A2,…,AN（1≤Ai≤10^9 ），其中 Ai 表示第 
i 份订单需要的备餐时间。

输出格式
输出一个整数，表示可行的连续备餐批次数量。
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005

typedef struct {
    long long v;
    int idx;
} Item;

static int n;
static int bit[MAXN];
static void add(int p, int d) {
    for (; p <= n; p += p & (-p)) bit[p] += d;
}

static int sum(int p) {
    int s = 0;
    for (; p > 0; p -= p & (-p)) s += bit[p];
    return s;
}

static int kth(int k) {
    int idx = 0, step;
    for (step = 1; step <= n; step <<= 1) {}
    step >>= 1;
    while (step) {
        int nxt = idx + step;
        if (nxt <= n && bit[nxt] < k) {
            k -= bit[nxt];
            idx = nxt;
        }
        step >>= 1;
    }
    return idx + 1;
}

static int cmp(const void *a, const void *b) {
    const Item *x = (const Item *)a;
    const Item *y = (const Item *)b;
    if (x->v != y->v) return x->v > y->v ? -1 : 1;
    return x->idx - y->idx;
}

int main(void) {
    scanf("%d", &n);
    Item *items = (Item *)malloc(sizeof(Item) * n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &items[i - 1].v);
        items[i - 1].idx = i;
    }
    qsort(items, n, sizeof(Item), cmp);

    long long ans = 0;
    int i = 0;
    while (i < n) {
        long long v = items[i].v;
        int j = i;
        while (j < n && items[j].v == v) {
            add(items[j].idx, 1);
            j++;
        }
        for (int k = i; k < j; k++) {
            int pos = items[k].idx;
            int cnt = sum(n) - sum(pos);
            if (cnt < 2) {
                ans += (long long)n - pos + 1;
            } else {
                int k1 = sum(pos) + 1;
                int p1 = kth(k1);
                int k2 = sum(p1) + 1;
                int p2 = kth(k2);
                ans += (long long)p2 - pos;
            }
        }
        i = j;
    }

    printf("%lld\n", ans);
    free(items);
    return 0;
}