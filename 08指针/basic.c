#include <stdio.h>

void main()
{
    int a[5] = {1, 3, 5, 7, 9};

    int *p1 , *p2 ,m , n;

    p1 = a + 1 ;
    p2 = a + 4 ;

    m = p2 - p1 ;   // 两个指针之间的元素个数，输出m为3
    n = *p2 - *p1 ; // 两个指针所指向的值的差，输出n为6

    printf ("m = %d\nn = %d\n" , m , n) ;
}