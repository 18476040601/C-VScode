/*
    有一个3*4的矩阵，要求编程序求出其中最大的元素的值，以及其所在的行号和列号。
*/

#include <stdio.h>

int main()

{
    int i, j, row = 0, colum = 0, max; // row:行  colum:列
    int a[3][4] = {{1, 2, 3, 4}, {9, 8, 7, 6}, {-10, 10, -5, 2}};
    max = a[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];  //最大数赋值给max
                row = i;
                colum = j;
            }
        }
    }
    printf("max=%d\nrow=%d\ncolum=%d\n", max, row, colum);
    return 0;
}