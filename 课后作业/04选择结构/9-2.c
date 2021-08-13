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
	if (num / 10000 > 0) //取出万位数字
	{
		printf("%d ", num / 10000);
	}
	if (num % 10000 >= 1000) //取余10000则可以取出低四位的数据，除以1000则得到千位的数字
	{
		printf("%d ", (num % 10000) / 1000);
	}
	if (num % 1000 >= 100) //取余1000则可以取出低三位的数据，除以100则得到百位的数字
	{
		printf("%d ", (num % 1000) / 100);
	}
	if (num % 100 >= 10) //取余100则可以取出低两位的数据，除以10则得到十位的数字
	{
		printf("%d ", (num % 100) / 10);
	}
	if (num % 10 >= 0) //取余10则取出个位数字
	{
		printf("%d ", num % 10);
	}
	printf("\n");
	system("pause");
	return 0;
}
