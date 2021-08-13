/*
题目：
    写一个函数,使输人的一个字符串按反序存放,在主函数中输入和输出字符串。
题目解析：
    要把一个字符串反序存放，其实就是对字符串做一个逆序操作，操作过程为收尾字符交换，直到把所有字符全部交换完毕。
*/

#include <stdio.h>
#include <string.h>

void ReverseString(char str[])
{
    int start, end;
    char tmp;
    start = 0;
    end = strlen(str) - 1; //字符数组小标从0开始，所以-1
    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;

        start++;
        end--;
    }
}

int main()
{
    char str[100] = {0};
    printf("请输入一个字符串: ");
    scanf("%s", str);
    printf("原始字符串为: %s\n", str);
    ReverseString(str);
    printf("反序字符串为: %s\n", str);
    return 0;
}