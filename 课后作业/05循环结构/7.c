/*
    求(1+2+3+......+100) + (1+2^2+3^2+.....+50^2) + (1 + 1/2 + 1/3 + ......+1/10)
*/

#include <stdio.h>

int main()

{

    double sum = 0, sum1 = 0, sum2 = 0, sum3 = 0.0;
    for (int m = 1; m <= 100; m++)
    {
        sum1 += m;

        if (m <= 50)
        {
            sum2 += m * m;
        }
        if (m <= 10)
        {
            sum3 += 1.0 / m;
        }
    }

    sum = sum1 + sum2 + sum3;
    printf("该数列值为：%lf\n", sum);
    return 0;
}