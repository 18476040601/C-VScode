#include <stdio.h>

void main()

{
    int i = 2000;
    int *pointer;    // 表示定义指针变量
    pointer = &i ;   // &表示取址操作符 ， pointer存放的是i的地址
    printf ("%d\n" , *pointer) ; // *表示取值操作符，*pointer表示取存放在i地址里的值
}