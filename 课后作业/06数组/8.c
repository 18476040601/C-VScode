/*
题目：
    找出一个二维数组中的鞍点，即该位置上的元素在该行上最大，在该列上最小，也可能没有鞍点。
【答案解析】
    鞍点是行上最大，列上最小的元素，因此对数组的第i元素进行如下操作：
        1. 找到该行上最大元素，用max标记，并标记该元素所在列colindex
        2. 找colindex列上最小的元素，用min标记，并标记该元素所在行号rowindex
        3. 如果max和min相等，并且最小的元素刚好是在第i行，则为鞍点
    如果所有行找完了，没有输出则没有鞍点
*/

#if (1)
#include <stdio.h>

//宏定义M、N为全局变量 ， 后面不用加分号(;)
#define M 3
#define N 4

int main()

{
    int array[M][N];
    int i, j, k, max, min, rowindex, colindex, flag = 0; //rowindex行指数，colindex列指数

    printf("请输入%d行%d列的数组:\n", M, N);
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("\n");

    printf("该%d行%d列的数组为:\n", M, N);
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%-4d", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < M; i++)
    {
        // 找到i行上最大的元素,记录该元素在列号colindex
        max = array[i][0];
        for (j = 0; j < N; j++)
        {
            if (array[i][j] > max)
            {
                max = array[i][j];
                colindex = j;
            }
        }

        // 找max所在列colindex上最小的元素，并记录其所在的行
        min = max;
        for (int k = 0; k < M; k++)
        {
            if (array[k][colindex] < min)

                min = array[k][colindex];
            rowindex = k;
            break;
        }

        // 如果最小元素与最小元素相同，并且最小元素也在第i行，则为鞍点
        if (max == min)
        {
            //flag = 1;
            printf("鞍点为：第%d行%d列的元素a[%d][%d]=%d\n", rowindex, colindex, rowindex, colindex, max);
            break;
        }
    }

    if (max != min)
        printf("该数组没有鞍点\n");

    return 0;
}

#endif
