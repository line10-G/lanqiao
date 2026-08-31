/*
问题描述
在一条一维的直线上，存在 n 台显示器和 n 个电源插座。
老师给小蓝布置了一个任务：将每台显示器通过电源线与一个插座相连
接（每个插座最多只能给一台显示器供电）。
同时，老师希望所消耗的电源线长度尽可能少。
请计算电源线的最小消耗长度（只需考虑直线距离）。

输入格式
输入的第一行包含一个正整数 n.
接下来 n 行，每行包含一个整数 xi , 依次表示每台显示器的坐标。
接下来 n 行，每行包含一个整数 yi , 依次表示每个插座的坐标。

输出格式
输出一行包含一个整数，表示电源线的最小消耗长度。

评测用例规模与约定
对于 20% 的评测用例，1≤n≤10, 0≤ xi,yi ≤100;
对于 40% 的评测用例，1≤n≤100, 0≤ xi,yi ≤10^3 ;
对于 60% 的评测用例，1≤n≤1000, 0≤ xi,yi ≤10^5 ;
对于 80% 的评测用例，1≤n≤10000, 0≤ xi,yi ≤10^9 ;
对于所有评测用例，1≤n≤50000, 0≤ xi,yi ≤10^9 。
*/

#include <stdio.h>
#include <stdlib.h>

int cmp_asc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main(void){
    int n;
    scanf("%d",&n);

    int xsq[50000]={0};
    int cz[50000]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&xsq[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&cz[i]);
    }

    qsort(xsq,n,sizeof(int),cmp_asc);
    qsort(cz,n,sizeof(int),cmp_asc);

    long long res=0;
    for(int i=0;i<n;i++){
        res += (long long)abs(xsq[i]-cz[i]);
    }
    printf("%lld",res);

    return 0;
}

/*
题目描述
一条走廊上有 n 间会议室和 n 个团队，每间会议室有一个容量 cᵢ，
每个团队有一个人数 pᵢ。
要求：把每个团队分配到恰好一间会议室（一一对应），使得所有分配
满足约束的前提下，总浪费空间最小（浪费空间 = 容量 - 人数，仅对
容量 ≥ 人数的配对计）。
约束：每间会议室的容量必须 ≥ 分配到的团队人数，否则该方案非法。
如果不存在合法方案，输出 -1。

输入格式
第一行一个正整数 n。
接下来 n 行，每行一个整数 cᵢ，表示每间会议室容量。
接下来 n 行，每行一个整数 pᵢ，表示每个团队人数。

输出格式
输出一行一个整数，表示最小总浪费空间；若不存在合法方案，输出 -1。
*/
/*
#include <stdio.h>
#include <stdlib.h>

int cmp_asc(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(void){
    int n;
    scanf("%d",&n);

    int mtc[50000]={0};
    int number[50000]={0};
    for(int i=0;i<n;i++)scanf("%d",&mtc[i]);
    for(int i=0;i<n;i++)scanf("%d",&number[i]);

    qsort(mtc,n,sizeof(int),cmp_asc);
    qsort(number,n,sizeof(int),cmp_asc);

    // long long res = 0;
    // long long waste;
    // for(int i=0;i<n;i++){
    //     waste = (long long)mtc[i] - number[i];
    //     if(waste<0){
    //         res = -1;
    //         break;
    //     }else{
    //         res += waste;
    //     }
    // }
    // printf("%lld",res);

    long long waste = 0;
    for (int i = 0; i < n; i++) {
        long long waste = (long long)mtc[i] - number[i];
        if (waste < 0) {
            printf("-1\n");
            return 0;        // 直接退出，不用管 res
        }
        res += waste;
    }
    printf("%lld\n", res);

    return 0;
}
*/