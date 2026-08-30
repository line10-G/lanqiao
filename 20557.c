/*
问题描述
如果一个正整数只能被 1 和它本身整除，就称为一个质数。

最小的几个质数依次是 2,3,5,7,11,13,….

请问，第 2025 个质数是多少？
*/
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n)
{
    if (n < 2)
        return false;
    if (n < 4)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    int count = 0;
    int n = 1;

    while (count < 2025)
    {
        n++;
        if (is_prime(n))
            count++;
    }

    printf("%d\n",n);
    return 0;
}