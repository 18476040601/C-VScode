#include <stdio.h>

int main()
{
    double power(double a, double b);
    double a, b, result;
    printf("请输入你要求的数的幂次方: ");
    scanf("%lf %lf", &a, &b);
    result = power(a, b);
    printf("%lf的%lf次方为：%lf\n", a, b, result);
    return 0;
}

double power(double a, double b)
{
    int i ;
    double c = 1.0 ;
    for (i=1 ; i<=b ; i++)
    {
        c *= a ;
    }
    return c;
}
