#include <stdio.h>
#include <time.h>
#include "font.h"
#include <string.h>
#include <unistd.h>



int main()
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
        Clean_Area(0,0, 800, 40 ,0x0); //往屏幕指定区域填充颜色

        time (&timep);
        sprintf( buf , "%s\n", asctime(gmtime(&timep)));

        Display_characterX(0,          //x坐标起始点
                            0,          //y坐标起始点
                            buf,   //GB2312 中文字符串
                            0xFF0000,     //字体颜色值
                            3);	
        sleep(1);
    }

    UnInit_Font();

}