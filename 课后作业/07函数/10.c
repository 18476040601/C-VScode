/*
题目：
    写一个函数,输入一行字符,将此字符串中最长的单词输出。
题目解析:
    单词以空格进行分隔，因此寻找空格出现的位置即为关键，
    每次从单词的起始到空格出现的位置即为一个单词，此时计算单词的长度，
    如果比当前最大的还长，就进行跟新最长单词信息，当整个字符串遍历完成，word即保存最长字符串。
*/

#include <stdio.h>
#include <string.h>

void LongestWord(char str[], char word[])
{
    int max_len = 0;
    int len = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            str[i] = '\0';
            len = strlen(str);
            if (len > max_len)
            {
                max_len = len;
                strcpy(word, str);
                str = str + (len + 1);  // 表示str字符串前面舍去(len + 1)个字符 ,len个字符加1个空格字符
            }
        }
        i++;
    }
}

int main()
{
    char line[100] = {0};
    char word[100] = {0};
    printf("input one line:\n");
    fgets(line , 100 ,stdin);  // stdin 表示从键盘输入

    LongestWord(line, word);

    printf("The longest word is : %s\n", word);
    return 0;
}
