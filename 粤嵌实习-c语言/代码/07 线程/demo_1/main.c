#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>



void Exit_lcd();
void Exit( void );
int init_ts( void );
int init_lcd( void );
void * ts_get( void * arg );
int show(int x_s,int y_s,char *bmpname);

int flag = 0 ;

int main(int argc, char const *argv[])
{
    
    init_lcd( ) ;
    init_ts( );

    pthread_t TID ;
    pthread_create(&TID,  NULL , ts_get , NULL );


    int num = 0 ;
    char FileName[128] = {0} ;

    while(1)
    {
        if (flag) // 逻辑判断非零则真
        {
            num ++ ;
            if ( num > 81 )
            {
                num = 0 ;
                bzero(FileName, 128);
            }
            
            sprintf( FileName ,"/mnt/udisk/4/3/Frame%d.bmp" , num);
            show(0,0, FileName ); 
            usleep(2000);
        }

    }

	Exit_lcd ();



    return 0;
}
