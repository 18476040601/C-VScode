/*
题目：输入某年某月某日，判断这一天是这一年的第几天？

程序分析：
    以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，
    特殊情况，闰年且输入月份大于3时需考虑多加一天。
*/

#include <stdio.h>

int main()

{
    int year, month, day;
    int i, Day;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("please input date: ");
    scanf("%d %d %d", &year, &month, &day);
    printf("date is %d year %d month %d day \n", year, month, day);

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        for (i = 0; i < month; i++)
        {
            Day += a[i];
        }
        if (month > 2)
        Day = Day + day + 1 ;
        else 
        Day = Day + day ;
    }
    else
    {
        for (i = 0; i < month; i++)
        {
            Day += a[i] ;
        }
        Day += day ;
    }

    printf("%d年%d月%d日是%d年第%d日\n", year, month, day, year, Day);

    return 0;
}