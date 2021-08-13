
// 横竖两条线移动

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>


void delay(unsigned int i)
{
    unsigned int x,y;
    for (x = 0; x < i; x++)
    {
        for(y=125;y>0;y--);
    }
    
}

int main(int argc, char const *argv[])
{
    // 打开LCD 对应的设备文件
    int fd_lcd =  open("/dev/fb0", O_RDWR) ; // 以可读写的方式打开LCD设备文件
    if ( -1 == fd_lcd )
    {
        perror("open lcd error");
        return -1 ;
    }


    // 内存映射
    int * p_lcd = mmap(NULL, 800*480*4, // 宽*高*每个像素4字节
             PROT_READ | PROT_WRITE , MAP_SHARED  , fd_lcd , 0 );
    if (MAP_FAILED == p_lcd)
    {
        perror("mmap error");
        return -1 ;
    }
    


    // 写入RGB颜色值
	int color = 0x00E5EE; // & 取地址， 取得color 的内存地址
	int color2 = 0xFFFFFF;

    int i=0,j=0;
    while (1)
    {
         i++;
         j++;   
            
        for (int y = 0; y < 480 ; y++)
        {
            for (int x = 0; x < 800 ; x++)
            {
                if(i == x || i == x+1 || j == y ||j == y+1)
                    *(p_lcd+x+y*800) = color2 ;
                else
                    *(p_lcd+x+y*800) = color ;
            }

            if(i == 800)
                i = 0 ;
            if(j == 480)
                j = 0 ;
        }
    
    }
    
    

    // 解除内存映射
    munmap( p_lcd , 800*480*4 );
    // 关闭文件  
    close(fd_lcd);  


    return 0;
}




