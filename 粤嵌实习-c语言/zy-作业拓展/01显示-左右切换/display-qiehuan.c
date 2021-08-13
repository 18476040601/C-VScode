#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

#include <sys/mman.h>
#include <unistd.h>


#define     LCD_PATH    "/dev/fb0"
#define     TS_PATH     "/dev/input/event0"

#define     LCD_W       800
#define     LCD_H       480
#define     LCD_SIZE    LCD_W * LCD_H * 4
#define     BMP_SIZE    LCD_W * LCD_H * 3


int bmp_display( char * File_Name );
int touch(int *a ,int *b);

int main()
{
    char BMP_name[999];
    int x,y;
    while(1)
    {
        
        touch( &x , &y);
        if(x<400)
    
         bmp_display( "3.bmp" );
         if(x>400)
        
          bmp_display( "2.bmp" );
    }
 
    return 0;

}

int touch(int *a ,int *b)
{
    // 打开触摸屏文件
    int fd_ts = open( TS_PATH , O_RDONLY );
      if (-1 == fd_ts)
    {
        perror("open event 0 error");
        return -1 ;
    } 
    // 读取文件的内容
    struct input_event ts_event ; // 定义一个结构体变量 ts_event 用来存放读取到的数据
while(1)
{
        read(fd_ts , &ts_event , sizeof(ts_event));
       
        // 数据分析得到坐标值
        if ( ts_event.type == EV_ABS )  // 先判断是不是触摸屏事件
        {
            if (ts_event.code == ABS_X) // 判断是不是 X轴
            {
                *a= ts_event.value*800/1024; // 把当前的值， 存入到X中  [黑色边框]
                // x = ts_event.value ; // 把当前的值， 存入到X中 【蓝色边框】
            }
            else if (ts_event.code == ABS_Y)// 判断是不是 Y轴
            {
                *b = ts_event.value*480/600 ;// 把当前的值， 存入到Y中  [黑色边框]
                // y = ts_event.value ;// 把当前的值， 存入到Y中  【蓝色边框】
            }
            
        }
        

        // 无所欲为
        // 实现松手检测， 当用户松手后输出最后的坐标值
        if (ts_event.type == EV_KEY && ts_event.code == BTN_TOUCH && ts_event.value == 0  )
            {
               break;
            }
} 
    // 关闭文件释放资源
    close(fd_ts);
    
    return 0;
}
int bmp_display( char * File_Name )
{
    //初始化LCD 显示器
    int fd_lcd = open( LCD_PATH , O_RDWR);
    if (-1 == fd_lcd)
    {
        perror("open lcd error");
        return -1 ;
    }

    // 内存 映射
    int * p_lcd = mmap(NULL , LCD_SIZE , PROT_READ | PROT_WRITE ,
                         MAP_SHARED , fd_lcd , 0);
    if ( MAP_FAILED ==  p_lcd )
    {
        perror("mmap error") ;   
        return -1 ;
    }
    
    // 打开图像文件
    int fd_bmp = open( File_Name  , O_RDWR);
    if (-1 == fd_bmp)
    {
        perror("open bmp error");
        return -1 ;
    }

    // 跳过前面54字节
    lseek(fd_bmp , 54 , SEEK_SET);

    // 读取图像数据BGR 
    char buf_bmp [ BMP_SIZE ] ;
    ssize_t ret_val = read( fd_bmp , buf_bmp , BMP_SIZE );
    printf("成功读取字节数为:%d字节\n" , ret_val );

    // 把24位的BGR 转换成 32位的ARGB 
    int buf_lcd [480][800] = {0};

    for (int y = 0; y < 480 ; y++)
    {
        for (int x = 0; x < 800 ; x++)
        {
            buf_lcd[479-y][x]  =    buf_bmp[(y*800+x)*3+0] << 0 |      // 蓝色数据
                                    buf_bmp[(y*800+x)*3+1] << 8 |   //绿色数据
                                    buf_bmp[(y*800+x)*3+2] << 16 |  // 红色数据
                                    0x00 << 24 ;   // 透明度 (无效)
        }
    }
    
    // 显示图像
    for (int y = 0; y < 480 ; y++)
    {
        for (int x = 0; x < 800 ; x++)
        {
            *(p_lcd+y*800+x) = buf_lcd[y][x] ;
        }
    }

    // 关闭退出 
    munmap(p_lcd , LCD_SIZE );
    close(fd_bmp);
    close(fd_lcd);

    return 0;
}