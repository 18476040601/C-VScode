/*
    有若干个人员的数据，其中有学生和教师。学生的数据包括：姓名、号码、性别、职业和班级。
    老师的数据包括：姓名、号码、性别、职业和职务。要求用一个表格来处理。
*/

#include <stdio.h>

struct // 声明无名结构体类型
{
    int num;
    char name[10];
    char sex;
    char job;

    union // 声明无名共用体类型
    {
        int clas;
        char position[10];
    } category; // 成员category是共用体变量
} person[2];    // 定义结构体数组person，有两个元素

int main()
{
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("please enter the data of person : \n");
        printf("The N0.%d person :\n", i);

        printf("pelase enter the num      : ");
        scanf("%d", &person[i].num);

        printf("pelase enter the name     : ");
        scanf("%s", person[i].name);

        printf("pelase enter the sex(M/F) : ");
        scanf("%c", &person[i].sex);

        printf("pelase enter the job(s/t) : ");
        scanf("%c", &person[i].job);

        // 如果为学生，则输入班级
        if (person[i].job == 's')
        {
            printf("pelase enter the clas     : ");
            scanf("%d", &person[i].category.clas);
        }
        // 如果为老师，则输入职务
        else if (person[i].job == 't')
        {
            printf("pelase enter the position : ");
            scanf("%s", person[i].category.position);
        }
        else
            printf("\nInput error !!!\n");

        printf("\n");
    }
    printf("\n");

    for (i = 0; i < 2; i++)
    {
        if (person[i].job == 's')
        {
            printf("The N0.%d person is a student :\n", i);
            printf("num   : %d\n", person[i].num);
            printf("name  : %s\n", person[i].name);
            printf("sex   : %c\n", person[i].sex);
            printf("job   : %c\n", person[i].job);
            printf("clas  : %d\n", person[i].category.clas);
        }
        else
        {
            printf("The N0.%d person a teacher :\n", i);
            printf("num   : %d\n", person[i].num);
            printf("name  : %s\n", person[i].name);
            printf("sex   : %c\n", person[i].sex);
            printf("job   : %c\n", person[i].job);
            printf("position : %s\n", person[i].category.position);
        }
    }
    return 0;
}
