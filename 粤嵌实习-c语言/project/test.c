#include "test.h"
void * test (void * arg)
{
	Init_Font();////显示字体库前先调用本函数进行初始化
#if(0)
	Clean_Area( 
				400, //x坐标起始点
                0,   //y坐标起始点
				400, //绘制的宽度
				200, //绘制的高度
				0xffffff
				);  //往屏幕指定区域填充颜色
#endif
	Display_characterX(
						 400,          //x坐标起始点
						 0,          //y坐标起始点
						"卡信息",   //GB2312 中文字符串
						 0x0000ff,     //字体颜色值
						 3
						 );	

	UnInit_Font();	 //程序退出前，调用本函数	

	return 0;
}
