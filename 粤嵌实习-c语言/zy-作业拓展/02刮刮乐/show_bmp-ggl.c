#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

typedef 	short	WORD  	 ;
typedef 	int	DWORD  	 ;
typedef 	long	LONG  	 ;

// 声明外部变量
extern int *mmap_lcd ;

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




int ggshow(int x_s,int y_s,char *bmpname)
{
	
	//打开要显示的bmp图片
	int fd_bmp = open(bmpname,O_RDONLY);
	if(-1 == fd_bmp)
	{
		printf("open %s failed !\n" , bmpname);
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
	
	//无特效显示
	int x,y;int x1,y1;


       

	
	//进行像素点的颜色对应和填充
	for(y1 = 0;y1 < h;y1++){
		for(x1 = 0;x1 < w;x1++){
			                                        buf_lcd[h-y1-1][x1] = buf_bmp[(y1*w+x1)*3+0+y1*n] << 0 | 
								buf_bmp[(y1*w+x1)*3+1+y1*n] << 8 | 
								buf_bmp[(y1*w+x1)*3+2+y1*n] << 16;} }
	
	//显示
/*if(x_s+100<800&&y_s+100<480){
	for(y=y_s ;y < y_s+100;y++)

	{
		for(x=x_s ;x <x_s+100;x++)
		{
			if (x+x_s < 800 && y+y_s < 480){
			
				*(mmap_lcd + ((y+y_s) * 800) + x+x_s ) = buf_lcd[y][x];
			}
		}
	}
}*/
if(x_s+100<800&&y_s+100<480){

	for(y=0 ;y < 100;y++)

	{
		for(x=0 ;x <100;x++)
		{
			if (x+x_s < 800 && y+y_s < 480){
			
				*(mmap_lcd + ((y_s+y) * 800) +x+x_s ) = buf_lcd[y_s+y][x_s+x];
			}
		}
	}
}

	return 0;
}

