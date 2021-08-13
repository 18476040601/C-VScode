#include "scale.h"
/*****************************************************************************************
*	���ܣ���ȡ�Ŵ���С���ͼƬ���ص�����
*	���� pColorData ԭͼ���ص�����
*		   o_w o_h ԭͼ��� �� �߶�
*		   pColorDataMid Ŀ��ͼƬ���ص�����
*		   d_w d_h Ŀ��ͼƬ��Ⱥ͸߶�
*****************************************************************************************/
void ScalePicture(unsigned char pColorData[],int o_w,int o_h,unsigned char pColorDataMid[],int d_w,int d_h)
{
	int hnum,wnum;
	for ( hnum = 0; hnum < d_h; hnum++)
		for ( wnum = 0; wnum < d_w; wnum++)
		{
			double d_original_img_hnum = (hnum+0.5)*o_h / (double)d_h-0.5;
			double d_original_img_wnum = (wnum+0.5)*o_w / (double)d_w-0.5;
			int i_original_img_hnum = d_original_img_hnum;
			int i_original_img_wnum = d_original_img_wnum;
			double distance_to_a_x = d_original_img_wnum - i_original_img_wnum;//��ԭͼ������a���ˮƽ����  
			double distance_to_a_y = d_original_img_hnum - i_original_img_hnum;//��ԭͼ������a��Ĵ�ֱ����  
	 
			int original_point_a = i_original_img_hnum*o_w*3 + i_original_img_wnum * 3;//����λ��ƫ��������Ӧ��ͼ��ĸ����ص�RGB�����,�൱�ڵ�A    
			int original_point_b = i_original_img_hnum*o_w*3 + (i_original_img_wnum + 1) * 3;//����λ��ƫ��������Ӧ��ͼ��ĸ����ص�RGB�����,�൱�ڵ�B  
			int original_point_c = (i_original_img_hnum + 1)*o_w*3 + i_original_img_wnum * 3;//����λ��ƫ��������Ӧ��ͼ��ĸ����ص�RGB�����,�൱�ڵ�C   
			int original_point_d = (i_original_img_hnum + 1)*o_w*3 + (i_original_img_wnum + 1) * 3;//����λ��ƫ��������Ӧ��ͼ��ĸ����ص�RGB�����,�൱�ڵ�D   
			
			if (i_original_img_hnum >= o_h - 1)
			{
				original_point_c = original_point_a;
				original_point_d = original_point_b;
			}
			if (i_original_img_wnum >= o_w - 1)
			{
				original_point_b = original_point_a;
				original_point_d = original_point_c;
			}
			int pixel_point = hnum*d_w*3 + wnum * 3;//ӳ��߶ȱ任ͼ������λ��ƫ����  
			pColorDataMid[pixel_point] =
				pColorData[original_point_a] * (1 - distance_to_a_x)*(1 - distance_to_a_y) +
				pColorData[original_point_b] * distance_to_a_x*(1 - distance_to_a_y) +
				pColorData[original_point_c] * distance_to_a_y*(1 - distance_to_a_x) +
				pColorData[original_point_c] * distance_to_a_y*distance_to_a_x;
			pColorDataMid[pixel_point + 1] =
				pColorData[original_point_a + 1] * (1 - distance_to_a_x)*(1 - distance_to_a_y) +
				pColorData[original_point_b + 1] * distance_to_a_x*(1 - distance_to_a_y) +
				pColorData[original_point_c + 1] * distance_to_a_y*(1 - distance_to_a_x) +
				pColorData[original_point_c + 1] * distance_to_a_y*distance_to_a_x;
			pColorDataMid[pixel_point + 2] =
				pColorData[original_point_a + 2] * (1 - distance_to_a_x)*(1 - distance_to_a_y) +
				pColorData[original_point_b + 2] * distance_to_a_x*(1 - distance_to_a_y) +
				pColorData[original_point_c + 2] * distance_to_a_y*(1 - distance_to_a_x) +
				pColorData[original_point_c + 2] * distance_to_a_y*distance_to_a_x;
	 
		}
}
