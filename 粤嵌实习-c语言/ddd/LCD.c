#include "LCD.h"
#include "scale.h"


int *mmap_lcd = NULL ;
int fd_lcd = -1 ;
int fd_ts = -1 ;
extern int flag;

int init_LCD()
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


void Exit_LCD( void )
{
    munmap(mmap_lcd , 800*480*4 );
	close(fd_lcd);
    close(fd_ts);
}

int show_BMP(int x_s,int y_s,char *bmpname)
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


	printf("图像宽度：%ld , 高度：%ld \n" , info_head.biWidth , info_head.biHeight );
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
	int x,y;
	
	//进行像素点的颜色对应和填充
	for(y = 0;y < h;y++)
		for(x = 0;x < w;x++)
			buf_lcd[h-y-1][x] = buf_bmp[(y*w+x)*3+0+y*n] << 0 | 
								buf_bmp[(y*w+x)*3+1+y*n] << 8 | 
								buf_bmp[(y*w+x)*3+2+y*n] << 16; 
	
	//显示
	for(y = 0;y < h;y++)
	{
		for(x = 0;x < w;x++)
		{
			if (x+x_s < 800 && y+y_s < 480)
			{
				*(mmap_lcd + ((y+y_s) * 800) + x+x_s ) = buf_lcd[y][x];
			}
		}
	}

	return 0;
}

void show_scalebmp(const char *pathname,int start_x,int start_y,int d_w,int d_h)
{
	int fd_bmp,i,x,y;
	unsigned short heigh,weight;
	unsigned char head_buff[54];//存储头信息的buff
	//打开屏幕
	fd_bmp = open(pathname,O_RDWR);
	if(fd_bmp == -1)
	{
		printf("open bmp failure!\n");
		return ;
	}
	
	read(fd_bmp,head_buff,54);
	//得到图片宽度
	weight = head_buff[19]<<8 | head_buff[18];
	
	//得到图片高度
	heigh = head_buff[23]<<8 | head_buff[22];

	if((d_w+start_x) > 800)
	{
		printf("bmp d_w+start_x big 800\n");
		return ;
	}
	
	if((d_h+start_y) > 480)
	{
		printf("bmp d_h+start_y big 480\n");
		return ;
	}
	
	//定义用于存放图片rgb的buff
	unsigned char bmp_buff[weight*heigh*3];
	
	unsigned int buff[d_w*d_h];

	//将原图图片像素读到buffer当中
	read(fd_bmp,bmp_buff,sizeof(bmp_buff));
	
	unsigned char bmp_scalebuff[d_w*d_h*3];
	
	ScalePicture(bmp_buff,weight,heigh,bmp_scalebuff,d_w,d_h);
	
	
	//将rgb合成一个像素点unsigned int
	for(i=0; i<d_w*d_h; i++)
		buff[i] = bmp_scalebuff[3*i+0] | bmp_scalebuff[3*i+1]<<8 | bmp_scalebuff[3*i+2]<<16;
	
	
	//图像倒序及显示
	for(y=0; y<d_h; y++)
		for(x=0; x<d_w; x++)
			*(mmap_lcd + (y+start_y)*800+ start_x+x) = buff[(d_h-1-y)*d_w+x];
		
	close(fd_bmp);
	
}


int ts_get(int * x0 , int * y0 , int * x1 , int * y1 )
{
    int  a , b;
    // 读取文件的内容
    struct input_event ts_event ; // 定义一个结构体变量 ts_event 用来存放读取到的数据
    while(1)
    {

        read(fd_ts , &ts_event , sizeof(ts_event));
        
        // 数据分析得到坐标值
        if ( ts_event.type == EV_ABS )  // 先判断是不是触摸屏事件
        {
            if (ts_event.code == ABS_X) // 判断是不是 X轴d
            {
                a = ts_event.value*800/1024; // 把当前的值， 存入到X中  [黑色边框]
                // x = ts_event.value ; // 把当前的值， 存入到X中 【蓝色边框】
            }
            else if (ts_event.code == ABS_Y)// 判断是不是 Y轴
            {
                b = ts_event.value*480/600 ;// 把当前的值， 存入到Y中  [黑色边框]
                // y = ts_event.value ;// 把当前的值， 存入到Y中  【蓝色边框】
            }
            
        }
        

        // 无所欲为

		if (ts_event.type == EV_KEY && ts_event.code == BTN_TOUCH && ts_event.value == 1  )
        {
			*x0 = a;
			*y0 = b;
            printf("get_x0y0:(%d,%d)\n" , *x0, *y0 );
            
        }

        // 实现松手检测， 当用户松手后输出最后的坐标值
        if (ts_event.type == EV_KEY && ts_event.code == BTN_TOUCH && ts_event.value == 0  )
        {
			*x1 = a;
			*y1 = b;
            printf("get_x1y1:(%d,%d)\n" , *x1, *y1 );
            break  ;
        }

        
    }
    
    return 0;
}


void * show_ad(void * arg)
{
    int i=0;
    int x0,y0,x1,y1;
    char aviName[100][64] ;
    char name[999];


    // 初始化 
    init_LCD();

    
    int num = find_dir( "./" , ".avi" , aviName);
              
    
    sprintf(name ,"mplayer -quiet -slave -input file=/tmp/my_fifo -geometry 0:240 -zoom -x 800 -y 240 %s  &" ,aviName[0]);
    system(name);
	sleep(10);
    cmd_send("loop 0\n");
    while(1)
    {      
        ts_get( &x0 , &y0 , &x1 , &y1);
        if(0 < x1 && x1 < 250 )
        {
            i--;
            if(i < 0)
                i = num-1;
            printf("avipName[%d]:%s\n" , i , aviName[i]);
            sprintf(name ,"mplayer -quiet -slave -input file=/tmp/my_fifo -geometry 0:240 -zoom -x 800 -y 240 %s  &" ,aviName[i]);
            system("killall -9 mplayer");
            system(name);
            
        } 
        else if(550 < x1 && x1 <800)
        {
            i++;
            if(i > num-1)
                i = 0;
            printf("avipName[%d]:%s\n" , i , aviName[i]);
            sprintf(name ,"mplayer -quiet -slave -input file=/tmp/my_fifo -geometry 0:240 -zoom -x 800 -y 240 %s  &" ,aviName[i]);
            system("killall -9 mplayer");
            system(name);
        }
        
        
    }
    // 释放资源
    Exit_LCD();
    
    return 0;
}

void * show_bmp(void * arg)
{
    int j=0;
    char bmpName[100][64]  ;
    // 初始化 
    init_LCD();

    
    
    
    int num = find_dir( "./" , ".bmp" , bmpName); 
         
    while(1)
    { 
        while(flag==0)
        {        
            //printf("bmpName[%d]:%s\n" , j , bmpName[j]);    
            show_scalebmp(bmpName[j],400,0,400,240); 
            j++;
            if(j > num-1)
                j=0;

            sleep(5);
        }
    }
   
    

    // 释放资源
    Exit_LCD();
    
    return 0;
}