//////////////////////////////////////////////////
////刮刮乐
////Even
////2018.7.22
/////////////////////////////////////////////////
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <linux/input.h>

#define DEV_TS_PATH "/dev/input/event0"
#define DEV_LCD_PATH "/dev/fb0"

//函数声明
int ts_get(int *x ,int *y );
int inint(void);
int show(int x,int y ,int xn ,int yn );

//全局变量
int log_f = 0;
int fd_lcd;
int * p ;
int buf_lcd [480][800];


int main(int argc, char const *argv[])
{
	int x, y;
	inint();

	while(1)
	{
		ts_get(&x , &y );
		int xn = x + 50  ;
		int yn = y + 50  ;
		printf("==x: %d xn:%d  y:%d yn:%d==\n", x, xn , y , yn );
		show(x , y , xn,yn );
		// usleep(2000);
	}

	return 0;
}

int inint(void)
{
	int x , y ;
	//1.打开设备文件
	fd_lcd = open(DEV_LCD_PATH, O_RDWR );
	if ( -1 == fd_lcd)
	{
		printf("oepn fb0 failed !!\n");
		return 2 ;
	}

	int fd_bmp ;
	fd_bmp = open("timg.bmp", O_RDWR );
	if ( -1 == fd_bmp )
	{
		printf("open 1.bmp failed !!\n");
		return -1 ;
	}

	//内存映射
	// * 申请一个指针变量p类型时int
	p = (int *)mmap(	NULL,		//需要建立内存映射的起始地址（通常设为 NULL, 代表让系统自动选定地址）
						800*480*4,	// 需要建立内存映射的大小 X800 Y480 每个像素点占4个字节
						PROT_READ | PROT_WRITE, //映射区域可被读取 映射区域可被写入
						MAP_SHARED,  // 对应射区域的写入数据会复制回文件内
						fd_lcd,		//需要内存映射的文件描述符
						0);				//offset为文件映射的偏移量, 通常设置为0
	if ( MAP_FAILED == p)
	{
		printf("mmap error !\n");
		return -1 ;
	}

		//文件指针跳转
	int ret = lseek(fd_bmp, 54 , SEEK_SET);
	printf("lseek: %d\n", ret );
	//读取图片信息
	char buf_bmp[800*480*3];
	ret = read(fd_bmp, buf_bmp , sizeof(buf_bmp));
	printf("read:%d\n", ret );

	//数据处理把24位数据转换成32位
	

	for ( y = 0; y < 480 ; y++)
	{
		for ( x = 0; x < 800 ; x++)
		{
			buf_lcd[479 - y][x] = buf_bmp[(x+y*800)*3 + 0] << 0 |
							buf_bmp[(x+y*800)*3 + 1] << 8 |
							buf_bmp[(x+y*800)*3 + 2] << 16 ;
		}
	}

	for ( y = 0; y < 480 ; y++)
	{
		for ( x = 0; x < 800 ; x++)
		{
			*(p+x+y*800) = 0xC0C0C0;
		}
	}

	return 0 ;
}

int show(int x,int y ,int xn ,int yn )
{
	int x_s = x ;
	if (xn >= 800)
	{
		xn = 799 ;
	}
	if (yn >= 480)
	{
		yn = 479 ;
	}
	//2. 写入内容
	for ( ; y < yn ; y++)
	{
		for ( x = x_s ; x < xn ; x++)
		{
			// * 解引用
			*( p + y*800 + x ) = buf_lcd[y][x] ;
		}
	}

	return 0;
}

int ts_get(int *x ,int *y )
{
	// printf("ts_get x = %d y = %d\n", *x , *y  );
	
	//1.打开设备文件
	int fd_ts = open(DEV_TS_PATH, O_RDONLY);
	if (-1 == fd_ts)
	{
		printf("open even0 failed ~\n");
		return -1 ;
	}


	// struct input_event {
	// 	struct timeval time;  	//事件发生的时间
	// 	__u16 type;				//事件发生的类型
	// 	__u16 code;				//事件发生的编码
	// 	__s32 value;			//事件发生的值
	// };
	//2.读取文件信息
	struct input_event ts_event;
	int cont = 0 ;
	while(1)
	{	
		read(fd_ts , &ts_event , sizeof(ts_event));
		// printf("time:%d:%d\t type:%d\t code:%d\t value:%d\n",
		// 		ts_event.time.tv_sec,
		// 		ts_event.time.tv_usec,
		// 		ts_event.type,
		// 		ts_event.code,
		// 		ts_event.value);
		if ( EV_ABS == ts_event.type)
		{
			if (ABS_X == ts_event.code)
			{
				*x = ts_event.value ;
				cont ++ ;
			}
			else if (ABS_Y == ts_event.code)
			{
				*y = ts_event.value ;
				cont ++ ;
			}
		}
		if (2 == cont)
		{
			// printf("ts_get (%d,%d)\n",*x, *y );
			cont = 0 ;
			break ;
		}
		
	}
	close(fd_ts);
	return 0;
}
