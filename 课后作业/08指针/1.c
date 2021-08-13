/*
题目：
    输入3个整数，要求按由小到大的顺序输出。
解题思路：
    先获取到三个变量的地址，然后获取三个数据，通过指针进行比较转换即可
*/

// WKS
#if (1)

#include <stdio.h>

void sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[3];
    int i, *p;

    printf("please enter 3 integer numbers : ");
    for (i = 0; i < 3; i++)
    {
        p = a + i;
        scanf("%d", p); // p 指向&a[i]
    }

    printf("The 3 integer numbers  : ");
    for (i = 0; i < 3; i++)
    {
        p = a + i;
        printf("%-5d", *p); // *p 指向a[i]的值
    }
    printf("\n");

    sort(a, 3);
    printf("The sort of numbers is : ");
    for (i = 0; i < 3; i++)
    {
        p = a + i;
        printf("%-5d", *p); // *p 指向a[i]的值
    }
    printf("\n");

    return 0;
}

#endif

// CSDN
#if (0)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *p_a, int *p_b)
{
    int temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;
}
int main()
{
    int a, b, c, *p_a = &a, *p_b = &b, *p_c = &c; // 获取每个变量空间的地址
    printf("Please enter three numbers:");
    scanf("%d %d %d", p_a, p_b, p_c);
    if (*p_a > *p_b)
    {
        swap(p_a, p_b); //通过指针进行指向空间内的数据交换
    }
    if (*p_a > *p_c)
    {
        swap(p_a, p_c);
    }
    if (*p_b > *p_c)
    {
        swap(p_b, p_c);
    }
    printf("%d %d %d\n", *p_a, *p_b, *p_c);

    // system("pause")  是暂停的意思，等待用户信号；不然控制台程序会一闪即过，你来不及看到执行结果。
    // system("pause");  // 非linux 下的写入方式

    // 是暂停的意思，等待用户信号；不然控制台程序会一闪即过，你来不及看到执行结果。
    // pause () ; // linux 下的实现保留控制台的效果的 写入方式

    return 0;
}

#endif