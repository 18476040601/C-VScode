/*
题目：
    定义一个结构体变量(包括年、月、日)。计算该日在本年中是第几天,注意闰年问题。
    写一个函数days。由主函数将年、月、日传递给days函数,计算后将日子数传回主函数输出。
解题思路：
    用一个日期数组保存每一月的天数，二月的天数记为28天，后面根据输入的时间确定是否是闰年的二月，
    如果是，天数在加1。
*/

#include <stdio.h>

struct Date
{
    int year;
    int month;
    int day;
};

/***********************************计算天数***********************************/
int Days(struct Date date)
{
    int i, days = 0;
    static int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0)
    {
        for (i = 0; i < date.month; i++)
        {
            days += a[i];
        }
        if (date.month > 2)
            days = days + date.day + 1;
        else
            days = days + date.day;
    }
    else
    {
        for (i = 0; i < date.month; i++)
        {
            days += a[i];
        }
        days += date.day;
    }

    return days;
}

int main()

{
    int days;
    struct Date date;

    printf("please enter the year : ");
    scanf("%d", &date.year);
    printf("please enter the month : ");
    scanf("%d", &date.month);
    printf("please enter the day : ");
    scanf("%d", &date.day);
    printf("\ndate is %d year %d month %d day \n", date.year, date.month, date.day);

    days = Days(date);

    printf("\n%d 年%d 月%d 日是%d 年第%d 日\n\n", date.year, date.month, date.day, date.year, days);

    return 0;
}
