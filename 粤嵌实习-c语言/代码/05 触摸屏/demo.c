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
    int  x, y ;
    struct input_event ts_event ; // 定义一个结构体变量 ts_event 用来存放读取到的数据
    while(1)
    {

        read(fd_ts , &ts_event , sizeof(ts_event));
        
        // 数据分析得到坐标值
        if ( ts_event.type == EV_ABS )  // 先判断是不是触摸屏事件
        {
            if (ts_event.code == ABS_X) // 判断是不是 X轴
            {
                x = ts_event.value*800/1024; // 把当前的值， 存入到X中  [黑色边框]
                // x = ts_event.value ; // 把当前的值， 存入到X中 【蓝色边框】
            }
            else if (ts_event.code == ABS_Y)// 判断是不是 Y轴
            {
                y = ts_event.value*480/600 ;// 把当前的值， 存入到Y中  [黑色边框]
                // y = ts_event.value ;// 把当前的值， 存入到Y中  【蓝色边框】
            }
            
        }
        

        // 无所欲为
        // 实现松手检测， 当用户松手后输出最后的坐标值
        if (ts_event.type == EV_KEY && ts_event.code == BTN_TOUCH && ts_event.value == 0  )
        {
            printf("(%d,%d)\n" , x, y );
        }
        
    }

    // 关闭文件释放资源
    close(fd_ts);
    
    return 0;
}
