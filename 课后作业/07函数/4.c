/*
题目：
    写一个函数,使给定的一个3X3的二维整型数组转置,即行列互换。
题目解析：
    进行数组的行列互换，其关键在于数组互换的表达式 ar[i] [j] = ar[j] [i];
    其次在循环的时候，内层循环不能到达最大列，需要根据此时是第几行的交换来决定循环的次数，
    否则有可能数组行列交换之后最后又交换回原来的形状了。
*/

#include <stdio.h>

#define M 3
#define N 3

// 打印数列
void PrintArray(int array[M][N])
{
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%-4d", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void ChangeArray(int array[M][N])
{
    int i, j, temp;
    for (i = 0; i < M ; i++)
    {
        for (j = 0; j < i ; j++)
        {
            if (i != j)  //中间数不发生变化
            {
                // 互换
                temp = array[i][j];
                array[i][j] = array[j][i];
                array[j][i] = temp;
            }
        }
    }
}

int main()
{
    int array[M][N] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};

    printf("转置前的数组为：\n");
    PrintArray(array);

    ChangeArray(array); // 进行数组转置

    printf("转置前后的数组为：\n");
    PrintArray(array);

    return 0;
}
