/*
题目：
    写两个函数,分别求两个整数的最大公约数和最小公倍数,用主函数调用这两个函数,并输出结果。两个整数由键盘输人。
题目解析：
    该题直接使用“辗转相除法”来求解最大公约数和最小公倍数
    最大公约数找出两数中的最小值，然后直接相模，当能够同时被两数整除时，则为最大公约数。
    最小公倍数找出两数中的最大值，然后直接进入死循环，直到找到一个数能够同时被两数整除时，则为最小公倍数
【注】此题还有一些比较高级的解法，比如求最大公约数的相减法、欧几里德辗转相除法等，有兴趣的同学可以查询相关资料
*/

// WKS
#if (0)

#include <stdio.h>

// 最大公约数
int GCD(int m, int n) // 定义 GCD 函数 (greatest common divisor : 最大公约数)
{
    int i, temp;

    if (m < 0 || n < 0)
    {
        printf("input error!!!\n");
    }
    if (m > 0 && n > 0)
    {
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
        return i;
    }
}

// 最小公倍数
int LCM(int m, int n) //定义 LCM 函数 (lowest common multiple : 最小公倍数)
{
    int GCD(int m, int n);
    int lcm, k;
    k = GCD(m, n);
    lcm = m * n / k;
}

int main()
{
    int GCD(int m, int n);
    int LCM(int m, int n);

    int a, b;
    int gcd, lcm;

    printf("please input 2 positive intger:\n"); // 输入两个正整数
    scanf("%d %d", &a, &b);
    printf("\n");

    gcd = GCD(a, b);
    lcm = LCM(a, b);
    printf("%d和%d的最大公约数为：%d\n", a, b, gcd);
    printf("%d和%d的最小公倍数为：%d\n", a, b, lcm);

    return 0;
}

#endif

// CSDN
#if (1)

#include <stdio.h>

//最大公约数
size_t GCD(size_t a, size_t b)
{

     /* 
    size_t 它是一种“整型”类型，里面保存的是一个整数，就像int、long那样。
    这种整数用来记录一个大小（size）。size_t的全称应该是size type，就是说“一种用来记录大小的数据类型”。
     */
    size_t gcd;
    gcd = a > b ? b : a;
    while (gcd > 1)
    {
        if ((a % gcd == 0) && (b % gcd == 0))
            return gcd;
        gcd--;
    }
    return gcd;
}

//最小公倍数
size_t LCM(size_t a, size_t b)
{
    size_t lcm;
    lcm = a > b ? a : b;
    while (1)
    {
        if ((lcm % a == 0) && (lcm % b == 0))
            break;
        lcm++;
    }
    return lcm;
}

int main()
{
    size_t a, b, result;
    printf("请输入两个整数:> ");
    scanf("%ld %ld", &a, &b);

    result = GCD(a, b);
    printf("%ld和%ld的最大公约数为:%ld\n", a, b, result);
    result = LCM(a, b);
    printf("%ld和%ld的最小公倍数为:%ld\n", a, b, result);

    return 0;
}

#endif