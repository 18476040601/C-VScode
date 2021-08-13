/*
    将字符串a复制为字符串b，然后输出字符串b。
*/

#include <stdio.h>

#if (0)
// 下标法
int main()
{
    char a[] = "I am a good boy.", b[20];
    int i;
    for (i = 0; *(a + i) != '\0'; i++)
    {
        *(b + i) = *(a + i); // 将a[i]的值赋给b[i]
    }
    *(b + i) = '\0'; // 在b数组的有效字符之后加上'\0'表示结束

    printf("string a is : %s\n", a);

    printf("string b is : ");
    for (i = 0; b[i] != '\0'; i++)
    {
        printf("%c", b[i]);
    }
    printf("\n");

    return 0;
}
#endif

#if (0)
//    指针变量法
int main()
{
    int i;
    char a[] = "I am a good boy.", b[20], *p1, *p2;
    p1 = a;
    p2 = b; // p1, p2分别指向a和b数组的第一个元素

    for (int i = 0; a[i] != '\0'; i++)
    {
        *(p2 + i) = *(p1 + i); // 相当于b[i] = a[i]
    }
    //*(p2 + i) = '\0';

    /*
    for (; *p1 != '\0' ; p1++ , p2++)
    {
        *p2  = *p1 ;  // 将p1所指向的值赋给p2所指向的值
    }
    *p2 = '\0' ;  // 在复制完全部字符后加'\0'
*/

    printf("string a is : %s\n", a);
    printf("string b is : %s\n", b);

    return 0;
}

#endif

#if(1)
// 用指针变量处理，用函数实现
int main()
{
    

    return 0;
}

#endif