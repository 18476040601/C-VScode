/*
    从键盘输入4个学生的有关数据，然后把它们以二进制的形式存储到磁盘文件中
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void save(); // 定义函数 save 。向文件输出SIZE个学生的信息
void load(); // load 函数将文件读取并显示出来

struct Student_type
{
    int num;
    char name[10];
    int age;
    char addr[20];

} stud[SIZE];

/*****************************向文件输入信息********************************/
void save() // 定义函数 save 。向文件输出SIZE个学生的信息
{
    FILE *fp;
    int i;

    if (!(fp = fopen("stu.dat", "wb"))) // 打开输出文件，以只写二进制的模式
    {
        printf("cannot open file !!!\n");
        return;
    }

    printf("Please enter data of students : \n");
    printf("(num / name / age / addr)\n");

    for (i = 0; i < SIZE; i++)
    {
        scanf("%d %s %d %s", &stud[i].num, stud[i].name, &stud[i].age, stud[i].addr);

        if (fwrite(&stud[i], sizeof(struct Student_type), 1, fp) != 1) // 写数据stu[i]输入文件中
        {
            printf("file write error !!!");
            fclose(fp);
        }
    }

    fclose(fp);
}

/*****************************文件读取并显示*******************************/
void load() // load 函数将文件读取并显示出来
{
    FILE *fp;
    int i;

    if (!(fp = fopen("stu.dat", "rb"))) // 打开输出文件，以只写二进制的模式
    {
        printf("cannot open file !!!\n");
        return;
    }

    printf("\nThe data of students :\n");
    printf("\nnum / name   /   age / addr\n");

    for (i = 0; i < SIZE; i++)
    {
        fread(&stud[i], sizeof(struct Student_type), 1, fp); // 从文件中读取数据stu[i]

        printf("%-5d %-10s %-5d %-15s\n", stud[i].num, stud[i].name, stud[i].age, stud[i].addr);
    }

    fclose(fp);
}

int main()
{

    save();
    load();

    return 0;
}