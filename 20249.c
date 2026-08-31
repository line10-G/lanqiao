/*
问题描述
如果一个数 p 是个质数，同时又是整数 a 的约数，则 p 称为 a 的
一个质因数。

请问，2024 的所有质因数的和是多少？
*/

#include <stdio.h>

// 计算 n 的所有不同质因数之和
int sumOfPrimeFactors(int n) {
    int sum = 0;

    // 检查 2
    if (n % 2 == 0) {
        sum += 2;
        while (n % 2 == 0) {  // 把 2 全部除掉
            n /= 2;
        }
    }

    // 检查奇数因子（3, 5, 7, ...）
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            sum += i;
            while (n % i == 0) {  // 把该因子全部除掉
                n /= i;
            }
        }
    }

    // 如果剩下的 n > 1，说明 n 本身是一个质因数
    if (n > 1) {
        sum += n;
    }

    return sum;
}

int main(void) {
    int n = 2024;
    printf("%d\n",sumOfPrimeFactors(n));
    return 0;
}