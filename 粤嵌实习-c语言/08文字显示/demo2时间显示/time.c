#include <stdio.h>
#include <time.h>
#include "font.h"
#include <string.h>
#include <unistd.h>

 

int main()
{
    Init_Font();

	Clean_Area( 0,  //x坐标起始点
                0,  //y坐标起始点
				800, //绘制的宽度
				480,//绘制的高度
				0x0); //往屏幕指定区域填充颜色

    time_t timep;

        struct tm 

    { 
            int tm_sec; //代表目前秒数, 正常范围为 0-59, 但允许至 61 秒
            int tm_min; //代表目前分数, 范围 0-59 
            int tm_hour; //从午夜算起的时数, 范围为 0-23 
            int tm_mday; //目前月份的日数, 范围 01-31 
            int tm_mon; //代表目前月份, 从一月算起, 范围从 0-11 
            int tm_year; //从 1900 年算起至今的年数
            int tm_wday; //一星期的日数, 从星期一算起, 范围为 0-6 
            int tm_yday; //从今年 1 月 1 日算起至今的天数, 范围为 0-365 
            int tm_isdst; //日光节约时间的旗标
    }; 

    

    char buf [128] = {0} ;

    while(1)
    {
        Clean_Area(0,0, 800, 40 ,0x0); //往屏幕指定区域填充颜色

        //time (&timep);

        char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; 
        time_t timep; 
        struct tm *p; 
        time(&timep); 
        p = localtime(&timep); //取得当地时间
        snprintf ( buf, 20, "%d%d%d%s\n ", (1900+p->tm_year), (1+p->tm_mon), (p->tm_mday), wday[p->tm_wday]); 
        snprintf ( buf, 8, "%d:%d:%d\n",  p->tm_hour, p->tm_min, p->tm_sec); 

        //strlen  计算字符串的长度（不包含结束符）
        //snprintf( buf , strlen(asctime(gmtime(&timep))),"%s\t\n", asctime(gmtime(&timep)));

        Display_characterX( 0,          //x坐标起始点
                            0,          //y坐标起始点
                            buf,   //GB2312 中文字符串
                            0xFF0000,     //字体颜色值
                            3);	
        sleep(1);
    }

    UnInit_Font();

}