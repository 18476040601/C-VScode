/*  形参和实参建的数据传递
    形参 ：在定义函数时函数名后面括号钟的变量名称为“形式参数”(简称形参)或“虚拟参数”。
           （可以说是定义的类型，int、float、double%……等等）
           例如：int x ，int y ， x和y为形参
    实参 ：在主函数中调用一个函数时，函数名后面括号中的参数称为“实际参数”(简称实参)。
           实参可以是常量、变量或表达式。
*/

#include <stdio.h>

int main()

{
    int max(int x, int y); //对max函数的声明
    int a, b, c;
    printf("please enter two integer numbers :"); //提示输入数据
    scanf("%d,%d", &a, &b);                       //输入数据,中间用逗号隔开(注意为英文逗号)
    c = max(a, b);                                //调用max函数，有两个实参。大数赋给变量c
    printf("max is %d\n", c);                     //输出最大数c

    return 0;
}

// 编写max函数
int max(int x, int y) // 定义 max 函数，有两个形参
{
    int z;             //定义临时变量z

    // 条件表达式 z=x>y?x:y 分为条件表达式1？表达式2：表达式3 
    //若条件1 (x>y) 为真则返回表达式2(即返回x)， 若为假则返回表达式3(即返回y)
    z = x > y ? x : y; //把x和y中的最大者赋给c
    return (z);
}