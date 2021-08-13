/*
题目：
    编写一个函数print,打印一个学生的成绩数组，该数组中有5个学生的数据记录，
    每个记录包括num,name,score[3],编写一个函数input,用来输人5个学生的数据记录。,用print函数输出这些记录。
*/

#include <stdio.h>

#define N 5

struct Student
{
    int num;
    char name[20];
    float score[3];
} stu[N];

void print(struct Student *stu) ; // 输出函数，用来输出数据
void input(struct Student *stu) ; // 输入函数，输入数据


/*******************************输出函数**********************************/
void print(struct Student *stu)
{
    printf("These %d student data of : \n" , N);
    for (int i = 0; i < N; i++)
    {
        printf("num : %-5dname : %-8sscore[0] : %-8.2fscore[1] : %-8.2fscore[2] : %-8.2f\n",
               stu[i].num, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
    }
    printf("\n");
}


/*******************************输入函数**********************************/
void input(struct Student *stu)
{
    printf ("please enter the students data of : \n") ;
    printf ("(num - name - score[0] - score[1] - score[2])\n") ;

    for (int i = 0; i < N; i++)
    {
        scanf("%d %s %f %f %f", &stu[i].num, stu[i].name, &stu[i].score[0],
              &stu[i].score[1], &stu[i].score[2]);
    }
    printf ("\n") ;
}

int main()
{
    input(stu) ;
    print(stu);
    return 0;
}