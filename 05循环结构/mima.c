/*
    译密码！！使电文保密，往往按一定规律将其转换成密码，收报人再按约定的规律将其翻译
        例如：将字母A变成字母E，a变成e，即变成其后的第四个字母，W变成A，X变成B，Z变成D。
            密码电文互相转换。
*/

#include <stdio.h>

int main()

{
    char i, j;
    printf("请输入电文：");
    i = getchar();
    printf("密码为：");
    while (i != '\n')
    {
        if (i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z')
        {
            if (i >= 'w' && i <= 'z' || i >= 'W' && i <= 'Z')
                i = i - 22;
            else
                i = i + 4;
        }

        printf("%c", i);

        i = getchar();
    }

    printf("\n");

    printf("请输入密码：");
    j = getchar();
    printf("电文为：" );
    while (j != '\n')
    {
        if (j >= 'a' && j <= 'z' || j >= 'A' && j <= 'Z')
        {
            if (j >= 'a' && j <= 'd' || j >= 'A' && j <= 'D')
                j = j + 22;
            else
                j = j - 4;
        }

        printf("%c", j);
        j = getchar();
    }

    printf("\n");
    return (0);
}