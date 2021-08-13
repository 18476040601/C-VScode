#include "main.h"

extern unsigned int ID  ;

int main(int argc, char const *argv[])
{  
   #if(1)
	Init_Font();
	char buf2[128]={0};
	 Clean_Area(400,  
                120,  
                400, 
                80,
                0xffffff); 
	#endif
    
    INFO car_arr[10] ={0} ;
    car_arr[0].car_id = 0xf199931e;  
    car_arr[0].money = 6;  
    car_arr[1].car_id = 0x27e764a6;  
    car_arr[1].money = 6 ;  

    pthread_t tid1;
    pthread_create( &tid1 , NULL , get_car_id , NULL );
   
 
    pthread_t tid2;
    pthread_create( &tid2 , NULL ,  bmp_display , NULL );
    

    pthread_t tid3;
    pthread_create( &tid3 , NULL , time_get , NULL );
    #if(1)
    char buf [128] = {0} ;
    while(1)
    {           
       
        if ( ID != 0 )
        {
            if (ID == car_arr[0].car_id||ID == car_arr[1].car_id )
            {
                 if(car_arr[0].money >=2||car_arr[1].money >= 2 )
                    {
                        if(ID == car_arr[0].car_id && car_arr[0].money >=2)
                        {
                            car_arr[0].money -= 2 ;
                            printf("��ǰ����2Ԫ�� ���Ϊ��%d\n" , car_arr[0].money );
                            ID = 0 ;
                            Clean_Area(400,120, 400, 80 ,0xfffff); 
                            sprintf(buf2,"�� ��:%d",car_arr[0].money);                        
                            Display_characterX( 420,120,  buf2 , 0x0000ff, 2);//��ʾ���
                        }
                        else if(ID == car_arr[1].car_id && car_arr[1].money >=2)
                        {
                            car_arr[1].money -= 2 ;
                            printf("��ǰ����20Ԫ�� ���Ϊ��%d\n" , car_arr[1].money );
                            ID = 0 ;
                            Clean_Area(400,120, 400, 80 ,0xfffff); 
                            sprintf(buf2,"�� ��:%d",car_arr[1].money);                        
                            Display_characterX( 420,120,  buf2 , 0x0000ff, 2);//��ʾ���
                        }
                        else 
                        {
                            Clean_Area(400,0, 400, 200 ,0xffffff);                                        
                            Display_characterX( 420,70,  "����!!!" , 0xff0000, 3);
                            usleep(20000);
                        } 
                    }        
                 else
                     {
                        Clean_Area(400,0, 400, 200 ,0xffffff);                                        
                        Display_characterX( 420,70,  "����!!!" , 0xff0000, 3);
                        usleep(20000);
                    }                   
            }
            else
            {
                Clean_Area(400,0, 400, 200 ,0xffffff); 
                Display_characterX( 420,70,  "���Ų����ڣ�����" , 0xff0000, 3);
                usleep(20000);
            }
        }


    }
    #endif
    #if(0)
    char buf [128] = {0} ;
    while(1)
    {           
       
        if ( ID != 0 )
        {
            if (ID == car_arr[0].car_id && car_arr[0].money >= 2 )
            {
                car_arr[0].money -= 2 ;
                printf("��ǰ����20Ԫ�� ���Ϊ��%d\n" , car_arr[0].money );
                ID = 0 ;
                   #if(1)
                                Clean_Area(400,120, 400, 80 ,0xfffff); 

                                   sprintf(buf2,"��_��:%d",car_arr[0].money);                        
                                    Display_characterX(
                                                        420,          
                                                        120,          
                                                        buf2,   
                                                        0x0000ff,     
                                                        2
                                                        );
		                    #endif
            }
            else if (ID == car_arr[1].car_id && car_arr[1].money >= 2 )
            {
                car_arr[1].money -= 2 ;
                printf("��ǰ����20Ԫ�� ���Ϊ��%d\n" , car_arr[1].money );
                ID = 0 ;
                   #if(1)
                                Clean_Area(400,120, 400, 80 ,0xfffff); 

                                   sprintf(buf2,"��_��:%d",car_arr[1].money);                        
                                    Display_characterX(
                                                    420,          
                                                    120,          
                                                    buf2,   
                                                    0x0000ff,     
                                                    2
                                                    );
		                    #endif
            }
            else            
            {
                printf("ˢ��ʧ��,����Ŀ�꿨������\n" );
                ID = 0 ;
                 #if(1)
                                Clean_Area(400,0, 400, 200 ,0xffffff); 

                                                         
                                    Display_characterX(
                                                    470,          
                                                    70,          
                                                    "ˢ��ʧ��!!!" ,   
                                                    0xff0000,     
                                                    3
                                                    );
		                    #endif
            }
            
        }
        


    }
    #endif


    	UnInit_Font();
    return 0;
}
