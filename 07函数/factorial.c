/*
    用递归的方法求 n！（n的阶乘）
        思路：5！ = 4！ * 5 ，4！ = 3！ * 4；
        即：n = 1  （n = 0 ，1）
            n * (n-1)!
*/

#include <stdio.h>

long recursion(int n); //声明递归函数

int main()
{
    int n;
    long result;

    printf("please input a integer number:\n");
    scanf("%d", &n);

    result = recursion(n);
    printf("%d! = %ld\n", n, result);

    // 求 n！+(n-1)! + (n-2)! + ………… + 1
    long sum = 0;

    for (int i=n; i > 0; i--)
    {
        sum += recursion(i) ;
        printf("%d! = %ld\n", i, recursion(i));
    }
    printf("从%d！逐渐加上退1的阶乘加到1结果为：%ld\n", n, sum);

    return 0;
}

# if (1)

// 使用递归方法
long recursion(int n) //定义递归函数
{
    long temp_result;   //temp : 临时
    if (n < 0)
    {
        printf("n < 0 , input error!\n");
    }
    else if (n == 0 || n == 1)  // 0 的阶乘为1！！！
    {
        temp_result = 1;
    }
    else
    {
        temp_result = recursion(n - 1) * n;
    }
    return temp_result;
}

#endif