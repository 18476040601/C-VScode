/*
题目：
    编一程序，将两个字符串连接起来，不要用strcat函数。
【答案解析】
    直接将s2中的字符逐个拷贝到s1的末尾即可，用户需要保证s1中能存的下s2中的字符
        1. 获取s1末尾的位置
        2. 将s2中的字符逐个拷贝到s1中
*/

#include <stdio.h>

int main()
{
    char s1[100] = {0};
    char s2[50] = {0};
    int index1 = 0, index2 = 0;
    printf("请输入字符串s1：");
    scanf("%s", s1);

    printf("请输入字符串s2：");
    scanf("%s", s2);

    printf("将s2拼接在s1之后: ");
    // 1. 找到s1的末尾
    while ('\0' != s1[index1])
        index1++;

    // 2. 将s2中的字符逐个往s1之后拼接
    while (s1[index1++] = s2[index2++]) ;

    printf("%s\n", s1);
    return 0;
}
