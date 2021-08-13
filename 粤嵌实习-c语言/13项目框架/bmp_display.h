#ifndef    __BMP_DISPLAY_H__
#define    __BMP_DISPLAY_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

typedef 	short	WORD  	 ;
typedef 	int		DWORD  	 ;
typedef 	long	LONG  	 ;

// 声明外部变量
extern int *mmap_lcd ;

int show(int x_s,int y_s,char *bmpname)
{
	
	//打开要显示的bmp图片
	int fd_bmp = open(bmpname,O_RDONLY);
	
}










#endif