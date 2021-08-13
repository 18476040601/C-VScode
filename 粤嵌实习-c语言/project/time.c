#include "time.h"

extern unsigned int ID ;

void * time_get(void * arg)
{
    
    Init_Font();

	Clean_Area(0,  //x坐标起始点
               0,  //y坐标起始点
			    400, //绘制的宽度
				200,//绘制的高度
				0x66ffcc); //往屏幕指定区域填充颜色
    #if(0)
    Clean_Area(400,  //x坐标起始点
                0,  //y坐标起始点
                400, //绘制的宽度
                200,//绘制的高度
                0xffffff); //往屏幕指定区域填充颜色
    #endif
    time_t timep;

    char buf [128] = {0} ;
    while(1)
    {

        Clean_Area(0,0, 400, 200 ,0x66ffcc); //往屏幕指定区域填充颜色
    //    Clean_Area(400,0, 400, 200 ,0xfffff); //往屏幕指定区域填充颜色

        char *wday[] = {"日", "一", "二", "三", "四", "五", "六"};

        time (&timep);
        //strlen 计算字符串的长度（不包含结束符）
        //n 用来控制拷贝的长度（安全版本的拼接拷贝）
        struct tm *p;
        p = localtime(&timep);//用localtime将秒数转化为struct tm结构体
        sprintf( buf ,"日期:%d年%d月%d日", (1900 + p->tm_year),(1+ p->tm_mon), p->tm_mday);
        // printf(buf);
        Display_characterX(20,          //x坐标起始点
                            30,          //y坐标起始点
                            buf,   //GB2312 中文字符串
                            0x000000,     //字体颜色值
                            2);
        sprintf( buf ,"星期%s", wday[p->tm_wday]);
        // printf(buf);
        Display_characterX(20,          //x坐标起始点
                            80,          //y坐标起始点
                            buf,   //GB2312 中文字符串
                            0x000000,     //字体颜色值
                            2);	
        sprintf( buf ,"时间:%d:%d:%d", p->tm_hour, p->tm_min, p->tm_sec);
        // printf(buf);
        Display_characterX(20,          //x坐标起始点 
                            130,          //y坐标起始点
                            buf,   //GB2312 中文字符串
                            0x000000,     //字体颜色值
                            2);	

#if(0)
    sprintf(buf,"卡_号：%d",ID);                        
    Display_characterX(
                    420,          //x坐标起始点
                    30,          //y坐标起始点
                    buf,   //GB2312 中文字符串
                    0x0000ff,     //字体颜色值
                    2
                    );	
    sprintf(buf,"余_额：%d",ID);                        
    Display_characterX(
                    420,          //x坐标起始点
                    120,          //y坐标起始点
                    buf,   //GB2312 中文字符串
                    0x0000ff,     //字体颜色值
                    2
                    );
#endif


        sleep(1);
    }

    UnInit_Font();

}