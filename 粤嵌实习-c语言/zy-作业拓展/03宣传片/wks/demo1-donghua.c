 // 小僵尸图片连成动画

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>


#define     LCD_PATH    "/dev/fb0"

#define     LCD_W       800
#define     LCD_H       480
#define     LCD_SIZE    LCD_W * LCD_H * 4
#define     BMP_SIZE    LCD_W * LCD_H * 3

// 函数声明
int bmp_display( char * File_Name  ) ;


int main(int argc, char const *argv[])
{
    

    while(1)
    {
        char BMP_name[999];

        for (int i = 0; i < 82; i++)
        {
            sprintf(BMP_name,"Frame%d.bmp",i);

            bmp_display( BMP_name );
            usleep(10000);
        }  
       
    }


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
