/*
题目：
    有一个已经排好序的数组，要求输入一个数后，按原来顺序的规律将它插入数组中 
*/

#include <stdio.h>

int main()

{
    int array[11] = {1, 2, 3, 7, 8, 13, 16, 19, 39, 78};
    int i, j, num;
    printf("原数组序列为:\n");
    for (int i = 0; i < 10; i++)
        printf("%-4d", array[i]);
    printf("\n");

    printf("请输入一个正整数：");
    scanf("%d", &num);

    for (i = 0; i < 10; i++)
    {
        if (num <= array[i])
            break;
    }
    j = i;

    for (i = 10; i > j; i--)
    {
        array[i] = array[i - 1];
    }
    array[j] = num;

    printf("新的数组排序为:\n");
    for (i = 0; i < 11; i++)
    {
        printf("%-4d", array[i]);
    }
    printf("\n");

    return 0;
}