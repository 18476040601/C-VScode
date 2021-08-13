/*
    求Fibonacci(斐波那契数列)数列前40个数。这个数列有如下特点：
        第1，2两个数为1，1。从第3个数开始，该数是前面两个数之和
*/

#include <stdio.h>

int main()

{
    long int i, x, y, F[1000];

    printf("请输入F[1]的值=");
    scanf("%ld", &x);
    printf("请输入F[2]的值=");
    scanf("%ld", &y);

    printf("F[1]=%ld\n", x);
    printf("F[2]=%ld\n", y);
    F[1] = x;
    F[2] = y;

    for (i = 3; i <= 80; i++)
    {
        F[i] = F[i - 1] + F[i - 2];

        printf("F[%ld]=%ld\n", i, F[i]);
    }

    printf ("请输入你要查找斐波那契数列的第几个数：");
    scanf  ("%ld", &i);
    printf ("F[%ld]=%ld\n", i, F[i]);

    return 0;
}