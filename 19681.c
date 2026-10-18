/*
问题描述
有 N 件物品和一个体积为 M 的背包。第 i 个物品的体积为 vi ，价值为
 wi 。每件物品只能使用一次。
请问可以通过什么样的方式选择物品，使得物品总体积不超过 M 的情况下
总价值最大，输出这个最大价值即可。

输入格式
第一行输入两个正整数 N,M。(1≤N,M≤1000)
接下来 N 行，每行输入两个整数 vi,wi。(0≤vi,wi ≤1000)

输出格式
输出一个整数，表示符合题目要求的最大价值。
*/

#include <stdio.h>

int max(int a,int b){
    return a>b?a:b;
}

int dp[1005][1005];

int main(void){
    int n,m;
    scanf("%d %d",&n,&m);

    int v[1005],w[1005];

    for(int i=1;i<=n;i++){
        scanf("%d %d",&v[i],&w[i]);
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j<v[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
            }
        }
    }

    printf("%d\n",dp[n][m]);
    return 0;
}