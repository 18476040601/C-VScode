/*
    通过指向结构体变量的指针变量以及怎样使用它
*/

#include <stdio.h>
#include <string.h>

struct Student
{
    long num;
    char name[20];
    char sex[10];
    float score;
};

int main()
{
    struct Student stu_1 = {101, "Wu", "Boy", 95.5};
    struct Student *p = &stu_1;

    printf("No.%ld\nname  : %s\nsex   : %s\nscore : %-6.2f\n",
           stu_1.num, stu_1.name, stu_1.sex, stu_1.score);

    printf("\nNo.%ld\nname  : %s\nsex   : %s\nscore : %-6.2f\n",
           (*p).num, (*p).name, (*p).sex, (*p).score);

    return 0;
}