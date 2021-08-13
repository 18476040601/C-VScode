/*
    输入两个正整数m和n ， 求其最大公约数和最小公倍数
*/

#include <stdio.h>

int main()

{
    int m, n, i, temp, p;
    printf("请输入两个正整数:\n");
    scanf("%d", &m);
    scanf("%d", &n);

    //最大值转换，最大值赋予m
    if (m < n)
    {
        temp = m;
        m = n;
        n = temp;
    }
    for (i = m; i >= 1; i--)
    {
        if (m % i == 0 && n % i == 0)
            break;
    }
    p = m * n / i;     //求最小公倍数
    printf("最大公约数为：%d\n", i);
    printf("最小公倍数为：%d\n", p);
}