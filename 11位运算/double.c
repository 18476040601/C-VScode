/*
    位运算符和赋值运算符可以组成复合赋值运算符
    例如 ：&= , |= , ^= , <<= , >>=
        a &= b  ;  相当于  a = a & b  ;
        a <<= 2 ;  相当于  a = a << 2 ;
*/

/*
题目：
    取一个 char a 从最右端开始的第2位到第5位
解题思路：
    1. 先使a右移 2 位 ，a >> 2
    2. 设置一个低4位全为1，其余全为 0 的数。考虑到不同编译器给一个数的字节不一定相同，则
       ~ (~0 << 4) 如果为 8 字节，则'0000 0000' --> '1111 1111' --> '1111 0000' --> '0000 1111'
    3. 结合1跟2，得到 ：  (a >> 2) & ~(~0 << 4)
*/

#include <stdio.h>

void main()
{
    char a  ;  

    printf ("请输入待检验的数字 : ") ;
    scanf ("%hhd" , &a) ; // 假设输入75 ，'0100 1011'
    
    a = (a >> 2) & ~(~0 << 4) ;  // 得到 '0010'

    printf ("\n得到的数字为 : %d\n" , a ) ; // 输出2
}
