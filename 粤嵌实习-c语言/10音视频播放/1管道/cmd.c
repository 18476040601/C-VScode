#include "cmd.h"


#define     FIFO_PATH       "/tmp/my_fifo"



int main(int argc, char const *argv[])
{
    
    system("mplayer -quiet -slave -input file=/tmp/my_fifo -geometry 0:0 -zoom -x 800 -y 480 Faded3.avi  &");

    printf("MUSIC PALY !!\n");

    // 创建管道文件
    if(access(FIFO_PATH , F_OK )) // 先判断文件是否存在如果不存在则创建
    {
        if(mkfifo(FIFO_PATH , 0666 ))
        {
            perror("mkfifo error");
            return -1 ;
        }
    }
    else{
        printf("管道文件已存在不需要创建！！！！\n");
    }

    // 打开管道文件
    int fd_fifo = open (FIFO_PATH , O_RDWR );
    if (-1 == fd_fifo)
    {
        perror("open fifo error");
        return -1 ;
    }
    else{
        printf("打开管道文件成功！！！！\n");
    }

    // 发送命令
    char * msg1 = "seek -5\n";  // 视频退回到5秒前
    char * msg2 = "seek +5\n";  // 视频退回到5秒后
    char * msg3 = "pause\n" ;   //暂停或继续
    while(1)
    {
        for(int x; x > 0; x++ )
    {
            if ( x < 300)
        {
                int ret_val = write(fd_fifo , msg1 , strlen(msg1) ); 
                printf("成功发送%d字节数据...\n" , ret_val);
                sleep(4);
        }
            if ( x > 500)
        {
                int ret_val = write(fd_fifo , msg2 , strlen(msg2) ); 
                printf("成功发送%d字节数据...\n" , ret_val);
                sleep(4);

        } 

            if (x>300&&x<500)
        {
               int ret_val = write(fd_fifo , msg3 , strlen(msg3) ); 
                printf("成功发送%d字节数据...\n" , ret_val);
                sleep(4);

        }
             
    }  
    }



    close(fd_fifo);
    


    return 0;
}
