#include "lcd.h"
#include "scale.h"
int lcd_fd;
unsigned int *mem_p; //定义无符号类型指针，用于存放映射地址
unsigned int W=450;
unsigned int H=315;
unsigned int L_W=1000;
unsigned int L_H=600;
unsigned int N_W=600;
unsigned int N_H=420;
//LCD初始化
void LCD_init(void)
{
	//打开屏幕
	lcd_fd = open(FB_PATH,O_RDWR);
	if(lcd_fd == -1)
	{
		printf("open lcd failure!\n");
		return ;
	}
	
	//I/O映射
	mem_p = (unsigned int *)mmap( NULL, 800*480*4 ,    	 	//映射fb内存空间长度 	 
					PROT_READ | PROT_WRITE,	//可读可写
					MAP_SHARED,     		//进程间共享机制
					lcd_fd, 				//lcd的文件描述符
					0);
	
	if(mem_p == MAP_FAILED)
	{
		printf("mmap failure!\n");
		return;
	}
}

//LCD撤消
void LCD_UnInit(void)
{
	close(lcd_fd);
	munmap(mem_p,800*480*4);
}
/***********************************************************************
* 功能：左右偏移图片
* 参数:  pathname 图片名字 (必须是在同工程目录下的图片)
*          start_x 起点X
*			start_y 起点Y
*			left_offset 左移偏移量
*			right_offset 右移偏移量
**********************************************************************/
void show_bmp_Xoffset(const char *pathname,int start_x,int start_y,int left_offset,int right_offset)
{
	int bmp_fd,i,x,y;
	unsigned short heigh,weight;
	unsigned char head_buff[54];//存储头信息的buff
	//打开屏幕
	bmp_fd = open(pathname,O_RDWR);
	if(bmp_fd == -1)
	{
		printf("open bmp failure!\n");
		return ;
	}
	
	read(bmp_fd,head_buff,54);
	//得到图片宽度
	weight = head_buff[19]<<8 | head_buff[18];
	
	//得到图片高度
	heigh = head_buff[23]<<8 | head_buff[22];
	
	if((weight+start_x) > 800)
	{
		printf("bmp weight+start_x big 800\n");
		return ;
	}
	
	if((heigh+start_y) > 480)
	{
		printf("bmp heigh+start_y big 800\n");
		return ;
	}
	
	
	//定义用于存放图片rgb的buff
	unsigned char bmp_buff[weight*heigh*3];
	unsigned int buff[weight*heigh];
	unsigned int T_buff[weight*heigh];
	
	//将图片像素读到buffer当中
	read(bmp_fd,bmp_buff,sizeof(bmp_buff));
	
	//将rgb合成一个像素点unsigned int
	for(i=0; i<weight*heigh; i++)
		buff[i] = bmp_buff[3*i+0] | bmp_buff[3*i+1]<<8 | bmp_buff[3*i+2]<<16;
	
	for(y=0; y<heigh; y++)
		for(x=0; x<weight; x++)
			T_buff[y*weight+x]=buff[(heigh-1-y)*weight+x];
		
	//处理T_buff 剔除 屏幕左边界至某列的图像像素点，再显示出来
	if(left_offset==0 && right_offset == 0 )
	{
		for(y=0;y<heigh;y++)  //图片高度 420  上下间距:30    
		{
				for(x=0;x<weight;x++)  //图片宽度 600  左右间距:100
				{
					*(mem_p + (y+start_y)*800 + x +start_x ) = T_buff[y*weight+x];	
				}
		}
		return;
	}
	//若有左偏移，则是剔除左边界至left_offset列的像素点
	if(left_offset>0 && left_offset<weight)
	{
			for(y=0;y<heigh;y++)
			{
				for(x=left_offset;x<weight;x++)
				{
					//*(mem_p + y*weight+ x - left_offset) = T_buff[y*weight+x];	//原本无偏移的代码
					//加上x,y偏移后的代码
					*(mem_p + (y+start_y)*800+ x - left_offset+start_x) = T_buff[y*weight+x];	
				}
			}
	}
	else if(right_offset>0 && right_offset<weight)//若有右偏移，则是剔除右边界至right_offset列的像素点
	{
			for(y=0;y<heigh;y++)
			{
				for(x=0;x<weight-right_offset;x++)
				{
					//*(mem_p + y*weight+ x + right_offset) = T_buff[y*weight+x];	
					
					//加上x,y偏移后的代码
					*(mem_p + (y+start_y)*800+ x + right_offset +start_x) = T_buff[y*weight+x];	
				}
			}
	}
	
	close(bmp_fd);
	
}

