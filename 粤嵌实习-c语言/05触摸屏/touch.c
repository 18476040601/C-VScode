#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

#define     TS_PATH     "/dev/input/event0"

int main(int argc, char const *argv[])
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

        // 无所欲为
        printf("Time:%d:%d \t Type:%d \t Code:%d \t Value:%d\n",
                ts_event.time.tv_sec ,
                ts_event.time.tv_usec ,
                ts_event.type,
                ts_event.code,
                ts_event.value);
    }

    // 关闭文件释放资源
    close(fd_ts);
    
    return 0;
}
