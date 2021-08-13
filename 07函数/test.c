//函数调用

#include <stdio.h>

int main()

{
    void print_star() ;      //声明 print_star 函数
    void print_message() ;   //声明 print_message 函数
    print_star() ;           //调用 print_star 函数
    print_message() ;        //调用 print_message 函数
    print_star() ;           //调用 print_star 函数

    return 0 ;
}

    // 定义 print_star 函数
    void print_star()
    {
        printf ("*********************\n") ;    //输出一行 * 号
    }

    // 定义 print_message 函数
    void print_message()
    {
        printf ("Hello WKS!\n") ;    
    }
