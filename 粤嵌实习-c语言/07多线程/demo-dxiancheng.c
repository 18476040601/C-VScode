#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>




void * CuiHua (void * arg )
{

    while( 1 )
    {
        printf("%d__%s\n" , __LINE__ , __FUNCTION__ );
    }

}

int main(int argc, char const *argv[])
{
    pthread_t TID ; // 定义一个变量用来存放线程的编号

    int ret_val = pthread_create(&TID , NULL , CuiHua , NULL );
    if ( ret_val != 0 )
    {
        fprintf(stderr , "线程创建失败：%s\n" , strerror(ret_val));
        return -1 ;
    }
    else
    {
        printf("线程创建成功,ID号为：%ld！！！\n" , TID) ;
    }


    while( 1 )
    {
        printf("%d__%s\n" , __LINE__ , __FUNCTION__ );
    }
    


    return 0;
}
