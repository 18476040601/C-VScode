/*
    输入a和b两个整数，按大到小的顺序输出a和b。
*/

#include <stdio.h>

int main()

{
    int *p1, *p2, *p, a, b;
    printf("please enter two integer number : ");
    scanf("%d %d", &a, &b);
    printf("a = %d , b = %d\n", a, b);

    p1 = &a;
    p2 = &b;

    // 实现互换 ，把较大的值的地址取给p1
    if (a < b)
    {
        /* p1 = &b ; p2 = &a ; */  // 可改为这行
        p = p1;
        p1 = p2;
        p2 = p;
    }
    printf("max = %d , min = %d\n", *p1, *p2);
    return 0;
}