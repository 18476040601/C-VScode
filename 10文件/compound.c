/*
    制作一个文件图片合成器，通过修改后缀名来切换
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
    FILE *f_pic, *f_file, *f_finish;
    char ch, pic_name[20], file_name[20], finish_name[20];

    printf("请输入需要合成的图片和文件的名称 ：\n");
    printf("图片 ：");
    scanf("%s", pic_name);
    printf("文件 ：");
    scanf("%s", file_name);
    printf("生成为 ：");
    scanf("%s", finish_name);

    if (!(f_pic = fopen(pic_name, "rb")))
    {
        printf("无法打开该图片：%s !\n", pic_name);
        return;
    }
    if (!(f_file = fopen(file_name, "rb")))
    {
        printf("无法打开该文件：%s !\n", file_name);
        return;
    }
    if (!(f_finish = fopen(finish_name, "wb")))
    {
        printf("无法打开该新文件：%s !\n", finish_name);
        return;
    }

    while (!(feof(f_pic)))
    {
        ch = fgetc(f_pic);
        fputc(ch, f_finish);
    }
    fclose(f_pic);

    while (!(feof(f_file)))
    {
        ch = fgetc(f_file);
        fputc(ch, f_finish);
    }
    fclose(f_file);
    fclose(f_finish);

    pause();
}