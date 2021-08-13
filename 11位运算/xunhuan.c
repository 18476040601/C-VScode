/*
    要求将 a 循环移位 ， 即如果 a 右移了n位，则把移出的n位补充到左边的高位
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    unsigned char a, b, c, finish;
    int n;

    printf("请输入需要实现循环移位的数   ： ");
    scanf("%hhd", &a);
    printf("请输入需要实现循环右移的位数 ： ");
    scanf("%d", &n);

    b = a >> n;
    c = a << (sizeof(char) * 8 - n);
    finish = c | b;

    printf("\n结果是 : %d\n", finish);
}

