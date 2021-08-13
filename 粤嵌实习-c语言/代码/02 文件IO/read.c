#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    //打开文件
    char buf [] = "./Even.c" ; // 把字符串常量"./Even.c" 拷贝到数组buf 所对应的内存中
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

    // 读取文件的内容
    char msg [128] = {0} ;

    ssize_t ret_val = read  ( fd , msg , 128 );
    if (-1 == ret_val )
    {
        perror("读取失败>>");
        return -1 ;
    }
    else{
        printf("成功读取%ld个字节， 内容为：%s\n" , ret_val , msg );
    }
    
    // 关闭文件
    close(fd );
    

    return 0;
}
