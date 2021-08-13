/*
    将一个二维数组行和列的元素互换，存到另一个二维数组中。

        1  2  3          1  4
    a = 4  5  6      b = 2  5
                         3  6
*/

#include <stdio.h>

int main()

{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[3][2], i, j;
    printf("array a:\n"); //数组a为：
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%5d", a[i][j]);
            b[j][i] = a[i][j];
        }
        printf("\n");
    }
    printf("array b:\n");

    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 2; i++)
        {
            printf("%5d", b[j][i]);
        }
        printf("\n");
    }
    return 0;
}