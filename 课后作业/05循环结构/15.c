/*
    用二分法求下面方程在(-10,10)的根:
    2 * x^3 - 4 * x^2 + 3x - 6= 0
    答案解析：
    将区间划分为两部分，记录区间左右端点，得到中点。每次运算将中点带入方程进行运算，求得结果，进行分析：
    结果 > 0：将中位数赋值给右端点
    结果 < 0：将中位数赋值给左端点
    以此类推…
    fabs函数是一个求绝对值的函数，求出x的绝对值，和数学上的概念相同;
    le-5：10^−5 , 即0.00001

*/

#include <stdio.h>
#include <math.h>

int main()
{
    double left = -10, right = 10, mid;
    double temp = 10;
    while (fabs(temp) > 1e-5)
    {
        mid = (left + right) / 2;
        //((2x - 4)*x + 3) * x - 6 ==> 2x^3 - 4x^2 + 3x -6
        temp = ((2 * mid - 4) * mid + 3) * mid - 6;

        if (temp > 0)
        {
            right = mid;
        }
        else if (temp < 0)
        {
            left = mid;
        }
    }
    printf("在(-10,10)的根为：%lf\n", mid);
    return 0;
}
