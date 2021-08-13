/*
    将数组a中的n个整数按相反顺序存放，使用函数实现
*/

#if (0)

#include <stdio.h>

void reverse(int *x, int n)
{
    int *p, temp, *i, *j, m;

    m = (n - 1) / 2;
    i = x;         // i指向数组的首元素地址
    j = x + n - 1; // j指向数组的最后一个元素地址
    p = x + m;     // p指向中间元素地址

    for (; i <= p; i++, j--)
    {
        temp = *i;
        *i = *j;
        *j = temp;
    }
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;

    printf("The original array : \n");
    for (i = 0; i < 10; i++)
    {
        printf("%-4d", a[i]);
    }
    printf("\n");

    reverse(a, 10); // 实现数组倒序排放

    printf("The reverse array : \n");
    for (i = 0; i < 10; i++)
    {
        printf("%-4d", a[i]);
    }
    printf("\n");

    return 0;

    printf("相反顺序的数组为：\n");

    reverse(a, 10);

    return 0;
}

#endif

#if (1)

#include <stdio.h>

void reverse(int *a, int n)  // *a指向a[]
{
    int *p, i;
    p = a + (n - 1); // p指向数组最后一个元素

    for (i = 0; i < n ; i++)
    {
        printf("%-4d", *p--);
    }
    printf("\n");

    
    for (i = n-1; i >= 0 ; i--)
    {
        p = a + i ; // p指向数组第一个元素
        printf("%-4d", *p);
    }
    printf("\n");


    for (i = 0; i < n ; i++)
    {
        p = a + (n - i - 1) ; // p指向数组第一个元素
        printf("%-4d", *p);
    }
    printf("\n");


}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;

    printf("The original array : \n");
    for (i = 0; i < 10; i++)
    {
        printf("%-4d", a[i]);
    }
    printf("\n");

    printf("The reverse array : \n");
    reverse(a, 10); // 实现数组倒序排放

    return 0;
}

#endif