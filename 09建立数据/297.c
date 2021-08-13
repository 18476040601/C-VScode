/*
    把一个学生的信息（包括学号、姓名、性别、住址）放在一个结构体变量中，然后输出学生信息
*/

#include <stdio.h>

int main()
{
    struct Student    // 声明结构体类型
    {
        long int num;
        char name[20];
        char sex[10];
        char addr[20];

    }
    a = {18124061048 , "伍堪生" , "Man" , "123 Shaoguan Road"} ; // 定义结构体变量a并初始化

    printf ("NO.%ld\nname : %s\nsex : %s\naddress : %s\n" , a.num , a.name , a.sex , a.addr) ;

    return 0;
}