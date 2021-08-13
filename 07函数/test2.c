/*
    看函数时自左向右顺序求实参的值，还是自右向左求实参的数
*/

#if (1)

#include <stdio.h>

int main() //使用stdcall调用方法(即自右向左)
{
    int f(int a, int b);
    int i = 2, p;

    p = f(i, ++i);
    printf("%d\n", p);

    return 0;
}

int f(int a, int b)
{
    int c;
    if (a > b)
    {
        c = 1;
    }
    if (a == b)
    {
        c = 0;
    }
    else
    {
        c = -1;
    }
    return c;
}

#endif

#if (0)

#include <stdio.h>
int main(void) //使用stdcall调用方法(即自右向左给实参赋值)

{
    int i = 8;
    printf("%d\n%d\n%d\n%d\n", ++i, --i, i++, i--); // 输出结果是8, 7, 8, 8
    printf("%d\n%d\n", ++i, ++i);                   //输出结果是10 ，10
    printf("%d\n%d\n", ++i, i++);                   //输出结果是10 ，12

/*  
    //输出结果是 9,8,8,9      
    printf("%d\n",++i);
    printf("%d\n",--i);
    printf("%d\n",i++);
    printf("%d\n",i--); 
 */

/*
    //输出结果是 8,7,7,8
    printf("%d\n",i--);
    printf("%d\n",i++);
    printf("%d\n",--i);
    printf("%d\n",++i); 
*/
    return 0;
}

#endif
