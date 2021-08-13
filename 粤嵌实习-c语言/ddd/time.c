#include "time.h"




void * show_time(void * arg)
{
    Init_Font();

	Clean_Area(0,  //x坐标起始点
               0,  //y坐标起始点
				800, //绘制的宽度
				480,//绘制的高度
				0x0); //往屏幕指定区域填充颜色

    time_t timep;
    

    char buf [128] = {0} ;

    while(1)
    {
        Clean_Area(0,0, 400, 240 ,0xFFFFFF); //往屏幕指定区域填充颜色

        time (&timep);
        //strlen 计算字符串的长度（不包含结束符）
        //n 用来控制拷贝的长度（安全版本的拼接拷贝）
        struct tm *p;
        p = localtime(&timep);//用localtime将秒数转化为struct tm结构体

        sprintf( buf ,"日期:%d年%d月%d日", 1900 + p->tm_year , 1+ p->tm_mon ,p->tm_mday);
        Display_characterX(0,          //x坐标起始点
                            50,          //y坐标起始点
                            buf,   //GB2312 中文字符串
                            0x0,     //字体颜色值
                            2);	
      

        sprintf( buf ,"时间:%d:%d:%d", p->tm_hour, p->tm_min, p->tm_sec);
        Display_characterX(0,          //x坐标起始点
                            150,          //y坐标起始点
                            buf,   //GB2312 中文字符串
                            0x0,     //字体颜色值
                            2);	
        sleep(1);
    }

    UnInit_Font();

}