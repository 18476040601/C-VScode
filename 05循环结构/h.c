#include <stdio.h>

int  main ()
{
    int i,j;
    for ( i=6 ; i<7&&i>0; i--)
    {
        
        for ( j=1; j<=i ; j++)
        {
            printf("*");
        }

        printf("\n"); 

    }
    return 0;
}