/*
问题描述
输入一个数组 a，包含有 n 个元素 a1 ,a2 ,⋯,an 。对这个数组进行
 m 次变换，每次变换会将数组 a 中的每个元素ai转换为 
 ai ⋅ bitCount(ai)。其中 bitCount(x) 表示数字 x 的二进制表示
 中 1 出现的次数，例如 bitCount(3)=2，因为 3 的二进制表示为 
 11，其中 1 出现了两次。

请输出变换之后的数组内容。

输入格式
输入的第一行包含一个正整数 n，表示数组 a 中的元素个数。

第二行包含 n 个整数 a1 ,a2 ,⋯,an ，相邻整数之间使用一个空格
分隔。

第三行包含一个整数 m，表示变换次数。

输出格式
输出一行，包含 n 个整数，相邻整数之间使用一个空格分隔，表示变换
之后得到的数组 a。
*/

#include <stdio.h>

int bitCount(int x){
    int count = 0;
    while(x > 0){
        count += x % 2;
        x /= 2;
    }
    return count;
}

int main(void){
    int n;
    scanf("%d",&n);

    int a[1001];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int t;
    scanf("%d",&t);
    for(int i=0;i<n;i++){
        int x = a[i];
        for(int j=0;j<t;j++){
            x = x*bitCount(x);
        }
        printf("%d ",x);
    }

    return 0;
}

/*
问题描述
给定一个长度为 n 的数组 a，以及两个正整数 m 和 P。
对数组进行恰好 m 次变换，每次变换将每个元素 ai同时更新为：
a_i←(a_i×bitCount(a_i))modP 
其中 bitCount(x) 表示 x 的二进制表示中 1 的个数。

输入格式
n m P
a1 a2 ... an

输出格式
一行 n 个整数，表示 m 次变换后的数组。

数据范围
1≤n≤100
1≤m≤10^18
2≤P≤10^9
0≤ai<P
*/
/*
//超时
#include <stdio.h>

int bitCount(int x){
    int count = 0;
    while(x > 0){
        count += x % 2;
        x /= 2;
    }
    return count;
}

int main(void){
    int n,m,P;
    scanf("%d %d %d",&n ,&m ,&P);

    int a[100]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        int x = a[i];
        for(int j=0;j<m;j++){
            x = (x*bitCount(x))%P;
        }
        printf("%d ",x);
    }

    return 0;
}
*/
/*
#include <stdio.h>

// 变换规则：f(x) = (x * bitCount(x)) % P
long long bitCount(long long x) {
    int cnt = 0;
    while (x > 0) {
        cnt += (x & 1);
        x >>= 1;
    }
    return cnt;
}

// 一步变换
long long next(long long x, long long P) {
    return (x * bitCount(x)) % P;
}

// Floyd 判圈：返回最终值
long long solve_one(long long start, long long m, long long P) {
    if (m == 0) return start;
    
    // ========== Phase 1：找相遇点 ==========
    long long slow = next(start, P);
    long long fast = next(next(start, P), P);
    
    while (slow != fast) {
        slow = next(slow, P);
        fast = next(next(fast, P), P);
    }
    
    // ========== Phase 2：求环长度 ==========
    long long cycle_len = 1;
    fast = next(slow, P);
    while (fast != slow) {
        fast = next(fast, P);
        cycle_len++;
    }
    
    // ========== Phase 3：求环入口（前置长度） ==========
    long long pre_len = 0;
    slow = start;
    fast = next(start, P);
    // 先走 pre_len 步让 fast 到达环入口
    // 实际上这里我们不需要严格找入口，换一种更直观的方式：
    // 直接模拟 pre_len 步，然后用 m 定位
    
    // 更实用的做法：直接记录完整轨迹
    // 但为了 Floyd 教学，用标准方法：
    long long entry = start;
    fast = start;
    // fast 先走 cycle_len 步
    for (int i = 0; i < cycle_len; i++) {
        fast = next(fast, P);
    }
    // 然后同步走，相遇就是入口
    while (entry != fast) {
        entry = next(entry, P);
        fast = next(fast, P);
        pre_len++;
    }
    
    // ========== Phase 4：直接定位 ==========
    if (m <= pre_len) {
        // 还没进环，暴力模拟
        long long res = start;
        for (long long i = 0; i < m; i++) {
            res = next(res, P);
        }
        return res;
    } else {
        // 已经进环
        long long remaining = (m - pre_len) % cycle_len;
        long long res = entry;
        for (long long i = 0; i < remaining; i++) {
            res = next(res, P);
        }
        return res;
    }
}

int main() {
    int n;
    long long m, P;
    scanf("%d %lld %lld", &n, &m, &P);
    
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lld", &a);
        printf("%lld ", solve_one(a, m, P));
    }
    return 0;
}
*/