#include <stdio.h>

void main()

{
    printf ("当前文件名 : %s\n" , __FILE__ ) ; // 打印当前文件名

    printf ("当前函数名 : %s\n" , __FUNCTION__ ) ; // 打印当前函数名

    printf ("当前函数名 : %s\n" , __func__ ) ; // 打印当前函数名

    printf ("当前行号为 : %d\n" , __LINE__ ) ; // 打印当前行号

    printf ("当前日期为 : %s\n" , __DATE__ ) ; // 打印包含当前日期的字符串

    printf ("非零值     : %d\n" , __STDC__ ) ; // 如果编译器遵循ANSI C标准，它就是个非零值

    printf ("当前时间为 : %s\n" , __TIME__ ) ; // 打印包含当前时间的字符串


    #line 200   //指定下一行的__LINE__为200
    printf ("当前行号为 : %d\n" , __LINE__ ) ; // 打印当前行号
    printf ("当前行号为 : %d\n" , __LINE__ ) ; // 打印当前行号

}