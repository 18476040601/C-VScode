/*
题目：
    定义一个结构体变量(包括年、月、日)。计算该日在本年中是第几天,注意闰年问题。
解题思路：
    用一个日期数组保存每一月的天数，二月的天数记为28天，后面根据输入的时间确定是否是闰年的二月，
    如果是，天数在加1。
*/

#include <stdio.h>

struct DATE
{
    int year ;
    int month ;
    int day ;
}date;  // 定义结构体变量 date

int main()

{
    // int year, month, day;
    int i, Days = 0;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("please enter the year : ");
    scanf("%d", &date.year);
    printf("please enter the month : ");
    scanf("%d", &date.month);
    printf("please enter the day : ");
    scanf("%d", &date.day);
    printf("\ndate is %d year %d month %d day \n", date.year, date.month, date.day);

    if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0)
    {
        for (i = 0; i < date.month; i++)
        {
            Days += a[i];
        }
        if (date.month > 2)
        Days = Days + date.day + 1 ;
        else 
        Days = Days + date.day ;
    }
    else
    {
        for (i = 0; i < date.month; i++)
        {
            Days += a[i] ;
        }
        Days += date.day ;
    }

    printf("\n%d 年%d 月%d 日是%d 年第%d 日\n", date.year, date.month, date.day, date.year, Days);

    return 0;
}
