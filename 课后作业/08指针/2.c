/*
题目：
     输入3个字符串，要求按由小到大的顺序输出。
解题思路： 
    字符串的比较可以使用strcmp函数，返回值>0表示大于，返回值小于0表示小于，返回追等于0表示相同。
    其他的比较排序思路与数字的排序交换没有区别，逐个进行比较先找出最大的，然后找出第二大的。
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
    char name[3][32];  //后边的数字(32)限制缓冲区边界，防止缓冲区溢出访问越界
    char *p[3];
    printf("Please enter three strings:");
    for (int i = 0; i < 3; i++)
    {
        p[i] = name[i];
        scanf("%s", p[i]); 
    }
    //printf ("\n") ;

    printf("The three strings :  ");
    for (int i = 0; i < 3; i++)
    {
        p[i] = name[i];
        printf ("%s    ", p[i]); 
    }
    printf ("\n") ;

    int n = 3;
    sort(p, n);
    
    printf ("Sort strings from smallest to largest : \n") ;
    print(p, n);

    return 0;
}