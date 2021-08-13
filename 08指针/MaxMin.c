/*
    输入两个整数，然后用户选择1或2，选1时调用max函数求最大值，选2时调用min函数求最小值
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

    return z;
}

int min(int x, int y)
{
    int z;
    if (x < y)
        z = x;
    else
        z = y;

    return z;
}

int main()
{
    int (*p)(int, int);
    int a, b, c, n;

    printf("please input two integer numbers : ");
    scanf("%d %d", &a, &b);

    printf("please choose 1 or 2 : ");
    scanf("%d", &n);

    if (n == 1)
        p = max;
    else if (n == 2)
        p = min;
    else
    {
        printf("input error!!!\n");
        return -1;
    }

    printf("a = %d\nb = %d\n", a, b);

    c = (*p)(a, b);
    if (n == 1)
        printf("max = %d\n", c);
    else
        printf("min = %d\n", c);

    return 0;
}
