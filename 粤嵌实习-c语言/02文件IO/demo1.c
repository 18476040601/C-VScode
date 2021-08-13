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
    char buf [] = "./wks.c" ; // 把字符串常量"./wks.c" 拷贝到数组buf 所对应的内存中
    int fd = open( buf , O_RDWR );
    if ( -1 == fd  )
    {
        printf("打开文件失败!!!\n") ;
        perror("失败原因1>>>");
        printf("失败原因2>>>%s\n" , strerror(errno)) ;
        fprintf( stderr , "失败原因3>>>%suods\n" , strerror(errno)) ;
        return -1 ;
    }
    else
    {
        printf("打开文件成功，描述符为：%d\n" , fd) ;
    }

    // 写入内容
    char * msg = "Hello wks" ; // 使用一个指针msg 指向字符串常量 "Hello wks"
    int msg_len = strlen(msg) ; // strlen 计算某个字符串的长度（不包含结束符\0）
    ssize_t ret_val =  write ( fd  , msg , msg_len ); 
    if ( -1 == ret_val )
    {
        perror("写入失败>>>");
        return -1 ;
    }
    else{
        printf("成功写入%ld字节..\n" , ret_val);
    }

    // 把读写位置偏移回到文件开头
    lseek( fd , 0 , SEEK_SET );

    char msg_4_read [128] = {0} ; 
    ret_val = read  ( fd , msg_4_read , 128 );
    if (-1 == ret_val )
    {
        perror("读取失败>>");
        return -1 ;
    }
    else{
        printf("成功读取%ld个字节， 内容为：%s\n" , ret_val , msg_4_read );
    }
    

    // 关闭文件
    close(fd);
    
    

    return 0;
}
