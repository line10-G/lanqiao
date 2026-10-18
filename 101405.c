/*
问题描述
校园文化节的晚会上，小蓝负责布置一条挂有 N 面彩旗的彩带。第 i 面彩旗的长度为 Ai。
设计图要求，彩旗从左到右的长度不能变小。小蓝检查时发现，已经挂好的彩旗不一定符合要求，而且比
挂架能够容纳的数量多了 K 面。
晚会即将开始，小蓝来不及重新排列所有彩旗。他准备拆下连续的 K 面彩旗，再把拆除处两侧剩余的彩
带接起来，其余彩旗保持原来的相对顺序。
请计算，有多少种拆除位置，能够使剩余彩旗从左到右的长度不递减。如果拆下彩带开头或末尾的 K 面
彩旗，直接保留另一部分即可。
两种选择只要拆下的起始位置不同，就视为不同的方案。

输入格式
第一行包含两个整数 N,K（2≤N≤10^5,1≤K<N），分别表示彩旗数量和需要拆下的数量。
第二行包含 N 个整数 A1,A2,…,AN（1≤Ai≤10^9），表示彩旗从左到右的长度。

输出格式
输出一个整数，表示满足设计要求的拆除方案数量。
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void){
    int n,k;
    scanf("%d %d",&n,&k);

    long long* lst = (long long*)malloc(n*sizeof(long long));
    for(int i=0;i<n;i++){
        scanf("%lld",&lst[i]);
    }
    
    bool* pre = (bool*)malloc((n+1)*sizeof(bool));
    pre[0] = true;
    for(int i=1;i<=n;i++){
        if(i==1){
            pre[i] = true;
        }else{
            pre[i] = pre[i-1] && (lst[i-2]<=lst[i-1]);
        }
    }

    bool* suf = (bool*)malloc((n+1)*sizeof(bool));
    suf[n] = true;
    for(int i=n-1;i>=0;i--){
        if(i == n-1){
            suf[i] = true;
        }else{
            suf[i] = suf[i+1] && (lst[i] <= lst[i+1]);
        }
    }

    int ans = 0;
    for(int i=0;i<=n-k;i++){
        if(!pre[i]) continue;
        if(!suf[i+k])continue;

        if(i>0 && i+k<n){
            if(lst[i-1]>lst[i+k])continue;
        }
        ans++;
    }

    printf("%d\n",ans);

    free(lst);
    free(pre);
    free(suf);

    return 0;
}