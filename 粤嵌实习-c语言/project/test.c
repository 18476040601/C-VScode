#include "test.h"
void * test (void * arg)
{
	Init_Font();////��ʾ�����ǰ�ȵ��ñ��������г�ʼ��
#if(0)
	Clean_Area( 
				400, //x������ʼ��
                0,   //y������ʼ��
				400, //���ƵĿ��
				200, //���Ƶĸ߶�
				0xffffff
				);  //����Ļָ�����������ɫ
#endif
	Display_characterX(
						 400,          //x������ʼ��
						 0,          //y������ʼ��
						"����Ϣ",   //GB2312 �����ַ���
						 0x0000ff,     //������ɫֵ
						 3
						 );	

	UnInit_Font();	 //�����˳�ǰ�����ñ�����	

	return 0;
}
