/*
    写一个函数建立一个有3名学生数据的单向动态链表
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct Student)

struct Student
{
    long num;
    float score;
    struct Student *next;
};

int n; // 全局变量

struct Student *creat(void) // 定义函数。此函数返回一个指向链表头的指针
{
    struct Student *head, *p1, *p2;
    n = 0;

    p1 = p2 = (struct Student *)malloc(LEN); // 开辟一个新单元
    scanf("%ld %f", &p1->num, &p1->score);   // 输入第1个学生的学号和成绩
    head = NULL;

    while (p1->num != 0)
    {
        n = n + 1;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;

        p2 = p1;
        p1 = (struct Student *)malloc(LEN);
        scanf("%ld %f", &p1->num, &p1->score);
    }

    p2->next = NULL;
    return head;
}

int main()
{
    struct Student *pt;
    pt = creat();

    while (pt->num != 0)
    {
        printf("\nnum   : %ld\nscore : %-6.2f\n", pt->num, pt->score);
        pt = pt->next;
    }
    // printf ("%ld\n" , LEN) ;

    return 0;
}
