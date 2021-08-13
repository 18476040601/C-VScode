#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "time.h"
#include "RFID.h"
#include "LCD.h"

// 声明一个结构体用来存放卡号以及其对应的余额
typedef struct car_info
{
    unsigned int car_id ;
    int money ;
}INFO ;

int flag=0;


extern int ID;


void * get_car_id(void * arg);



int main(int argc, char const *argv[])
{   
    char buf[128] = {0};

    // 定义一个结构体数据组， 并设定可以存放10个卡的信息以及余额
    INFO car_arr[10] ={0} ;

    car_arr[0].car_id = 0xf7952ea6;  // 手动添加一个卡片信息
    car_arr[0].money = 100 ;  // 设置其余额为 100 元


    // 初始化LCD 显示器

    // 创建各个功能线程 （后台）

        //RFID 读卡号线程
        pthread_t tid1;
        pthread_create( &tid1 , NULL , get_car_id , NULL );

        // 时间刷线线程
        pthread_t tid2;
        pthread_create( &tid2 , NULL , show_time , NULL );

        // 站点显示线程
        pthread_t tid3;
        pthread_create( &tid3 , NULL , show_bmp , NULL );

        // 广告播放线程
        //pthread_t tid4;
        //pthread_create( &tid4 , NULL , show_ad , NULL );

        

    while(1)
    {
        if ( ID != 0 )
        {
            if (ID == car_arr[0].car_id && car_arr[0].money >= 2  )
            {
                flag = 1;
                car_arr[0].money -= 20 ;
                printf("当前消费两元， 余额为：%d\n" , car_arr[0].money );

                Clean_Area(400,0, 400, 240 ,0xFFFFFF);
                sprintf( buf ,"卡号：%#.8x",car_arr[0].car_id );
                Display_characterX(500,          //x坐标起始点
                            60,          //y坐标起始点
                            buf,   //GB2312 中文字符串
                            0x000000,     //字体颜色值
                            2);	
                  
                sprintf( buf,"余额：%d",car_arr[0].money );
                Display_characterX(500,          //x坐标起始点
                            120,          //y坐标起始点
                            buf,   //GB2312 中文字符串
                            0x000000,     //字体颜色值
                            2);	
               
                sleep(2);
                flag = 0;
                ID = 0;    
            }
            else
            {
                flag = 1;
                printf("刷卡失败!\n" );
                Clean_Area(400,0, 400, 240 ,0xFFFFFF);
                sprintf( buf,"刷卡失败!");
                Display_characterX(500,          //x坐标起始点
                            80,          //y坐标起始点
                            buf,   //GB2312 中文字符串
                            0x000000,     //字体颜色值
                            2);	
                
                sleep(2);
                flag = 0;
                ID = 0;
            }
            
            
        }


    }




    return 0;
}
