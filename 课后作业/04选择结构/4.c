#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a > b)
    {
        if (a > c)
            printf("最大的数为：a=%d\n", a);
        else
            printf("最大的数为：c=%d\n", c);
    }
    else
    {
        if (b > c)
            printf("最大的数为：b=%d\n", b);
        else
            printf("最大的数为：c=%d\n", c);
    }
    return 0;
}