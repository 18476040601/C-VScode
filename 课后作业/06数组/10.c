/*
题目：
    有一篇文章，共有3行文字，每行有80个字符。
    要求分别统计出其中英文大写字母、小写字母、数字、空格以及其他字符的个数。
【答案解析】
    获取文章中的3行文本，并对每行文本进行以下操作：
        1. 定义保存结果变量：upp、low、digit、space、other
        2. 遍历每行文本中的字符
        3. 如果该字符ch：ch >= ‘a’ && ch <=‘z’，则该字符是小写字母，给low++
        4. 如果该字符ch：ch >= ‘A’ && ch <=‘Z’，则该字符是小写字母，给up++
        5. 如果该字符ch：ch >= ‘0’ && ch <=‘9’，则该字符是小写字母，给digit++
        6. 如果该字符ch：ch == ’ '，则该字符是小写字母，给space++
        7. 否则为其他字符，给other++
    输入统计结果
*/

#include <stdio.h>

int main()

{
    char text[3][80];
    int i, j, upp=0, low=0, digit=0, space=0, other=0;

    for (i = 0; i < 3; i++)
    {
        // 获取一行文本
        printf("please input line %d:\n", i + 1);
        fgets(text[i], 80, stdin); //stdin表示从键盘输入

        // 统计该行文本中小写字母、大写字母、数字、空格、其他字符的个数
        for (int j = 0; j < 80 && text[i][j] != '\0'; j++)
        {
            if (text[i][j] >= 'A' && text[i][j] <= 'Z') // 大写字母
                upp++;
            else if (text[i][j] >= 'a' && text[i][j] <= 'z') // 小写字母
                low++;
            else if (text[i][j] >= '0' && text[i][j] <= '9') // 数字
                digit++;
            else if (text[i][j] == ' ') // 控制
                space++;
            else
                other++; // 其他字符
        }
    }

    printf("\nupper case : %d\n", upp);
    printf("lower case : %d\n", low);
    printf("digit      : %d\n", digit);
    printf("space      : %d\n", space);
    printf("other      : %d\n", other);

    return 0;
}