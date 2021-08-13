#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("enter num:"); //输入数字
	scanf("%d", &num);
	if (num > 99999 || num < 0)
	{
		printf("请输入0~99999之间的正数\n");
		return -1;
	}
	if (num >= 10000)
	{
		printf("该数为5位数\n");
	}
	else if (num >= 1000)
	{
		printf("该数为4位数\n");
	}
	else if (num >= 100)
	{
		printf("该数为3位数\n");
	}
	else if (num >= 10)
	{
		printf("该数为2位数\n");
	}
	else
	{
		printf("该数为1位数\n");
	}
	system("pause");
	return 0;
}
