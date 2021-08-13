/*
    输入a和b两个整数，按大到小的顺序输出a和b ，使用函数处理。
*/

#include <stdio.h>

void swap(int *p1 , int *p2)  // 定义 swap (交换)函数
{
    int temp ;
    temp = *p1 ;
    *p1 = *p2 ;
    *p2 = temp ;
}

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
    swap(p1 , p2) ;

    printf("max = %d , min = %d\n", *p1, *p2);
    return 0;
}

