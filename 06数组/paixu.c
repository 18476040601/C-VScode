/*
    用冒泡法（起泡法）对10个数排序，由大到小。
    思路：将相邻两个数比较，将小的调到前面。
*/

#include <stdio.h>

int main()

{
    int a[10];
    int i, j, t;
    printf("input 10 numbers:\n"); // 输入10个数字
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n");
    for (j = 0; j < 9; j++)         // 进行9次循环，实现9趟比较
                                    //{
        for (i = 0; i < 9 - j; i++) //在每一趟中进行9-j次比较

        {
            if (a[i] > a[i + 1]) //相邻两个进行比较
            {
                //互换
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
        }

    printf("the sorted numbers :\n"); //数字排列顺序为
    for (i = 0; i < 10; i++)
    {
        printf("%5d", a[i]);
    }
    printf("\n");
    return 0;
}