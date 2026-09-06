/*
问题描述
在今年蓝桥杯的决赛中，一共有 10 道题目，每道题目的分数依次
为 5 分，5 分，10 分，10 分，15 分，15 分，20 分，20 分，
25 分，25 分。

假设某位参赛选手在解答每一道题时，要么能得到该题的全部分数，
要么就得 0 分。那么请问，这位参赛选手在完成这 10 道题之后，
所能获得的总分值存在多少种不同的情况？

注意，总分值仅需关注选手 10 道题的总得分，而无需关注具体是
由哪些题获得了相应的分数。例如，选手第一道题获得 5 分其余题
均为 0 分，与第二道题获得 5 分其余题均为 0 分，应视为同一
种情况。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int score[]={5,5,10,10,15,15,20,20,25,25};
    bool dp[151]={false};
    dp[0]=true;
    for(int i=0;i<10;i++){
        int x=score[i];
        for(int s=150;s>=x;s--){
            if(dp[s-x])
            dp[s]=true;
        }
    }
    int count=0;
    for(int i=0;i<151;i++){
        if (dp[i])
        count++;
    }
    printf("%d",count);
    return 0;
}

/*
描述
你有 n 种硬币，面值分别为 v[0], v[1], ..., v[n-1]，每种硬
币有数量上限 c[i]（即可使用 0 到 c[i] 枚）。

给定一个目标金额 W，求：用这些硬币凑出恰好 W 元的方案总数，
答案对 10^9 + 7 取模。

输入格式
第一行：n W
第二行：n 个整数 v[0] ... v[n-1]（面值）
第三行：n 个整数 c[0] ... c[n-1]（数量上限）
*/
/*
//O(n × W × max_c)
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n,W;
    scanf("%d %d",&n,&W);
    int v[101],c[101];
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    int dp[100001]={0};
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=W;j>=0;j--){
            for(int k=1;k<=c[i]&&k*v[i]<=j;k++){
                dp[j]=(dp[j]+dp[j-k*v[i]])%1000000007;
            }
        }
    }
    printf("%d",dp[W]);
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAXW 100001

int dp[MAXW];       // 上一轮的结果（dp_old）
int new_dp[MAXW];   // 本轮的结果（dp_new）

int main(void) {
    int n, W;
    scanf("%d %d", &n, &W);

    int v[101], c[101];
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);

    dp[0] = 1;  // 凑 0 元有 1 种方案（什么都不选）

    for (int i = 0; i < n; i++) {
        int vi = v[i], ci = c[i];

        // 按余数 r = 0..vi-1 分组，每组内步长为 vi
        for (int r = 0; r < vi; r++) {
            long long window_sum = 0;

            // j 从 r 开始，每次加 vi，形成一条链：r, r+vi, r+2vi, ...
            for (int j = r; j <= W; j += vi) {
                // 1. 把 dp_old[j] 加入窗口
                window_sum = (window_sum + dp[j]) % MOD;

                // 2. 如果窗口已超过 ci+1 个元素，移除最左端
                int left = j - (ci + 1) * vi;
                if (left >= 0) {
                    window_sum = (window_sum - dp[left] % MOD + MOD) % MOD;
                }

                // 3. window_sum = dp_old[j] + dp_old[j-vi] + ... + dp_old[j-ci*vi]
                //    这正是 dp_new[j]
                new_dp[j] = (int)window_sum;
            }
        }

        // 把 new_dp 拷回 dp，准备下一轮
        memcpy(dp, new_dp, sizeof(int) * (W + 1));
    }

    printf("%d\n", dp[W]);
    return 0;
}
*/