/***********************************************************************
* 功能：上下偏移图片
* 参数:  pathname 图片名字 (必须是在同工程目录下的图片)
*          start_x 起点X
*			start_y 起点Y
*			up_offset 上移偏移量
*			down_offset 下移偏移量
**********************************************************************/
void show_bmp_Yoffset(const char *pathname,int start_x,int start_y,int up_offset,int down_offset)
{
	if(up_offset>0&&down_offset>0)
	{
		printf("up_offset 和 down_offset 不能都有值");
		return;
	}
	int bmp_fd,i,x,y;
	unsigned short heigh,weight;
	unsigned char head_buff[54];//存储头信息的buff
	//打开屏幕
	bmp_fd = open(pathname,O_RDWR);
	if(bmp_fd == -1)
	{
		printf("open bmp failure!\n");
		return ;
	}
	
	read(bmp_fd,head_buff,54);
	//得到图片宽度
	weight = head_buff[19]<<8 | head_buff[18];
	
	//得到图片高度
	heigh = head_buff[23]<<8 | head_buff[22];
	
	if((weight+start_x) > 800)
	{
		printf("bmp weight+start_x big 800\n");
		return ;
	}
	
	if((heigh+start_y) > 480)
	{
		printf("bmp heigh+start_y big 800\n");
		return ;
	}
	
	
	//定义用于存放图片rgb的buff
	unsigned char bmp_buff[weight*heigh*3];
	unsigned int buff[weight*heigh];
	unsigned int T_buff[weight*heigh];
	
	//将图片像素读到buffer当中
	read(bmp_fd,bmp_buff,sizeof(bmp_buff));
	
	//将rgb合成一个像素点unsigned int
	for(i=0; i<weight*heigh; i++)
		buff[i] = bmp_buff[3*i+0] | bmp_buff[3*i+1]<<8 | bmp_buff[3*i+2]<<16;
	
	for(y=0; y<heigh; y++)
		for(x=0; x<weight; x++)
			T_buff[y*weight+x]=buff[(heigh-1-y)*weight+x];
		
	//若有左偏移，则是剔除左边界至left_offset列的像素点
	if(up_offset>0 && up_offset<heigh)
	{
			for(y=up_offset;y<heigh;y++)
			{
				for(x=0;x<weight;x++)
				{					
					//加上x,y偏移后的代码
					*(mem_p + (y-up_offset+start_y)*800+ x +start_x) = T_buff[y*weight+x];	
				}
			}
	}
	else if(down_offset>0 && down_offset<heigh)//若有右偏移，则是剔除右边界至right_offset列的像素点
	{
			for(y=0;y<heigh-down_offset;y++)
			{
				for(x=0;x<weight;x++)
				{
					//*(mem_p + y*weight+ x + right_offset) = T_buff[y*weight+x];	
					
					//加上x,y偏移后的代码
					*(mem_p + (y+start_y+down_offset)*800+ x +start_x) = T_buff[y*weight+x];	
				}
			}
	}
	
	close(bmp_fd);
	
}
/***********************************************************************
* 功能：放大缩小图片
* 参数:  pathname 原图名字 (必须是在同工程目录下的图片)
*          start_x 起点X
*			start_y 起点Y
*			d_w  目标图片宽度
*			d_h  目标图片高度
**********************************************************************/
void show_scalebmp(const char *pathname,int start_x,int start_y,int d_w,int d_h)
{
	int bmp_fd,i,x,y;
	unsigned short heigh,weight;
	unsigned char head_buff[54];//存储头信息的buff
	//打开屏幕
	bmp_fd = open(pathname,O_RDWR);
	if(bmp_fd == -1)
	{
		printf("open bmp failure!\n");
		return ;
	}
	
	read(bmp_fd,head_buff,54);
	//得到图片宽度
	weight = head_buff[19]<<8 | head_buff[18];
	
	//得到图片高度
	heigh = head_buff[23]<<8 | head_buff[22];

	if((d_w+start_x) > 800)
	{
		printf("bmp d_w+start_x big 800\n");
		return ;
	}
	
	if((d_h+start_y) > 480)
	{
		printf("bmp d_h+start_y big 480\n");
		return ;
	}
	
	//定义用于存放图片rgb的buff
	unsigned char bmp_buff[weight*heigh*3];
	
	unsigned int buff[d_w*d_h];

	//将原图图片像素读到buffer当中
	read(bmp_fd,bmp_buff,sizeof(bmp_buff));
	
	unsigned char bmp_scalebuff[d_w*d_h*3];
	
	ScalePicture(bmp_buff,weight,heigh,bmp_scalebuff,d_w,d_h);
	
	
	//将rgb合成一个像素点unsigned int
	for(i=0; i<d_w*d_h; i++)
		buff[i] = bmp_scalebuff[3*i+0] | bmp_scalebuff[3*i+1]<<8 | bmp_scalebuff[3*i+2]<<16;
	
	
	//图像倒序及显示
	for(y=0; y<d_h; y++)
		for(x=0; x<d_w; x++)
			*(mem_p + (y+start_y)*800+ start_x+x) = buff[(d_h-1-y)*d_w+x];
		
	close(bmp_fd);
	
}

