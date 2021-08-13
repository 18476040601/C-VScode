/*
题目：
    求一个3 X 3的整形矩阵对角线元素之和
【答案解析】
    矩阵：即二维数组，矩阵行和列相等的二维数组称为方阵。
    1 2 3
    4 5 6
    7 8 9
    左上角到右下角对角线上数字：行下标和列下标相等
    右上角到左下角对角线上数字：列下标减1 行下标加一
    通过两个循环来取到对角线上的元素，并对其求和即可。
*/

#if (1)

#include <stdio.h>

int main()

{
    int i, j, sum1 = 0, sum2 = 0, sum = 0;
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

/*  也可输入矩阵数值

     printf("请输入3行3列的矩阵：\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    }
*/

    //左上角到右下角之和
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
                sum1 += a[i][j];
        }
    }

    //左下角到右上角之和
    for (i = 0, j = 2; i < 3; i++, j--)
    {

        sum2 += a[i][j];
    }
    sum = sum1 + sum2;

    printf("左上角到右下角对角线元素之和: %d\n", sum1);
    printf("右上角到左下角对角线元素之和: %d\n", sum2);
    printf("该数组对角线数字之和为:%d\n", sum);
}

#endif

#if (0)

#include <stdio.h>
int main()
{
    int array[3][3];
    int sumLT2RB = 0; // 标记左上角到右下角对角线元素之和
    int sumRT2LB = 0; // 标记右上角到左下角对角线元素之和
    printf("请输入3行3列的矩阵：\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            scanf("%d", &array[i][j]);
    }

    // 左上角到右下角对角线
    for (int i = 0; i < 3; i++)
        sumLT2RB += array[i][i];

    for (int i = 0, j = 2; i < 3; i++, j--)
        sumRT2LB += array[i][j];

    printf("左上角到右下角对角线元素之和: %d\n", sumLT2RB);
    printf("右上角到左下角对角线元素之和: %d\n", sumRT2LB);
    return 0;
}

#endif