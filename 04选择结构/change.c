#include <stdio.h>

int main()


{
    char ch;
    scanf("%c" , &ch);

    if (ch>='A'&&ch<='Z')
        ch = ch + 32;
    else
        ch = ch ;

    printf ("%c\n" , ch);

    return 0;

}