/*
    枚举类型的默认值为0、1、2.......
*/

#include <stdio.h>

void main()
{
    //enum Weekday {sun , mon , tue , wed , thu , fri , sat} ; 
    // Weekday为枚举名，花括号里为枚举元素为常量，不能在花括号外面对他们赋值。
    // 例如sun = 0，mon = 1是错的.枚举类型的默认值为0、1、2.......。最后输出 0 1 2 3 4 5 6

    enum Weekday {sun = 7 , mon = 1 , tue , wed , thu , fri , sat} ;
    // 指定枚举常量sun的值为7，mon的值为1，以后的顺序则逐步加1，sat为6
    // 最后输出 7 1 2 3 4 5 6


    enum Weekday a[7];  // a[7]为枚举变量，它们的值只限于花括号中的指定的值之一，即sun到sat之一

    a[0] = sun ;  // 不能
    a[1] = mon ;
    a[2] = tue ;
    a[3] = wed ;
    a[4] = thu ;
    a[5] = fri ;
    a[6] = sat ;

    for (int i = 0 ; i < 7 ; i++)
    {
        printf ("%-4d" , a[i]) ;
    }
    printf ("\n") ;

}