/*
    从键盘读入若干个字符串，对他们按字母大小的顺序排序，然年把排序好的字符串送到txt文件中保存
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *fp ;
    char str[3][10] , temp[10] ;
    int i , j , k , n = 3 ;

    printf ("Enter strings : \n") ;
    for (i = 0 ; i < n ; i++)
    fgets (str[i] , 10 , stdin) ; // stdin 表示从键盘输入

    for(i = 0 ; i < n-1 ; i++)  // 用选择排序法对字符串进行排序
    {
        k = i ;
        for (j = i + 1 ; j < n ; j++)
        if (strcmp(str[k] , str[j]) > 0) 
        k = j ;

        if (k != i)
        {
            strcpy(temp , str[i]) ;
            strcpy(str[i] , str[k]) ;
            strcpy(str[k] , temp) ;

        }
    }

    if ( ! (fp = fopen("string.txt" , "w")))
    {
        printf ("cannot open file ! \n") ;
        exit(0);
    }

    printf ("\nThe new sequence : \n") ;
    for (i = 0 ; i < n ; i++)
    {
        fputs(str[i], fp) ;
        fputs("\n" , fp) ;
        printf ("%s" , str[i]) ;
    }
    printf ("\n") ;
}