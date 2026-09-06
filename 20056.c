/*
问题描述
威慑纪元 2230 年，人类联邦在与三体文明的对抗中，为了强化飞船的
能源储备，决定收集能量晶体。飞船的储存空间呈矩形，边长分别为 a 
和 b。对于一个能量晶体，只有当它的长度小于或等于存储空间的对角
线长度时，它才能被安全地放入飞船中。
现在，人类联邦总共收集了 n 个能量晶体。你的任务是判断每根能量晶
体是否可以放入飞船。

输入格式
第一行包含两个整数 a 和 b（1≤b≤a≤10^3 ），表示飞船储存空间的
长和宽。
接下来一行包含一个整数 n（1≤n≤10^3 ），表示能量晶体的数量。
再接下来 n 行，每行包含一个整数 c（1≤c≤10^4 ），表示每根能量晶
体的长度。

输出格式
对于每根能量晶体，输出一行：
如果该晶体可以放入，输出 YES。
如果该晶体不能放入，输出 NO。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int a,b;
    scanf("%d %d",&a,&b);
    double diag = sqrt(a*a + b*b);
    int n;
    scanf("%d",&n);
    int len[1001]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&len[i]);
    }
    for(int i=0;i<n;i++){
        if(len[i]<=diag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

/*
问题描述
威慑纪元 2230 年，人类联邦的飞船储存空间呈矩形，边长分别为 a 
和 b。
此前收集的能量晶体都是一维线段，只需比对对角线即可。但新一代能
量晶体是矩形晶体片，每片有自己的宽 wi和高 hi 。
晶体的放置规则如下：
每片晶体必须完全位于储存空间内部（可以贴边）。
晶体可以旋转 90°（即宽高互换），但不能斜放。
任意两片晶体的区域不得重叠（可以共享边界）。
人类联邦收集了 n 片能量晶体，请你判断：是否能把全部 n 片晶体同
时放入储存空间？

输入格式
第一行包含三个整数 a, b, n（1 ≤ b ≤ a ≤ 20，1 ≤ n ≤ 8），分别
表示储存空间的长、宽和晶体数量。
接下来 n 行，每行两个整数 wi ,hi（1≤wi,hi≤20），表示第 i 片晶
体的宽和高。

输出格式
如果能将全部晶体放入，输出 YES；否则输出 NO。
*/
/*
#include <stdio.h>

// 箱子的网格：grid[x][y] = 1 表示这个格子被某块积木占了，0 表示空着
int grid[20][20];
int a, b, n;
int w[8], h[8]; // 每块积木的宽和高

// 检查：把第 idx 块积木放在 (x,y) 位置，宽 ow 高 oh，能不能放
// 检查三件事：不超边界 + 不和已放的积木重叠
int can_place(int x, int y, int ow, int oh) {
    // 超出箱子右边界或下边界 → 放不下
    if (x + ow > a || y + oh > b) return 0;
    // 逐个格子检查，看有没有被占过
    for (int i = x; i < x + ow; i++)
        for (int j = y; j < y + oh; j++)
            if (grid[i][j]) return 0; // 这个格子已经有人了
    return 1; // 全部格子都是空的，能放
}

// 把第 idx 块积木放到 (x,y)，宽 ow 高 oh
// 放下去 = 把这些格子标记成"被占了"
void place(int x, int y, int ow, int oh, int val) {
    for (int i = x; i < x + ow; i++)
        for (int j = y; j < y + oh; j++)
            grid[i][j] = val; // val=1 表示放上，val=0 表示拿走
}

// 核心函数：尝试放下第 idx 块积木（以及它后面的所有积木）
// 返回 1 = 全部放下了，返回 0 = 这条路走不通
int solve(int idx) {
    if (idx == n) return 1; // 所有积木都放完了，成功！

    // 第一步：面积剪枝——剩下的积木面积总和如果超过剩余空格数，直接放弃
    int remain = 0;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            if (!grid[i][j]) remain++;
    int need = 0;
    for (int i = idx; i < n; i++)
        need += w[i] * h[i];
    if (need > remain) return 0; // 空间不够，不用试了

    // 第二步：枚举这块积木的两种朝向
    for (int rot = 0; rot < 2; rot++) {
        int ow, oh; // 这块积木当前的宽和高
        if (rot == 0) { ow = w[idx]; oh = h[idx]; }       // 原样放
        else           { ow = h[idx]; oh = w[idx]; }       // 转 90°

        // 第三步：枚举箱子里每个位置
        for (int x = 0; x < a; x++) {
            for (int y = 0; y < b; y++) {
                // 能不能放这里？
                if (can_place(x, y, ow, oh)) {
                    // 能放 → 放下去
                    place(x, y, ow, oh, 1);
                    // 递归：试着放下一块
                    if (solve(idx + 1)) return 1; // 后面全成功了！
                    // 后面失败了 → 把这块拿走，换个位置再试
                    place(x, y, ow, oh, 0); // 撤回
                }
            }
        }
    }
    return 0; // 两种朝向、所有位置都试过了，都不行
}

int main() {
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &w[i], &h[i]);

    // 先清空网格
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            grid[i][j] = 0;

    // 开始摆，从第 0 块开始
    if (solve(0))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
*/