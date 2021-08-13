/*
题目：
    编写一个函数,由实参传来一个字符串,统计此字符串中字母、数字、空格、制表键和其他字符的个数,
    在主函数中输人字符串以及输出上述的结果。
题目解析:
    该题的关键在于要能够写出各种字符统计的条件
*/

// WKS
#if (1)

#include <stdio.h>

int letter_num, figure_num, space_num, table_num, other_num;

void StaStr(char str[]) // 定义StaStr函数(统计字符)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))

            letter_num++;

        else if (str[i] >= '0' && str[i] <= '9')

            figure_num++;

        else if (str[i] == ' ')

            space_num++;

        else if (str[i] == '\t') // table 键

            table_num++;

        else

            other_num++;

    }
}

int main()

{
    char str[100];
    printf("please input string ：");
    fgets(str, 80, stdin); //stdin表示从键盘输入

    StaStr(str);
    printf("letter numbers : %d\n", letter_num);
    printf("figure numbers : %d\n", figure_num);
    printf("space  numbers : %d\n", space_num);
    printf("table  numbers : %d\n", table_num);
    printf("other  numbers : %d\n", other_num);

    return 0;
}

#endif

// CSDN
#if (0)

#include <stdio.h>

int letter, digit, space, others;

void CountChar(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        //统计字母
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            letter++;
        else if (str[i] >= '0' && str[i] <= '9') //统计数字
            digit++;
        else if (str[i] == ' ') //统计空格
            space++;
        else
            others++; //统计其他字符
    }
}

int main()
{
    char text[80];
    printf("input string:\n");
    fgets(text, 80, stdin); //stdin表示从键盘输入
    printf("string: %s\n", text);

    CountChar(text);
    printf("\nletter:%d\ndigit:%d\nspace:%d\nothers:%d\n", letter, digit, space, others);
    return 0;
}

#endif