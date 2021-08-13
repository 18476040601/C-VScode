/* 
题目：
    求方程  a * x^2 + bx + c = 0 的根,用3个函数分别求当: 
    b^2−4ac大于0、等于0和小于0时的根并输出结果。从主函数输入a,b,c的值。
题目解析:
    根据disc = b^2 - 4ac 的值来决定如何求根，题目本身编程不难，不过需要同学们复习一下高中的数学知识哦。
*/

// WKS
#if (1)

#include <stdio.h>
#include <math.h>

double x1, x2, disc;

void ROOT(double a, double b, double c)
{

    disc = b * b - 4 * a * c;
}

// disc > 0
void greater(double a, double b, double c)
{
    void ROOT(double a, double b, double c);
    //if (disc > 0)

    x1 = (-b + sqrt(disc)) / (2 * a);
    x2 = (-b - sqrt(disc)) / (2 * a);

    printf("disc>0 的根为: x1 = %lf    x2 = %lf\n", x1, x2);
}

// disc == 0
void equal(double a, double b, double c)
{
    void ROOT(double a, double b, double c);
    //if (disc == 0)
    x1 = x2 = (-b) / (2 * a);
    printf("disc==0 的根为: x1 = x2 = %lf\n", x1);
}

// disc < 0
void smaller(double a, double b, double c)
{
    double p, q;
    void ROOT(double a, double b, double c);
    //if (disc < 0)

    p = -b / (2 * a);
    q = sqrt(-disc) / (2 * a);
    x1 = p + q;
    x2 = p - q;

    printf("disc<0 的根为: x1 = %f+%f\tx2 = %f-%f\n", p, q, p, q);
}

int main()
{
    int a, b, c;
    printf("请输入 a b c : ");
    scanf("%d %d %d", &a, &b, &c);
    printf("表达式为: %d*x^2 + %d*x + %d = 0\n", a, b, c);

    ROOT(a, b, c);
    if (disc > 0)
    {
        greater(a, b, c);
    }

    if (disc == 0)
    {
        equal(a, b, c);
    }

    if (disc < 0)
    {
        smaller(a, b, c);
    }

    return 0;
}

#endif

// CSDN
#if (0)

#include <stdio.h>
#include <math.h>

//x1为第一个根，x2为第二个根
float x1, x2, disc, p, q;

void greater_than_zero(float a, float b)
{
    float m = sqrt(disc);
    x1 = (-b + sqrt(disc)) / (2 * a);
    x2 = (-b - sqrt(disc)) / (2 * a);
}

void equal_to_zero(float a, float b)
{
    x1 = x2 = (-b) / (2 * a);
}

void smaller_than_zero(float a, float b)
{
    p = -b / (2 * a);
    q = sqrt(-disc) / (2 * a);
}

int main()
{
    int a, b, c;
    printf("请输入 a b c:");
    scanf("%d %d %d", &a, &b, &c);

    printf("表达式为: %d*x^2+%d*x+%d = 0\n", a, b, c);
    disc = b * b - 4 * a * c;

    if (disc > 0)
    {
        greater_than_zero(a, b);
        printf("disc>0的根为: x1=%f    x2=%f\n", x1, x2);
    }
    else if (disc == 0)
    {
        equal_to_zero(a, b);
        printf("disc==0的根为:x1=%f    x2=%f\n", x1, x2);
    }
    else
    {
        smaller_than_zero(a, b);
        printf("disc<0的根为:x1=%f+%f x2=%f-%f\n", p, q, p, q);
    }
    return 0;
}

#endif