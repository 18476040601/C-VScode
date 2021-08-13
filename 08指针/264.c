#include <stdio.h>

void main()
{
    char *a = "I love China !";
    printf("%s\n", a);

    a = a + 7; // 改变指针变量的值，即改变指针变量的指向 ,从指针变量a所指向的元素开始逐个输出字符
    printf("%s\n", a);

    char b[] = "I am a good boy !" ;
    char *p ;

    p = b ;  // p指向b数组首元素地址
    printf ("%s\n" , p) ;   // 输出b数组
    printf ("%d\n" , *p) ;  // 输出b数组首元素I的ASCII的值73

}