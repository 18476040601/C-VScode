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

    while (p1->num)  // 相当于while (p1->num != 0)
    {
        n = n + 1;
        if (n == 1)
            head = p1;  // 将p1地址赋给头指针
        else
            p2->next = p1; // 将p1的起始地址赋给p2结点的next成员，即p1指向下一个学生信息的地址

        p2 = p1;  // 将p1的地址赋给p2

        p1 = (struct Student *)malloc(LEN); // 开辟动态存储区，把起始地址赋给p1
        scanf("%ld %f", &p1->num, &p1->score);
    }

    p2->next = NULL;
    return head;
}

void print(struct Student *head)
{
    struct Student *p;
    printf("\nNow,These %d records are : \n", n);
    p = head;

    if (head != NULL)

        while (p != NULL)
        {
            printf("\nnum   : %ld\nscore : %-6.2f\n", p->num, p->score);
            p = p->next;
        }
}

int main()
{
    struct Student *pt;

    pt = creat(); // 函数返回链表第一个结点的地址

    print(pt);

    return 0;
}
