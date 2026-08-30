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