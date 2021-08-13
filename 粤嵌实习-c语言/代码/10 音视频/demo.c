#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define     FIFO_PATH       "/tmp/my_fifo" 

int main(int argc, char const *argv[])
{
    sprintf(cmd , "mplayer -quiet -slave -input file=/tmp/my_fifo -geometry 0:0 -zoom -x 800 -y 480 %s  &" , fileanem )
    system(cmd);

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
    char * msg = "seek +5\n";
    while(1)
    {
        int ret_val = write(fd_fifo , msg , strlen(msg) ); 
        printf("成功发送%d字节数据...\n" , ret_val);
        sleep(4);
    }



    close(fd_fifo);
    


    return 0;
}
