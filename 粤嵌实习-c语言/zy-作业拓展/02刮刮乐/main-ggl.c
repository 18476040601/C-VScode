#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <strings.h>

#define     TS_PATH     "/dev/input/event0"

int ts_get(int * a , int * b ) ;
int show(int x_s,int y_s,char *bmpname);
int ggshow(int x_s,int y_s,char *bmpname);


int *mmap_lcd = NULL ;
int fd_lcd = -1 ;
int fd_ts = -1 ;


int init_lcd()
{
   //打开lcd设备文件
	fd_lcd = open("/dev/fb0",O_RDWR);
	if(-1 == fd_lcd)
	{
		printf("open failed !\n");
		return -1;
	}
	//映射
	mmap_lcd = mmap(NULL,           //映射到的位置，不确定填NULL，系统自动分配
						800*480*4,       //映射的显存大小  800*480*4
						PROT_WRITE,      //映射的操作  PROT_EXEC   PROT_READ  PROT_WRITE  PROT_NONE
						MAP_SHARED,      //映射的权限标志  MAP_SHARED    MAP_PRIVATE
						fd_lcd,          //映射的对象
						0);              //映射偏移 ，默认为0 	
	//判断映射是否成功
	if(mmap_lcd == MAP_FAILED)
	{
		perror("mmap");
		return -1;
	}

    // 打开触摸屏文件
    fd_ts = open( TS_PATH , O_RDONLY );
    if (-1 == fd_ts)
    {
        perror("open event 0 error");
        return -1 ;
    }
	
	return 0 ; 
}

void Exit( void )
{
    munmap(mmap_lcd , 800*480*4 );
	close(fd_lcd);
    close(fd_ts);
}

int main(int argc, char const *argv[])
{

    // 初始化 
    init_lcd();

    // 等待触摸屏输入
    int x=0;int y=0 ;
  
    int Num = 1 ;
	show( 0,0,"3.bmp");

	while(1)
{
    
	ts_get(&x , &y);

	printf("main%d,%d",x,y);

	ggshow( x,y,"2.bmp");

  }
   

    // 释放资源
    Exit();
    
    return 0;
}
