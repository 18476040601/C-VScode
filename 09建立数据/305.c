/*
    有3个学生的信息，放在结构体数组中，要求输出全部学生的信息，通过指向结构体变量的指针变量
*/

#include <stdio.h>
#include <string.h>

struct Student
{
    long num;
    char name[20];
    int age;
    char sex[10];
    float score;
};
struct Student stu[3] =
    {
        {101, "Wu", 18, "Boy", 95.5},
        {103, "Kan", 19, "Boy", 99.5},
        {105, "Sheng", 20, "Boy", 100}};

int main()
{
    struct Student *p;
    int i;

    for (i = 0; i < 3; i++)
    {
        p = stu + i;
        printf("\nNo.%ld\nname  : %s\nage   : %d\nsex   : %s\nscore : %-6.2f\n",
               p->num, p->name, p->age, p->sex, p->score); 
               // p->num相当于(*p).num ，表示p所指向的结构体变量中的num成员。"->"称为指向运算符
    }

/*
    for (p = stu ; p < stu + 3 ; p++)
    {
        printf("\nNo.%ld\nname  : %s\nage   : %d\nsex   : %s\nscore : %-6.2f\n",
               p->num, p->name, p->age, p->sex, p->score);      
    }
*/

    return 0;
}