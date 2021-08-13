/*
    输出数组中的全部元素
*/

#include <stdio.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p, i;

    printf("This array is:\n");
    // 通过数组名计算数组元素的地址 ， 找出元素的值
    for (i = 0; i < 10; i++)
    {
        printf("%-3d", *(a + i)); // (a + i)表示a[i]的地址 , (a + i) 等价于 &a[i] 。
    }
    printf("\n");


    printf("This array is:\n");
    // 用指针变量指向数组元素
    for (i = 0; i < 10; i++)
    {
        p = a + i; // (a + i)表示a[i]的地址，p的值为a[i]的地址
        printf("%-3d", *p);
    }
    printf("\n");


    printf("This array is:\n");
    // 用指针变量指向数组元素
    for (p = a; p < (a + 10); p++) // 先使p的值是数组a首元素，(a + i)表示a[i]的地址
    {
        printf("%-3d", *p);
    }
    printf("\n");

    return 0;
}