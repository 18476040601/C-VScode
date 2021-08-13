/*
    输入两个整数，然后用户选择1,2或2，选1时调用max函数求最大值，选2时调用min函数求最小值.
    选3时求a和b的和.
    使用一个函数来把max，min，sum函数调用
    // 指向函数的指针
*/

#include <stdio.h>

int max(int x, int y)
{
    int z;
    if (x > y)
        z = x;
    else
        z = y;

    printf("max = ");

    return z;
}

int min(int x, int y)
{
    int z;
    if (x < y)
        z = x;
    else
        z = y;

    printf("min = ");

    return z;
}

int sum(int x, int y)
{
    int z;
    z = x + y;
    printf("sum = ");

    return z;
}

int fun(int x, int y, int (*p)(int, int)) // 声明形参p是指向函数的指针，整型函数，有两个整型实参
{
    int result;
    result = (*p)(x, y); // *p 表示调用的函数
    printf("%d\n", result);
}

int main()
{
    int a, b, n;

    printf("please input two integer numbers : ");
    scanf("%d %d", &a, &b);

    printf("please choose 1 , 2 or 3 : ");
    scanf("%d", &n);

    printf("a = %d\nb = %d\n", a, b);

    if (n == 1)
        fun(a, b, max);
    else if (n == 2)
        fun(a, b, min);
    else if (n == 3)
        fun(a, b, sum);
    else
    {
        printf("input error !!!\n");
        return -1;
    }

    return 0;
}
