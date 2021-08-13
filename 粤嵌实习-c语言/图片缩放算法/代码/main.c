#include <stdlib.h>
#include <unistd.h>
#include "lcd.h"


int main(void)
{
	//LCD屏幕指针初始化
	LCD_init();
	
	show_bmp("test.bmp",0,0);
	
	show_scalebmp("test.bmp",200,200,300,200);
	


	//释放LCD指针
	LCD_UnInit();
	return 0;
}