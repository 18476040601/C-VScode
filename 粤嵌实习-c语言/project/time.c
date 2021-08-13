#include "time.h"

extern unsigned int ID ;

void * time_get(void * arg)
{
    
    Init_Font();

	Clean_Area(0,  //x������ʼ��
               0,  //y������ʼ��
			    400, //���ƵĿ��
				200,//���Ƶĸ߶�
				0x66ffcc); //����Ļָ�����������ɫ
    #if(0)
    Clean_Area(400,  //x������ʼ��
                0,  //y������ʼ��
                400, //���ƵĿ��
                200,//���Ƶĸ߶�
                0xffffff); //����Ļָ�����������ɫ
    #endif
    time_t timep;

    char buf [128] = {0} ;
    while(1)
    {

        Clean_Area(0,0, 400, 200 ,0x66ffcc); //����Ļָ�����������ɫ
    //    Clean_Area(400,0, 400, 200 ,0xfffff); //����Ļָ�����������ɫ

        char *wday[] = {"��", "һ", "��", "��", "��", "��", "��"};

        time (&timep);
        //strlen �����ַ����ĳ��ȣ���������������
        //n �������ƿ����ĳ��ȣ���ȫ�汾��ƴ�ӿ�����
        struct tm *p;
        p = localtime(&timep);//��localtime������ת��Ϊstruct tm�ṹ��
        sprintf( buf ,"����:%d��%d��%d��", (1900 + p->tm_year),(1+ p->tm_mon), p->tm_mday);
        // printf(buf);
        Display_characterX(20,          //x������ʼ��
                            30,          //y������ʼ��
                            buf,   //GB2312 �����ַ���
                            0x000000,     //������ɫֵ
                            2);
        sprintf( buf ,"����%s", wday[p->tm_wday]);
        // printf(buf);
        Display_characterX(20,          //x������ʼ��
                            80,          //y������ʼ��
                            buf,   //GB2312 �����ַ���
                            0x000000,     //������ɫֵ
                            2);	
        sprintf( buf ,"ʱ��:%d:%d:%d", p->tm_hour, p->tm_min, p->tm_sec);
        // printf(buf);
        Display_characterX(20,          //x������ʼ�� 
                            130,          //y������ʼ��
                            buf,   //GB2312 �����ַ���
                            0x000000,     //������ɫֵ
                            2);	

#if(0)
    sprintf(buf,"��_�ţ�%d",ID);                        
    Display_characterX(
                    420,          //x������ʼ��
                    30,          //y������ʼ��
                    buf,   //GB2312 �����ַ���
                    0x0000ff,     //������ɫֵ
                    2
                    );	
    sprintf(buf,"��_�%d",ID);                        
    Display_characterX(
                    420,          //x������ʼ��
                    120,          //y������ʼ��
                    buf,   //GB2312 �����ַ���
                    0x0000ff,     //������ɫֵ
                    2
                    );
#endif


        sleep(1);
    }

    UnInit_Font();

}