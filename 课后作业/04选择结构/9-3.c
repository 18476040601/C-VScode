#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("enter num:");
	scanf("%d", &num);
	if (num > 99999 || num < 0)
	{
		printf("请输入0~99999之间的数字\n");
		return -1;
	}
	if (num % 10 >= 0)
	{
		printf("%d ", num % 10);
	}
	if (num % 100 >= 10)
	{
		printf("%d ", (num % 100) / 10);
	}
	if (num % 1000 >= 100)
	{
		printf("%d ", (num % 1000) / 100);
	}
	if (num % 10000 >= 1000)
	{
		printf("%d ", (num % 10000) / 1000);
	}
	if (num / 10000 > 0)
	{
		printf("%d ", num / 10000);
	}
	printf("\n");
	system("pause");
	return 0;
}
