/*
题目：
    编写一个程序，将字符数组s2中的全部字符复制到字符数组s1中，不用strcpy函数。
    复制时，‘\0’也要赋值过去。’\0’之后的字符不复制。
【答案解析】
    首先必须保证s1能否放的下s2中的字符，然后将s2中的每个字符逐个搬移到s1中即可。
*/

#include <stdio.h>

int main()
{
    char s1[100] = {0};
    char s2[50] = {0};
    int index1 = 0, index2 = 0;
    printf("请输入字符串s2：");
    scanf("%s", s2);

    printf("将s2拷贝到s1中, s1现在为: ");

    // 将s2[index2]位置字符拷贝到s1[index]位置，
    // 然后以s1[index1]的值作为循环条件判断是否拷贝到s2的末尾
    while (s1[index1++] = s2[index2++])
        ;
    printf("%s\n", s1);
    return 0;
}
