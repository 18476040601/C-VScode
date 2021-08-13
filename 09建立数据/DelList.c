/*
    对链表结点的删除操作实现
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>

#define LEN sizeof(struct Student)

struct Student *creat(void);                        // 创建链表
struct Student *del(struct Student *head, int num); // del 函数用于删除结点， *head即链表的
                                                    // 头指针，num是要删除的结点num
void print(struct Student *head);                   // 打印链表

struct Student
{
    long num;
    float score;
    struct Student *next;
};

int n; // 全局变量，用来记录存放了多少数据

struct Student *creat(void)
{
    struct Student *head, *p1, *p2;
    n = 0;

    p1 = p2 = (struct Student *)malloc(LEN); // 开辟一个新单元

    printf("please enter the num   : ");
    scanf("%ld", &p1->num); // 输入第1个学生的学号
    printf("please enter the score : ");
    scanf("%f", &p1->score); // 输入第1个学生的成绩
    printf("\n");
    head = NULL;

    while (p1->num) // 相当于while (p1->num != 0)
    {
        n = n + 1;
        if (n == 1)
            head = p1; // 将p1地址赋给头指针
        else
            p2->next = p1; // 将p1的起始地址赋给p2结点的next成员，即p1指向下一个学生信息的地址

        p2 = p1; // 将p1的地址赋给p2

        p1 = (struct Student *)malloc(LEN); // 开辟动态存储区，把起始地址赋给p1
        printf("please enter the num   : ");
        scanf("%ld", &p1->num); // 输入第1个学生的学号
        printf("please enter the score : ");
        scanf("%f", &p1->score); // 输入第1个学生的成绩
        printf("\n");
    }

    p2->next = NULL;
    return head;
}

struct Student *del(struct Student *head, int num)
{
    struct Student *p1, *p2;

    if (head == NULL) // 如果都节点是一个空指针，则这是一个空链表
    {
        printf("\nThis list is NULL !!!\n");
        goto end; // 直接跳转到下面end处，表示结束
    }

    p1 = head;
    while (p1->num != num && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if (num == p1->num)
    {
        if (p1 == head) // 当将要删除的结点位于头结点的时候，即删除的结点时第一个结点
        {
            head = p1->next; // 头结点指向下一个结点，即第一个结点跳过
        }
        else
        {
            p2->next = p1->next; // 假设p1->next为B指向C的结点，p2->next为A指向B的结点 ，
                                 // 则p2->next = p1->next
                                 // 表示把指向C的结点赋给A指向的下一个结点，即A指向C
        }
        printf("\nDelete No.%d succeed !\n", num);
    }
    else
    {
        printf("%d not been found !\n", num);
    }
    n = n - 1; // n是作为一个全局变量，用来记录链表的数据数，由于删除了一个，所以减少了了1位数据成员
end: // 跳转到此处
    return head;
}

void print(struct Student *head)
{
    struct Student *p;
    printf("\nNow , These records are : \n");
    p = head;

    if (head != NULL)

        while (p != NULL)
        {
            printf("\nnum   : %ld\nscore : %-6.2f\n", p->num, p->score);
            p = p->next;
        }
    printf("\n");
}

void main()
{
    struct Student *stu, *p;
    int n;

    stu = creat();
    p = stu;
    print(p);

    printf("please enter the num to delete : ");
    scanf("%d", &n);
    print(del(p, n));

    printf("\n\n");
    pause();
}
