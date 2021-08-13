
// 3种颜色（竖）


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
    int color[9] = {0xFF0000,0xA020F0,0X7CFC00,0XFFFF00,0X000000,0XFFFFFF,0X0000FF,0X00FFFF,0XC76114} ; // & 取地址， 取得color 的内存地址
    // 循环遍历地写入每一个像素点
    

    for (int y = 0; y < 480 ; y++)
    {
        if (y <160)
        {
            for (int i = 0; i < 800; i++)
            {
                if (i<266)
                {
                    write(fd_lcd,&color[0],4);
                }
                else if (i<532)
                {
                    write(fd_lcd,&color[1],4);
                }
                else{write(fd_lcd,&color[2],4);}
            }
            
        }
        if (y<320&&y>160)
        {
          
            for (int i = 0; i < 800; i++)
            {
                if (i<266)
                {
                    write(fd_lcd,&color[0],4);
                }
                else if (i<532)
                {
                    write(fd_lcd,&color[1],4);
                }
                else{write(fd_lcd,&color[2],4);}
            }
        }
        if (y<480&&y>320)
        {
           
            for (int i = 0; i < 800; i++)
            {
                if (i<266)
                {
                    write(fd_lcd,&color[0],4);
                }
                else if (i<532)
                {
                    write(fd_lcd,&color[1],4);
                }
                else{write(fd_lcd,&color[2],4);}
            }
        }
        
        
        
        
            
    }


    // 关闭文件  
    close(fd_lcd);  


    return 0;
}
