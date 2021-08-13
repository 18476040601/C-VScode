#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "time.h"
#include "RFID.h"
#include "LCD.h"

// ����һ���ṹ��������ſ����Լ����Ӧ�����
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

    // ����һ���ṹ�������飬 ���趨���Դ��10��������Ϣ�Լ����
    INFO car_arr[10] ={0} ;

    car_arr[0].car_id = 0xf7952ea6;  // �ֶ����һ����Ƭ��Ϣ
    car_arr[0].money = 100 ;  // ���������Ϊ 100 Ԫ


    // ��ʼ��LCD ��ʾ��

    // �������������߳� ����̨��

        //RFID �������߳�
        pthread_t tid1;
        pthread_create( &tid1 , NULL , get_car_id , NULL );

        // ʱ��ˢ���߳�
        pthread_t tid2;
        pthread_create( &tid2 , NULL , show_time , NULL );

        // վ����ʾ�߳�
        pthread_t tid3;
        pthread_create( &tid3 , NULL , show_bmp , NULL );

        // ��沥���߳�
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
                printf("��ǰ������Ԫ�� ���Ϊ��%d\n" , car_arr[0].money );

                Clean_Area(400,0, 400, 240 ,0xFFFFFF);
                sprintf( buf ,"���ţ�%#.8x",car_arr[0].car_id );
                Display_characterX(500,          //x������ʼ��
                            60,          //y������ʼ��
                            buf,   //GB2312 �����ַ���
                            0x000000,     //������ɫֵ
                            2);	
                  
                sprintf( buf,"��%d",car_arr[0].money );
                Display_characterX(500,          //x������ʼ��
                            120,          //y������ʼ��
                            buf,   //GB2312 �����ַ���
                            0x000000,     //������ɫֵ
                            2);	
               
                sleep(2);
                flag = 0;
                ID = 0;    
            }
            else
            {
                flag = 1;
                printf("ˢ��ʧ��!\n" );
                Clean_Area(400,0, 400, 240 ,0xFFFFFF);
                sprintf( buf,"ˢ��ʧ��!");
                Display_characterX(500,          //x������ʼ��
                            80,          //y������ʼ��
                            buf,   //GB2312 �����ַ���
                            0x000000,     //������ɫֵ
                            2);	
                
                sleep(2);
                flag = 0;
                ID = 0;
            }
            
            
        }


    }




    return 0;
}
