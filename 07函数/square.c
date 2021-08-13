/*
    探索sqrt()函数的原理，即开平方根函数的原理,先要求只输入整形数据
*/

#include <stdio.h>

int main()
{
    int square(int n);
    int n, s;
    printf("请输入你要求开平方根的正整数：");
    scanf("%d", &n);
    s = square(n);
    printf("该数的开平方根为：%d\n", s);
    return s;
}

int square(int n)
{
    if (n < 0)
        return n;
    int a = 0, b = n, mid, last;
    mid = (a + b) / 2;
    if (mid * mid == n)
    return mid ;
    
    // 采用二分法（未解决）
    if (mid * mid > n)
    {
       b = mid;

    }
            b = mid;
        if (mid * mid < n)
            a = mid;
        last = mid ;
        mid = (a + b) / 2;
    

    return mid;
}