/*
    求Sn=a + aa + aaa + aaaa + ....+aa..aa(n个a) 的值 ，其中a是一个<10的数字 ，n表示a的位数，
    a ，n由键盘输入 。
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int a, m, n, p = 0, q = 0;
    printf("请输入一个小于10的数a为：");
    scanf("%d", &a);
    printf("请输入要计算的位数：");
    scanf("%d", &n);

    for (m = 0; m < n; m++)
    {

        p = a * pow(10, m) + p; //pow(10,m) 表示10的n次方
        q = p + q;
    }
    printf("该数列的和为：%d\n", q);

    return 0;
}