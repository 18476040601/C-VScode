/*
    求1~200之间的全部素数打印出来
*/

#include <stdio.h>
#include <math.h>

int main()

{
    int m, n, i ;
    //printf("请输入一个正数：");
    //scanf("%d", &m);
    
    //printf("%d\n", i);

    for (m = 1; m <= 200; m++)
    {
        i = sqrt(m); //i = m开根号
        for (n = 2; n <= i; n++) //如果为素数的话，n会执行到>i
        {
            if (m % n == 0)
                break;
        }
        if (n > i)
            printf("%d\t" , m);
        //else
        //    printf("该数不为素数\n");
    }
        printf ("\n");
    return 0;
}