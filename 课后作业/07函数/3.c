/* 
题目：
    写一个判素数的函数,在主函数输人一个整数,输出是否为素数的信息。
题目解析：
    素数是一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数叫做素数
    该题可以使用概念直接判断法求解，不过不需要判断所有的数据，只需要判断数据的一半即可，
    因为偶数不可能为素数（除了2）,所以只需判断该数的一半即可的到答案
*/

// WKS
#if (1)

#include <stdio.h>
#include <math.h>

int prime(int p)
{
    int i, m;
    m = sqrt(p);
    for (i = 2; i <= m; i++)
    {
        if (p % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    //int prime(int p) ;
    int p, q;

    printf("请输入一个整数: ");
    scanf("%d", &p);
    q = prime(p);

    if (q == 1)
        printf("%d 为素数\n", p);
    else
        printf("%d 不为素数\n", p);
}

#endif

// CSDN
#if (0)

#include <stdio.h>
#include <stdbool.h>

bool IsPrime(int value)
{
    for (int i = 2; i < value / 2; ++i)
    {
        if (value % i == 0) //说明除了1和本身之外，还能被其他数整除
            return false;   //false是布尔类型的变量，表示假。
    }
    return true; //true是布尔类型的变量，表示真。
}

int main()
{
    int value;
    bool flag;
    printf("请输入 value :>");
    scanf("%d", &value);

    flag = IsPrime(value);

    if (flag) // 如果为真
        printf("%d 是素数.\n", value);
    else
        printf("%d 不是素数.\n", value);

    return 0;
}

#endif