//const char *pathname:图片路径
//int start_x：图片起始位置 x轴
//int start_y：图片起始位置 y轴
void show_bmp(const char *pathname,int start_x,int start_y)
{
	int bmp_fd,i,x,y;
	unsigned short heigh,weight;
	unsigned char head_buff[54];//存储头信息的buff
	//打开屏幕
	bmp_fd = open(pathname,O_RDWR);
	if(bmp_fd == -1)
	{
		printf("open bmp failure!\n");
		return ;
	}
	
	read(bmp_fd,head_buff,54);
	//得到图片宽度
	weight = head_buff[19]<<8 | head_buff[18];
	
	//得到图片高度
	heigh = head_buff[23]<<8 | head_buff[22];
	
	if((weight+start_x) > 800)
	{
		printf("bmp weight+start_x big 800\n");
		return ;
	}
	
	if((heigh+start_y) > 480)
	{
		printf("bmp heigh+start_y big 800\n");
		return ;
	}
	
	
	//定义用于存放图片rgb的buff
	unsigned char bmp_buff[weight*heigh*3];
	unsigned int buff[weight*heigh];

	
	//将图片像素读到buffer当中
	read(bmp_fd,bmp_buff,sizeof(bmp_buff));
	
	//将rgb合成一个像素点unsigned int
	for(i=0; i<weight*heigh; i++)
		buff[i] = bmp_buff[3*i+0] | bmp_buff[3*i+1]<<8 | bmp_buff[3*i+2]<<16;
	
	
	//图像倒序及显示
	for(y=0; y<heigh; y++)
		for(x=0; x<weight; x++)
			*(mem_p + (y+start_y)*800+ start_x+x) = buff[(heigh-1-y)*weight+x];
		
	close(bmp_fd);
	
}

