#ifndef __LCD_H_
#define __LCD_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define FB_PATH "/dev/fb0"      //LCD设备

extern unsigned int *mem_p; //定义无符号类型指针，用于存放映射地址
extern int lcd_fd;
//屏幕初始化
extern void LCD_init(void);

//LCD撤消
extern void LCD_UnInit(void);


//const char *pathname:图片路径
//int start_x：图片起始位置 x轴
//int start_y：图片起始位置 y轴
//int left_offset:图片左偏移量
//int right_offset:图片右偏移量
extern  void show_bmp_Xoffset(const char *pathname,int start_x,int start_y,int left_offset,int right_offset);
extern  void show_bmp_Yoffset(const char *pathname,int start_x,int start_y,int up_offset,int down_offset);
extern void show_scalebmp(const char *pathname,int start_x,int start_y,int d_w,int d_h);
//const char *pathname:图片路径
//int start_x：图片起始位置 x轴
//int start_y：图片起始位置 y轴
extern  void show_bmp(const char *pathname,int start_x,int start_y);
extern void Big_PictureByPoint(const char *pathname,int pointX,int pointY);
extern void show_smallbmp(unsigned char o_picture[],int o_w,int o_h,int start_x,int start_y,int d_w,int d_h);
extern void ExpandPicture(const char *pathname,int pointX,int pointY);
#endif