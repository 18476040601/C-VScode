/*
    不使用循环和递归，实现0~999的输出
解析：
    A(x)就是10个x语句，A(A(x))就是10个A(x)个语句，也就是100个x语句
    同理，A(A(A(x)))就是1000个x语句
    A(A(A(printf("%d",n++))));展开后就是1000个printf("%d",n++);不就是打印0到999么
*/

#include <stdio.h>

#define A(x) \
    x;       \
    x;       \
    x;       \
    x;       \
    x;       \
    x;       \
    x;       \
    x;       \
    x;       \
    x;

int main(void)
{
    int n = 0;

    A(A(A(printf("%d ", n++))));

    printf("\n");

    return 0;
}