void Big_PictureByPoint(const char *pathname,int pointX,int pointY)
{
	if(pointX<=100||pointX>=800-100-W) // 500
		return;
	if(pointY<=450-H)
		return;
	int bmp_fd,i,x,y;
	unsigned short heigh,weight;
	unsigned char head_buff[54];//存储头信息的buff
	//打开屏幕
	bmp_fd = open(pathname,O_RDWR);
	if(bmp_fd == -1)
	{
		printf("open bmp failure!\n");
		return ;
	}
	
	read(bmp_fd,head_buff,54);
	//得到图片宽度
	weight = head_buff[19]<<8 | head_buff[18];
	
	//得到图片高度
	heigh = head_buff[23]<<8 | head_buff[22];
	
	//pointY=480-pointY;
	pointY = 450 - pointY;	
	pointX = pointX-100;
	
	if(pointX>=600-W)
		return;
	if(pointY>=420-H)
		return;

	printf("I am lcd.c X:%d,Y:%d\n",pointX,pointY);
	//定义用于存放图片rgb的buff
	unsigned char bmp_buff[weight*heigh*3];
	unsigned char bmp_small[W*H*3];
	//将图片像素读到buffer当中
	read(bmp_fd,bmp_buff,sizeof(bmp_buff));
	int k,l;
	//截取图片 A[pointX,pointY] B[pointX+W,pointY] C[pointX,pointY+H],D[pointX+W,pointY+H]
	for(k=pointY;k<pointY+H;k++)
	{
		for(l=pointX;l<pointX+W;l++){
			bmp_small[((k-pointY)*W+l-pointX)*3]=bmp_buff[(k*W+l)*3];
			bmp_small[((k-pointY)*W+l-pointX)*3+1]=bmp_buff[(k*W+l)*3+1];
			bmp_small[((k-pointY)*W+l-pointX)*3+2]=bmp_buff[(k*W+l)*3+2];
		}
	}

	show_smallbmp(bmp_small,W,H,100,30,600,420);
			
	close(bmp_fd);
}


