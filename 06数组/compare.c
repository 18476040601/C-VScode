/*
    输入3个字符串，要求找出其中的"最大"者
*/

#include <stdio.h>
#include <string.h>

int main()

{
    char str[3][20], string[20];
    printf ("请输入字符：\n") ;
    for (int i = 0; i < 3; i++)
    {
        scanf ("%s" , str[i]) ;
        //fgets(str[i], 20, stdin); //stdin的意思是从键盘输入
    }
    if (strcmp(str[0], str[1]) > 0)
        strcpy(string, str[0]);
    else
        strcpy(string, str[1]);
    if (strcmp(str[2], string) > 0)
        strcpy(string, str[2]);

    printf("\nthe largest string is:\n%s\n", string);

    return 0;
}
