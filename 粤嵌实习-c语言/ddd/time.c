#include "time.h"




void * show_time(void * arg)
{
    Init_Font();

	Clean_Area(0,  //x������ʼ��
               0,  //y������ʼ��
				800, //���ƵĿ��
				480,//���Ƶĸ߶�
				0x0); //����Ļָ�����������ɫ

    time_t timep;
    

    char buf [128] = {0} ;

    while(1)
    {
        Clean_Area(0,0, 400, 240 ,0xFFFFFF); //����Ļָ�����������ɫ

        time (&timep);
        //strlen �����ַ����ĳ��ȣ���������������
        //n �������ƿ����ĳ��ȣ���ȫ�汾��ƴ�ӿ�����
        struct tm *p;
        p = localtime(&timep);//��localtime������ת��Ϊstruct tm�ṹ��

        sprintf( buf ,"����:%d��%d��%d��", 1900 + p->tm_year , 1+ p->tm_mon ,p->tm_mday);
        Display_characterX(0,          //x������ʼ��
                            50,          //y������ʼ��
                            buf,   //GB2312 �����ַ���
                            0x0,     //������ɫֵ
                            2);	
      

        sprintf( buf ,"ʱ��:%d:%d:%d", p->tm_hour, p->tm_min, p->tm_sec);
        Display_characterX(0,          //x������ʼ��
                            150,          //y������ʼ��
                            buf,   //GB2312 �����ַ���
                            0x0,     //������ɫֵ
                            2);	
        sleep(1);
    }

    UnInit_Font();

}