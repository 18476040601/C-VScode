/*************选择排序和冒泡排序方法*************************/

/*********************选择排序******************************/
/*#include<stdio.h>
int main()
{
	int i = 0;         //定义一个i并且赋初值为0，i作为数组的下标
	int j = 0;      //定义j并且赋初值为0，j作为找到最大值时所对应的下标
	int k;            //定义一个k，用来保存此次循环中最大值的下标
	int temp;         //定义一个中间变量temp，供以后交换值的时候使用
	int a[]={4,5,6,72,1,7,9,3,};    //定义了一个9个数的数组，并且初始化
	int len = sizeof(a)/sizeof(a[0]);  //len是数组的大小
	for(i = 0;i<len-1;i++)        //判断i是否小于len-1，执行下面的语句
	{
		k = i;           //假设此次循环中的最大值就是当前的值   
		for(j = i+1;j<len;j++)
		{
			if(a[j]>a[k])    //将假设的当前最大值与后面的值比较
			{
				k = j;     //若后面的值更大，则交换下标
			}
		}，当前最大值
		if(k != i)       //比较之后如果此次循环中最大值并非当前值
		{ 
			temp = a[i];   //将此次循环中的最大值与a[k]交换
			a[i] = a[k];
			a[k] = temp;
		}
	}
	for(i=0;i<len;i++)       //利用for循环将结果依次输出
	{
		printf("%d ",a[i]);
	}
	return 0;
}*/
/*************************冒泡排序******************************/
/*#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int temp;
	int a[10] = {9,8,7,6,5,4,3,2,1,0};
	int len = sizeof(a)/sizeof(a[0]);
	for(i = 0;i<len-1;i++)
	{
		for(j = 0;j< len-1-i;j++)
		{
			if(a[ｊ+1]>a[ｊ])
			{
				temp = a[ｊ+1];
				a[ｊ+1] = a[ｊ];
				a[ｊ] = temp;
			}
		}
	}
	for(i = 0;i<len;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}*/