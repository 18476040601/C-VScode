/*
    使用枚举类型打印出一个月内的同学们的值班表
*/

#include <stdio.h>

void main()
{
    enum boy
    {
        Tom,
        Danny,
        Gan,
        Lilei
    } month[31], j;

    int i;

    j = Tom;

    for (i = 1; i <= 30; i++)
    {
        month[i] = j;
        j++;

        if (j > Lilei)
        {
            j = Tom;
        }
    }

    for (i = 1; i <= 30; i++)
    {
        switch (month[i])  // 表示当month[i]为以下几种情况的时候
        {
        case Tom:                               // 相当于case 0：即month[i]=0的时候，而Tom表示0
            printf("%4d   %s\t", i, "Tom");
            break;
        case Danny:                             // 相当于case 1：即month[i]=1的时候，而Danny表示1
            printf("%4d   %s\t", i, "Danny");
            break;
        case Gan:                               // 相当于case 2：即month[i]=2的时候，而Gan表示2
            printf("%4d   %s\t", i, "Gan");
            break;
        case Lilei:                             // 相当于case 3：即month[i]=3的时候，而Lilei表示3
            printf("%4d   %s\t", i, "Lilei");
            break;
        }
        if (i % 4 == 0)
        printf ("\n") ;
    }
    printf ("\n") ;
}