/* 
题目：
    输入4个整数，找出其中最大的数。用函数的嵌套调用来实现
【解题思路】：
    在main函数中调用max4函数 ，max4函数的作用时找出4个数的最大者。
    在max4函数中再调用max2函数。max2函数的作用时找出2个数的最大者。
    max4函数通过不断调用max2函数来找出4个数中的最大者。
*/

// 求出两个数的最大者
int max2(int a, int b) //定义 max2 函数
{
    if (a >= b)
        return a;
    else
        return b;
}

// 通过调用 max2 函数来找出4个数的最大者
int max4(int a, int b, int c, int d) //定义 max4 函数
{
    int max2(int a, int b);
    int m;
    m = max2(a, b); // 调用max2函数，得到a和b中的最大者，放在m中
    m = max2(m, c);
    m = max2(m, d);
    return (m);
}

#include <stdio.h>

int main()

{
    int max4(int a, int b, int c, int d); // 对 max4 的函数声明
    int a, b, c, d, max;

    printf("please enter 4 interger numbers:"); // interger:整数型
    scanf("%d %d %d %d", &a, &b, &c, &d); 
          // 输入4个数，每个数用空格隔开
    max = max4(a, b, c, d);
    printf ("max=%d\n" , max) ;
    
    return 0;
}