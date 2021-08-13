/*
    将若干字符串按字母顺序（由小到大）输出
解题思路：
    定义一个指针数组name，用个字符串对它进行初始化，即把各字符串中第1个字符的地址赋给指针数组的各元素。
    然后用选择法排序，但不是移动字符串，而是改变指针数组的各元素的指向
*/

#include <stdio.h>
#include <string.h>

void sort(char *name[], int n)
{
    char *temp;
    int i, j, k;

    // 用选择法排序
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)

            /*  strcmp(str1 , str2) 会根据 ASCII 编码依次比较 str1 和 str2 的每一个字符，
            直到出现不到的字符，或者到达字符串末尾（遇见\0）。
                返回值：
                如果返回值 < 0，则表示 str1 小于 str2。
                如果返回值 > 0，则表示 str2 小于 str1。
                如果返回值 = 0，则表示 str1 等于 str2。  */
            if (strcmp(name[k], name[j]) > 0)
                k = j;

        if (k != i)
        {
            temp = name[i];
            name[i] = name[k];
            name[k] = temp;
        }
    }
}

void print(char *name[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%s\n", name[i]);
}

int main()
{
    char *name[] = {"follow me", "BASIC", "Great Wall", "FORTRAN", "Computer design"};

    int n = 5;
    sort(name, n);
    print(name, n);

    return 0;
}