#include <stdio.h>

int main()

{
    char grade;
    scanf("%c", &grade);
    printf("Your score:"); //你的成绩
    switch (grade)
    {
    case 'A':
        printf("90~100\n");
        break; //执行到break，语句结束
    case 'B':
        printf("80~89\n");
        break;
    case 'C':
        printf("70~79\n");
        break;
    case 'D':
        printf("60~69\n");
        break;
    case 'E':
        printf("<60\n");
        break;

    default:
        printf("enter data error\n");
        break; //输入数据错误   deafult这一行可有可无
    }

    return 0;
}