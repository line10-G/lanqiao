/*
问题描述
把 1∼n 的 n 个正整数排成一行后随机打乱顺序，按字典序输出所有不同
的方案。

输入格式
输入一行，包含一个正整数 n(1≤n≤8)

输出格式
输出 n! 行，每一行为一种方案。字典序较小的先输出。
*/

#include <stdio.h>

int n;
int path[8];
int used[9];

void dfs(int depth){
    if(depth==n){
        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d",path[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=1;
            path[depth]=i;
            dfs(depth+1);
            used[i]=0;
        }
    }
}

int main(void){
    scanf("%d",&n);
    dfs(0);

    return 0;
}