/*
    用指针方法对10个整数按大到小顺序排序
*/

#include <stdio.h>

void sort(int x[], int n)
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (x[j] < x[j + 1]) //相邻两个进行比较
            {
                //互换
                t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            }
        }
    }
}

int main()

{
    int i, *p, a[10];
    p = a;

    printf("please input 10 integer numbers : \n");
    for (i = 0; i < 10; i++)
    {
        p = a + i;
        scanf("%d", p);
    }

    p = a;  // 指针变量重新指向a[0] , 必须要有
    sort(p, 10);

    printf("The sort array is :\n");
    for (i = 0; i < 10; i++)
    {
        p = a + i;
        printf("%-4d", *p);
    }
    printf("\n");

    return 0;
}