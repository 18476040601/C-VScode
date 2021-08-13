/*
    求 1！+2！+3！+4！+......+20! 
    且：    1!=1
            2!=2*1
            3!=3*2*1
            ……
            ……
            19!=19*18*17……3*2*1
            20!=20*19*18*17……3*2*1
*/

#include <stdio.h>

int main()

{
    int m, n ;
    double  q=0 ;
    for (m = 1; m <= 20; m++)
    {
        double p = 1 ;
        for (n = m; n > 0; n--)
        {
            p *= n;  //p = p *n ;
        }
            q += p;  //q = q +p ;
    }
    printf("1~20每个数字阶乘总和为:%lf\n", q);
    return 0;
}