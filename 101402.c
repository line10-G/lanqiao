/*
问题描述
小蓝需要将 N 份材料从服务站分别送往 N 栋宿舍楼，每栋宿舍楼一份。其
中，服务站到第 i 栋宿舍楼的最短路程为 Di 米，往返的路程相同。
为了运送材料，小蓝从服务站借来了一辆小推车。这辆小推车每次只能装一
份材料，因此小蓝送完一份材料后，如果还有材料需要配送，就要回到服务
站领取下一份。当全部材料配送完毕后，小蓝可以直接结束工作，不必再次
返回服务站。
为了尽量减少行走路程，小蓝可以自行安排这 N 栋宿舍楼的配送顺序。现
在，请你计算他完成全部配送至少需要行走多少米。

输入格式
第一行包含一个整数 N（1≤N≤10^5），表示需要配送的材料数量。
第二行包含 N 个整数 D1,D2,…,DN（1≤Di≤10^9），表示各宿舍楼到服务
站的距离。

输出格式
输出一个整数，表示完成全部配送的最短路程。
*/

/*
#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    long long d[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&d[i]);
    }

    long long max = d[0];
    for(int i=1;i<n;i++){
        max = max<d[i]?d[i]:max;
    }

    long long res = 0;
    for(int i=0;i<n;i++){
        res += 2*d[i];
    }
    res -= max;

    printf("%lld", res);

    return 0;
}
*/

#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    
    long long sum = 0;  // 累加所有距离
    long long max = 0;  // 记录最大距离
    
    for (int i = 0; i < n; i++) {
        long long d;
        scanf("%lld", &d);
        sum += d;
        if (d > max) {
            max = d;
        }
    }
    
    // 总路程 = 2 * 总距离 - 最大距离（最后一趟不用返回）
    long long res = 2 * sum - max;
    
    printf("%lld\n", res);
    return 0;
}
