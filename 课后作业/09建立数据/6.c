/*
题目：
    13个人围成一圈,从第1个人开始顺序报号1,2,3。凡报到3者退出圈子。
    找出最后留在圈子中的人原来的序号。要求用链表实现。
解题思路：
    创建一个环形链表，给链表中的每一个节点从1~13编号，然后开始淘汰过程，
    对于淘汰的节点，序号置为0，淘汰完成之后，找到序号不为0的即为最后留下的。
*/

#include <stdio.h>
#define NUM 13
typedef struct people
{
    int num;
    struct people *next;
} people;

int main()
{
    int count = NUM;
    people p[NUM];
    people *head;
    head = p; //head 指向p[0]
              //1~13编号
    for (int i = 0; i < NUM; i++)
    {
        head->num = i + 1;
        head->next = &p[i + 1];
        head = head->next;
    }
    //最后一个元素指向第一个元素 ， 形成环
    p[NUM - 1].next = p;

    int i = 1;
    head = p;
    while (count > 1)
    {
        //跳过已经被淘汰的节点
        if (head->num == 0)
        {
            head = head->next;
            continue;
        }
        if (i == 3)
        {
            //被淘汰的节点，num置为0
            printf("第 %-3d位置被淘汰\n", head->num);
            head->num = 0;
            count--;
        }
        head = head->next;
        i++;
        if (i > 3)
        {
            i = 1;
        }
    }
    printf("--------------\n");
    while (head->num == 0)
    {
        //非0节点即为最后留下的
        head = head->next;
        if (head->num != 0)
        {
            printf("留到最后的是 %d \n", head->num);
        }
    }

    return 0;
}
