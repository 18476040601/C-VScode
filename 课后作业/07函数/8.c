/*
题目：
    写一个函数,输人一个4位数字，要求输出这4个数字字符,但每两个数字间空一个空格。
    如输人1990,应输出“1 9 9 0”。
题目解析:
    对字符串进行遍历输出，没输出一个字符，后面就跟着输出一个空格，
    关键点在于如果输出的是最后一个字符，则不能在输出字符，所以要对是否是最后一个字符的输出进行判断。
*/

// WKS
#if (1)

#include <stdio.h>

#define M 4 // 宏定义

void AddSpace(char s[] )
{
    int i = 0 ;

    printf("输出字符为：");

    while (s[i] != '\0')
    {
        printf ("%c" , s[i]) ;
        if (s[i + 1] == '\0')
        break;
        printf (" ") ;
        i++ ;
    }
    printf ("\n") ;
}

int main()

{
    char s[M];
    printf("请输入%d位数字：" , M);
    scanf("%s", s);

    AddSpace(s);
    

    return 0;
}

#endif

// CSDN
#if (0)

#include <stdio.h>

void OutString(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        if (str[i + 1] == '\0') //清除最后一个空格不输出
            break;
        printf("%c", ' ');
        i++;
    }
    printf("\n");
}
int main()
{
    char str[5] = {0};
    printf("input four digits:");
    scanf("%s", str);
    OutString(str);

    return 0;
}

#endif