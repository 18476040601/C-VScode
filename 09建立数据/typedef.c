#include <stdio.h>

// 声明了一个型类型名Date，代表那个结构体类型
typedef struct 
{
    int month ;
    int day ;
    int year ;
}DATE;

// 命名一个新的类型名代表数组类型
typedef int NUM[100] ;  

// 命名一个新的类型名代表指针类型
typedef char* STRING ;

// 命名一个新的类型名代表指向指针函数的指针类型
typedef int (*POINTER)();

int fun () ;
int main()
{
    DATE birthday ;
    birthday.year = 2000 ;
    birthday.month = 9 ;
    birthday.day = 25 ;

    printf ("%d - %d - %d\n" , birthday.year , birthday.month , birthday.day) ;


    NUM a ;  // 定义a为整型数组名，它有100个元素
    printf ("%ld\n" , sizeof(a)) ;  // 输出为400


    STRING p = {"WKS"} ;
    printf ("%s\n" , p) ; // 输出WKS


    POINTER p1 ;
    p1 = fun ;
    (p1)() ;

    return 0 ;
}

int fun()
{
    printf ("Wukansheng\n") ;
}
