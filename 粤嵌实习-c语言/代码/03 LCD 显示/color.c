#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    // 打开LCD 对应的设备文件
    int fd_lcd =  open("/dev/fb0", O_RDWR) ; // 以可读写的方式打开LCD设备文件
    if ( -1 == fd_lcd )
    {
        perror("open lcd error");
        return -1 ;
    }
    
    // 写入RGB颜色值
    int color = 0xADFF2F ; // & 取地址， 取得color 的内存地址

    // 循环遍历地写入每一个像素点
    for (int y = 0; y < 480 ; y++)
    {
        for (int x = 0; x < 800 ; x++)
        {
            write(fd_lcd , &color , 4 );
        }
    }

    // 关闭文件  
    close(fd_lcd);  


    return 0;
}



int  a  = 100 ;
