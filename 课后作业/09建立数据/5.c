/*
题目：
    有10个学生,每个学生的数据包括学号、姓名、3门课程的成绩,从键盘输人10个学生数据,
    要求输出3门课程总平均成绩,以及最高分的学生的数据(包括学号、姓名、3门课程成绩、平均分数)。
*/

#include <stdio.h>

#define N 5

struct Student
{
    int num;
    char name[20];
    float score[3];
    float aver ;
} stu[N];


void print(struct Student stud) ; // 输出最大成绩函数，用来输出数据
void input(struct Student *stu) ; // 输入函数，输入数据
struct Student max(struct Student stu[]) ; // 求最大平均成绩函数


/*******************************输出最大成绩函数**********************************/
void print(struct Student stud)
{
    printf("成绩最高的学生为 ：\n");
    printf("num   : No.%d\nname  : %s\nscore : %-6.2f %-6.2f %-6.2f\naverage score : %-8.2f\n",
           stud.num, stud.name, stud.score[0], stud.score[1], stud.score[2], stud.aver);
}


/*******************************输入函数**********************************/
void input(struct Student *stu)
{
    float a = 0, b = 0 , c = 0 ;

    printf ("please enter the students data of : \n") ;
    printf ("(num - name - score[0] - score[1] - score[2])\n") ;

    for (int i = 0; i < N; i++)
    {
        scanf("%d %s %f %f %f", &stu[i].num, stu[i].name, &stu[i].score[0],
              &stu[i].score[1], &stu[i].score[2]);

        stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0 ;

        a += stu[i].score[0] ;
        b += stu[i].score[1] ;
        c += stu[i].score[2] ;
    }

    printf ("\nThe average of the 3 grade : \n") ;
    printf ("%-6.2f%-6.2f%-6.2f\n" , a/N , b/N , c/N) ;
    printf ("\n") ;
}

/*****************************求最大数*************************/
struct Student max(struct Student *stu)
{
    int m = 0 , i ;

    for (i = 0 ; i < N ; i++)
    {
        if (stu[i].aver > stu[m].aver)
        m = i ;
    }

    return stu[m] ;

}


int main()
{
    input(stu) ;
    print(max(stu));
    return 0;
}