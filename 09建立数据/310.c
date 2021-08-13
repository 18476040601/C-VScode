/*
    建立一个简单链表，它由3个学生数据的节点组成，要求输出节点中的数据
*/

#include <stdio.h>

struct Student
{
    int num;
    float score;
    struct Student *next; // next 是指针变量，指向结构体变量
};

int main()
{
    // 定义一个结构体数组，作为链表的结点
    struct Student stu[3] =
        {
            {101, 95},
            {103, 78},
            {105, 66}};

    struct Student *head, *p;

    head = stu;            // 将结点stu的起始地址赋给头指针head
    stu[0].next = stu + 1; // 将结点stu[1]的起始地址赋给stu[0]结点的next成员
    stu[1].next = stu + 2; // 将结点stu[2]的起始地址赋给stu[1]结点的next成员
    stu[2].next = NULL;    //stu[2]结点的next成员不存放其他结点地址
    p = head;              // 使p指向stu结点

    printf ("学号   成绩\n") ;
    while(p != NULL)
    {
        printf("%-5d %6.2f\n", p->num, p->score);
        p = p->next; // 使p指向下一个结点
    }

    return 0;
}