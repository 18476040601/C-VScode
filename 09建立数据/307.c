/*
    有n个结构体变量，内含学生学号、姓名和3门课程成绩。要求输出平均成绩最高的学生信息和平均成绩。
    使用结构体变量的指针函数。
*/

#include <stdio.h>
#define N 3

struct Student
{
    int num;
    char name[20];
    float score[3];
    float aver;
};

void input(struct Student stu[])
{
    int i;
    printf("请输入各学生的信息 ：学号、姓名、3门课程成绩 ： \n");

    for (i = 0; i < N; i++)
    {
        scanf("%d %s %f %f %f", &stu[i].num, stu[i].name, &stu[i].score[0],
              &stu[i].score[1], &stu[i].score[2]);

        stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
    }

    printf("\n这%d名学生的信息为 ： \n", N);
    for (i = 0; i < N; i++)
    {
        printf("No.%d\nname  : %s\nscore : %-6.2f %-6.2f %-6.2f\naverage score : %-8.2f\n\n",
               stu[i].num, stu[i].name, stu[i].score[0], stu[i].score[1],
               stu[i].score[2], stu[i].aver);
    }
}

struct Student max(struct Student stu[])
{
    int i, m = 0;
    for (i = 0; i < N; i++)
    {
        if (stu[i].aver > stu[m].aver)
            m = i;
    }

    return stu[m];
}

void print(struct Student stud)
{
    printf("\n成绩最高的学生为 ：\n");
    printf("No.%d\nname  : %s\nscore : %-6.2f %-6.2f %-6.2f\naverage score : %-8.2f\n",
           stud.num, stud.name, stud.score[0], stud.score[1], stud.score[2], stud.aver);
}

int main()
{
    struct Student stu[N], *p = stu;

    input(p);
    print(max(p));

    return 0;
}