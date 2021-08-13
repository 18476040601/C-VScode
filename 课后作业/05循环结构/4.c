/*
    输入一行字符，分别统计出其中英文字母、空格、数字和其他字符的个数
*/

#include <stdio.h>

int main()

{
    char c;
    //定义eng_char为英文字母的个数，初始值为0
    //定义space_char为空格字符的个数，初始值为0
    //定义digit_char为数字字符的个数，初始值为0
    //定义other_char为其他字符的个数，初始值为0
    int eng_char = 0, space_char = 0, digit_char = 0, other_char = 0;

    printf("请输入字符：");
    c = getchar();
    while (c != '\n')
    {
        //字符A~Z的ASCII值为65~90 ， a~z的为97~102 。a=A+32；
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') 
        {
            eng_char++;
        }
        else if (c ==' ') //空格的ASCII值为16，控制字符为' '

        {
            space_char++;
        }
        else if (c >= '0' && c <= '9')  //字符'0'~'9' 的ASCII值为 48~57

        {
            digit_char++;
        }
        else
        {
            other_char++;
        }

        c = getchar();
    }
    printf("英文字母的个数为%d个\n空格个数为%d个\n", eng_char, space_char);
    printf("数字个数为%d个\n其他字符个数为%d个\n", digit_char, other_char);
    return 0;
}
