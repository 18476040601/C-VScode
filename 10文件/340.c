/*
    将一个磁盘文件中的信息复制到另一个磁盘文件中。
解题思路：
    从file1.dat文件中逐个读入字符，然后逐个输出到file2.dat中
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in, *out;
    char ch, infile[10], outfile[10];

    printf("请输入读入文件的名字 ：");
    scanf("%s", infile);
    printf("请输入输出文件的名字 ：");
    scanf("%s", outfile);

    if ((in = fopen("infile", "w+")) == NULL)
    {
        printf("无法打开此读入文件\n");
        exit(0);
    }

    if ((out = fopen("outfile", "w+")) == NULL)
    {
        printf("无法打开此输出文件\n");
        exit(0);
    }

    ch = fgetc(in); // 从输入文件读入一个字符，赋给变量ch

    // feof(in)是用来判断 in 所指的文件是否结束了。!feof(in)则表示 in 所指的文件否结束
    while (!feof(in)) // 如果未遇到输入文件的结束标志
    {
        fputc(ch, out);
        putchar(ch);
        ch = fgetc(in);
    }

    putchar(10); // 显示完全部字符后换行
    fclose(in);
    fclose(out);

    return 0;
}