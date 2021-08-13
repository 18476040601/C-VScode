#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

int main()
{
    float a, b;
    scanf("%f", &a);
    if (a >= 1000 || a < 0)
    {
        printf("请输入小于1000的正数\n");
        scanf("%f", &a);
        b = sqrt(a); //sqrt 求平方根
    }
    else
    {
        b = sqrt(a);
    }
    printf("a=%4.0f, b=%4.0f\n", a, b);
    system("pause"); //这一句是为了让控制台不退出
    return 0;
}
