/*
题目：
    写一个函数,将一个字符串中的元音字母复制到另一字符串,然后输出。
题目解析:
    该题的重点在于元音字母的判断，通过或条件，凡是元音字母都进行拷贝
*/

#include <stdio.h>

char Con_Vowel(char c[], char s[] )
{
    int i, j;
    
    for (i = 0 , j = 0; s[i] != '\0'; i++)
    {
        //判断元音字母
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U')
        {
            c[j] = s[i];
            j++;
        }
    }
    c[j] = '\0';
}

int main()
{
    char c[100] = {0};
    char s[50]  = {0};
    //char string[100] = {0};

    printf("请输入字符串s1：");
    scanf("%s", c);

    printf("请输入字符串s2：");
    scanf("%s", s);

    printf("将s中的元音字母复制到c之后: ");

    Con_Vowel(c, s );
    printf("%s\n", c);

    return 0;
}