void show_smallbmp(unsigned char o_picture[],int o_w,int o_h,int start_x,int start_y,int d_w,int d_h)
{
	int i,x,y;
	if((d_w+start_x) > 800)
	{
		printf("bmp d_w+start_x big 800\n");
		return ;
	}
	
	if((d_h+start_y) > 480)
	{
		printf("bmp d_h+start_y big 480\n");
		return ;
	}
	
	
	unsigned int buff[d_w*d_h];
	
	unsigned char bmp_scalebuff[d_w*d_h*3];
	
	ScalePicture(o_picture,o_w,o_h,bmp_scalebuff,d_w,d_h);
	
	
	//将rgb合成一个像素点unsigned int
	for(i=0; i<d_w*d_h; i++)
		buff[i] = bmp_scalebuff[3*i+0] | bmp_scalebuff[3*i+1]<<8 | bmp_scalebuff[3*i+2]<<16;
	
	
	//图像倒序及显示
	for(y=0; y<d_h; y++)
		for(x=0; x<d_w; x++)
			*(mem_p + (y+start_y)*800+ start_x+x) = buff[(d_h-1-y)*d_w+x];
	
}
/****************************************************************
*	局部放大图片，根据用户点击的位置，例如：左下角（设定一个区域的），然后放大从这个点开始的右上角（从放大后的图片(1000*600) 取600*420像素点）
*	pathname : 图片名字
*	pointX : 点击位置X
*  pointY ：点击位置Y
****************************************************************/
void ExpandPicture(const char *pathname,int pointX,int pointY)
{
	double r_x,r_y;	
	int bmp_fd,i,x,y;
	unsigned short heigh,weight;
	unsigned char head_buff[54];//存储头信息的buff
	pointY = 450 - pointY;	
	pointX = pointX-100;
	
	if(pointX>600||pointX<0)
		return;
	if(pointY>420||pointY<0)
		return;

	r_x = pointX/(double)600;
	r_y = pointY/(double)420;
	
	printf("r_x:%f,r_y:%f\n",r_x,r_y);
	
	//打开屏幕
	bmp_fd = open(pathname,O_RDWR);
	if(bmp_fd == -1)
	{
		printf("open bmp failure!\n");
		return ;
	}
	
	//read(bmp_fd,head_buff,54);
	//得到图片宽度
	weight = head_buff[19]<<8 | head_buff[18];
	
	//得到图片高度
	heigh = head_buff[23]<<8 | head_buff[22];
	
	
	
	//定义用于存放图片rgb的buff
	unsigned char bmp_buff[600*420*3];
	
	//将图片像素读到buffer当中
	read(bmp_fd,bmp_buff,sizeof(bmp_buff));
	
	//放大图片后的像素数组
	unsigned char bmp_BigBuff[L_W*L_H*3];//bug (1) 1200*840*3 过于大
	
	//放大图片操作
	ScalePicture(bmp_buff,600,420,bmp_BigBuff,L_W,L_H);
	
	//放大后的图片数组
	unsigned int buff[L_W*L_H];
	
	//倒序放大后的图片数组
	unsigned int T_buff[L_W*L_H];
	
	//从放大后图片的数组中截取到的数组
	unsigned int G_buff[N_W*N_H];
	
	//将rgb合成一个像素点unsigned int
	for(i=0; i<L_W*L_H; i++)
		buff[i] = bmp_BigBuff[3*i+0] | bmp_BigBuff[3*i+1]<<8 | bmp_BigBuff[3*i+2]<<16;
	
	//获取放大后的图片数组的倒序数组
	for(y=0; y<L_H; y++)
		for(x=0; x<L_W; x++)
			T_buff[y*L_W+x]=buff[(L_H-1-y)*L_W+x];
		
	//下面，开始针对这个倒序数组进行截取操作，截取600*420,放入G_buff
			
	//一共分4种情况，左上 左下  右上 右下
	//按比例计算出位于放大2倍图片的点击坐标b_x,b_y
	int b_x,b_y;
	b_x=(int)(L_W*r_x);
	b_y=(int)(L_H*r_y);
	printf("b_x:%d, b_y:%d\n",b_x,b_y);
	//点击左上角，从该点往右取600像素点，往下取420像素点得到一个600*420的图片
	if(b_x<L_W-600&&b_y<L_H-420)
	{
		printf("1\n");	
		
		for(y=b_y;y<b_y+N_H;y++)
		{
			for(x=b_x;x<b_x+N_W;x++)
			{
				G_buff[(y-b_y)*N_W+x-b_x]=T_buff[y*L_W+x];
			}
		}
	}
	else if(b_x<L_W-600&&b_y>L_H-180)//点击左下角，取右上
	{
		printf("2\n");
		for(y=b_y-N_H;y<b_y;y++)
		{
			for(x=b_x;x<b_x+N_W;x++)
			{
				G_buff[(y-b_y+N_H)*N_W+x-b_x]=T_buff[y*L_W+x];
			}
		}
	}
	else if(b_x>L_W-400&&b_y<L_H-420)//点击右上角,取左下
	{
		printf("3\n");
		for(y=b_y;y<b_y+N_H;y++)
		{
			for(x=b_x-N_W;x<b_x;x++)
			{
				G_buff[(y-b_y)*N_W+x-b_x+N_W]=T_buff[y*L_W+x];
			}
		}
	}
	else if(b_x>L_W-400&&b_y>L_H-180)//点击右下角，取左上    //L_W1000  L_H600
	{
		printf("4\n");
		for(y=b_y-N_H;y<b_y;y++)
		{
			for(x=b_x-N_W;x<b_x;x++)
			{
				G_buff[(y-b_y+N_H)*N_W+x-b_x+N_W]=T_buff[y*L_W+x];   
			}
		}
	}
	//让它完美的方法，1.扩大L_W,L_H，但是因为放大这个后会报错所以不行。
	//2.往左 取不到600像素点时，要往右取像素点，同理，往右，往上，往下都这样做，就可以点击任意地方 取到600*420 图片了。
	//3.为什么必须要取600*420？因为这个局部放大原理是：将原图（600*420）放大为 （L_W*L_H） 然后从放大后的图片(L_W*L_H)获取 600*420，获取到了就输出到屏幕
		
	
	//显示G_buff到屏幕上
	for(y=0; y<N_H; y++)
		for(x=0; x<N_W; x++)
			*(mem_p + (y+30)*800+ 100+x) = G_buff[y*N_W+x];
		
	//关闭文件流
	close(bmp_fd);
	
}