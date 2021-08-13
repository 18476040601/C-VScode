#include <stdio.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>


typedef 	short	WORD  	 ;
typedef 	int		DWORD  	 ;
typedef 	long	LONG  	 ;




typedef struct tagBITMAPFILEHEADER
{
      WORD bfType;//位图文件的类型，必须为BM(1-2字节）
      DWORD bfSize;//位图文件的大小，以字节为单位（3-6字节，低位在前）
      WORD bfReserved1;//位图文件保留字，必须为0(7-8字节）
      WORD bfReserved2;//位图文件保留字，必须为0(9-10字节）
      DWORD bfOffBits;//位图数据的起始位置，以相对于位图（11-14字节，低位在前）
      //文件头的偏移量表示，以字节为单位
}__attribute__((packed)) BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{
    DWORD biSize;//本结构所占用字节数（15-18字节）
    LONG biWidth;//位图的宽度，以像素为单位（19-22字节）
    LONG biHeight;//位图的高度，以像素为单位（23-26字节）
    WORD biPlanes;//目标设备的级别，必须为1(27-28字节）
    WORD biBitCount;//每个像素所需的位数，必须是1（双色），（29-30字节）
    //4(16色），8(256色）16(高彩色)或24（真彩色）之一
    DWORD biCompression;//位图压缩类型，必须是0（不压缩），（31-34字节）
    //1(BI_RLE8压缩类型）或2(BI_RLE4压缩类型）之一
    DWORD biSizeImage;//位图的大小(其中包含了为了补齐列数是4的倍数而添加的空字节)，以字节为单位（35-38字节）
    LONG biXPelsPerMeter;//位图水平分辨率，每米像素数（39-42字节）
    LONG biYPelsPerMeter;//位图垂直分辨率，每米像素数（43-46字节)
    DWORD biClrUsed;//位图实际使用的颜色表中的颜色数（47-50字节）
    DWORD biClrImportant;//位图显示过程中重要的颜色数（51-54字节）
}__attribute__((packed)) BITMAPINFOHEADER;

int line(char *file_name)
{

	int x = 1 , y = 1 ;

	int i , j ;

	int fd_lcd = open("/dev/fb0", O_RDWR);
	if ( -1 == fd_lcd )
	{
		printf("open fb0 failed !!!\n");
		return -1 ;
	}

	//建立内存映射
	int *p = (int *)mmap(NULL,	//需要内存映射的起始地址(通常设为 NULL, 代表让系统自动选定地址)
					800*480*4,  //需要多大的一片内存(一字节为单位) LCD显示屏800*480个像素点 每个像素点占4字节
					PROT_READ | PROT_WRITE,  //映射区域可被读取 映射区域可被写入
					MAP_SHARED,					//对应射区域的写入数据会复制回文件内
					fd_lcd, 		//需要内存映射的文件的文件描述符
					0);			//参数offset为文件映射的偏移量, 通常设置为0

 /*
 	for (y = 0; y < 480; y++)
	{
		for (x = 0; x < 800; x++)
		{
			//* --> 解引用 取内容  显示背景色
			//*(p+x+y*800) = 0X00BFFF;
		}
	}
 */

    
	//打开要显示的bmp图片
	int fd_bmp = open(file_name,O_RDONLY);
	if(-1 == fd_bmp)
	{
		printf("open failed !\n");
		return -1;
	}

	// 读取图片信息
	BITMAPFILEHEADER file_head ;
	read(fd_bmp,&file_head,sizeof(file_head)); // 读取文件头的信息

	BITMAPINFOHEADER info_head ;
	read(fd_bmp,&info_head,sizeof(info_head)); // 读取信息头的信息


	printf("图像宽度：%d , 高度：%d \n" , info_head.biWidth , info_head.biHeight );
	int w = info_head.biWidth ;
	int h = info_head.biHeight ;
	
	int n ;
	// 计算图像的宽度是否能被整除， 
	// 并获得补充的字节数n 
	if (((w*3)%4) != 0 )
	{
		n = 4 - ((w*3)%4); // 获得补充的字节数n 
	}
	else
	{
		n = 0 ;
	}

	char buf_bmp[h*(w*3+n)];
	int buf_lcd[h][w];
	
	int ret = 0;
	
	//读取bmp图片的颜色信息
	ret = read(fd_bmp,buf_bmp,sizeof(buf_bmp));
	if(-1 == ret)
	{
		printf("read failed !\n");
		return -1;
	}
	printf("ret = %d\n",ret);
	
	
	//进行像素点的颜色对应和填充
	for(y = 0;y < h;y++)
		for(x = 0;x < w;x++)
			buf_lcd[h-y-1][x] = buf_bmp[(y*w+x)*3+0+y*n] << 0 | 
								buf_bmp[(y*w+x)*3+1+y*n] << 8 | 
								buf_bmp[(y*w+x)*3+2+y*n] << 16; 
	

	//非零则真

		 for (int y = 0; y < 480 ; y++)
    {
        for (int x = 0; x < 800 ; x++)
	
        {
            *(p+y*800+x) = buf_lcd[y][x] ;
        }
    }
		
	close(fd_lcd);


	return 0;
}
