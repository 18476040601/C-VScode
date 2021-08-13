/*
    从键盘输入一些字符，并逐个把它们送入到磁盘上去，直到用户输入一个“#”结束。
解题思路：
    用fgets函数从键盘逐个输入字符，然后用fputs函数写到磁盘上。
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp; // 定义头文件指针fp ；
    char ch , filename[20];

    printf("请输入所用的文件名 ：");
    scanf("%s", filename);

    ch = getchar();                               // 用来消化最后输入的回车符
    if ((fp = fopen(filename, "wt+")) == NULL) // 打开输出文件并使fp指向该文件
    {
        printf("cannot open the file ! \n"); // 如果打开出错就输出“打不开”
        exit(0);                      // 终止程序
    }

    printf("请输入一个准备存储到磁盘的字符串（以#结束）：\n");

    ch = getchar(); // 接收从键盘输入的第一个字符

    while (ch != '#')
    {
        fputc(ch, fp);  // 向磁盘文件输出一个字符
        putchar(ch);    // 将输出的字符显示在屏幕上
        ch = getchar(); // 再接收从键盘输入的一个字符
    }

    fclose(fp);  // 关闭文件
    putchar(10); // 向屏幕输出一个换行符

    return 0;
}