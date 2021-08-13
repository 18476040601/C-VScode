/*
题目：
    写一个函数,将两个字符串连接。
题目解析:
    利用一个临时数组，空间要保证能够容纳两个字符串，先把第一个字符串进行拷贝到临时数组，
    第二个字符串在临时数组的尾部接着链接，最后记得加上字符串的结束标记\0即可
*/

// WKS
#if (1)

#include <stdio.h>

char ConnectStr(char s1[], char s2[])
{
    int index1 = 0, index2 = 0;
    // 1. 找到s1的末尾
    while ('\0' != s1[index1])
        index1++;

    // 2. 将s2中的字符逐个往s1之后拼接
    while (s1[index1++] = s2[index2++])
        ;
}

int main()
{
    char s1[100] = {0};
    char s2[50] = {0};
    //char s3[100] = {0};

    printf("请输入字符串s1：");
    scanf("%s", s1);

    printf("请输入字符串s2：");
    scanf("%s", s2);

    printf("将s2拼接在s1之后: ");

    ConnectStr(s1, s2);
    printf("%s\n", s1);

    return 0;
}

#endif

// CSDN

#if (0)

#include <stdio.h>

void ConcatStr(char string1[], char string2[], char string[])
{
    int i, j;
    for (i = 0; string1[i] != '\0'; i++)
        string[i] = string1[i];

    //找到字符串末尾，继续往后面链接字符串
    for (j = 0; string2[j] != '\0'; j++)
        string[i + j] = string2[j];

    //字符串末尾加上结束符 \0
    string[i + j] = '\0';
}

int main()
{
    char s1[200] = {0}, s2[100] = {0}, s[100] = {0};
    printf("input string1: ");
    scanf("%s", s1);
    printf("input string2: ");
    scanf("%s", s2);
    ConcatStr(s1, s2, s);
    printf("\nThe new string is:  %s\n", s);
    return 0;
}

#endif
