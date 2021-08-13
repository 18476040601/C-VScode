#include "main.h"

extern unsigned int ID ;
void * get_car_id(void * arg);

int main(int argc, char const *argv[])
{   
    // 定义一个结构体数据组， 并设定可以存放10个卡的信息以及余额
    INFO car_arr[10] ={0} ;

    car_arr[0].car_id = 0x27e764a6;  // 手动添加一个卡片信息
    car_arr[0].money = 100 ;  // 设置其余额为 100 元
    car_arr[1].car_id = 0xf199931e;  // 手动添加一个卡片信息
    car_arr[1].money = 100 ;  // 设置其余额为 100 元


    // 初始化LCD 显示器

    // 创建各个功能线程 （后台）

        // 时间刷线线程

        // 站点显示线程

        // 广告播放线程

        //RFID 读卡号线程
        pthread_t tid1;
        pthread_create( &tid1 , NULL , get_car_id , NULL );

    while(1)
    {
        if ( ID != 0 )
        {
            for(int i; i=0 ; i++ )
            if (ID == car_arr[i].car_id && car_arr[i].money >= 2 )
            {
                car_arr[i].money -= 2 ;
                printf("当前消费两元， 余额为：%d\n" , car_arr[i].money );
                ID = 0 ;
            }else
            {
                printf("刷卡失败，当前余额：%d\n" , car_arr[i].money );
                ID = 0 ;
            }
            
        }
        


    }




    return 0;
}
