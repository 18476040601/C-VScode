#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    //打开文件
    char buf [] = "./wks.c" ; // 把字符串常量"./wks.c" 拷贝到数组buf 所对应的内存中
    int fd = open( buf , O_RDWR );
    if ( -1 == fd  )
    {
        printf("打开文件失败!!!\n") ;
        perror("失败原因1>>>");
        printf("失败原因2>>>%s\n" , strerror(errno)) ;
        fprintf( stderr , "失败原因3>>>%s\n" , strerror(errno)) ;
        return -1 ;
    }
    else
    {
        printf("打开文件成功，描述符为：%d\n" , fd) ;
    }
    
    

    return 0;
}
