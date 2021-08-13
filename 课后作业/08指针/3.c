/*
题目：
     输入10个整数,将其中最小的数与第一个数对换, 把最大的数与最后一个数对换。
    写3个函数:
        1. 输人10个数;
        2. 进行处理;
        3. 输出10个数。
解题思路： 
    在进行数值逐个比较的同时找到最小值的空间地址以及最大值的空间地址，
    使用这两个空间中的数据最终与第一和最后数据进行对换即可。
*/

// WKS
#if (1)

#include <stdio.h>


void scan(int *array, int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
}

void print(int *array, int n)
{

    int i;
    for (i = 0; i < n; i++)
        printf("%-5d", array[i]);

    printf("\n");
}

void change(int *array, int n)
{
    int max_num = array[0], min_num = array[0];
    int *p_max = NULL, *p_min = NULL;
    for (int i = 1; i < n; i++)
    {
        if (min_num > array[i])
        { 
            //逐个比对后找出最小值
            min_num = array[i];
            p_min = &array[i]; //逐个比对后找到最小值的空间地址
        }
        if (max_num < array[i])
        { 
            //逐个比对后找出最大值
            max_num = array[i];
            p_max = &array[i]; //逐个比对后找到最大值的空间地址
        }
    }
    int tmp;
    tmp = *p_min; *p_min = array[0]; array[0] = tmp; //最小值与第一个数据交换
    tmp = *p_max; *p_max = array[n - 1]; array[n - 1] = tmp; //最大值与最后一个数据交换
}

int main()
{
    int array[10];
    int n = 10;

    printf("Please enter ten nums:");
    scan(array, 10);

    printf("The ten nums is : \n");
    print(array, n);

    printf("The chang ten nums is :\n");
    change(array, 10);
    print(array, n);

    return 0;
}

#endif

// CSDN
#if (0)

#include <stdio.h>

void input(int *arry, int len)
{
	for (int i = 0; i < len; i++) {
		scanf("%d", &arry[i]);
	}
}
void print(int *arry, int len)
{
	for (int i = 0; i < len; i++) {
		printf("%d ", arry[i]);
	}
	printf("\n");
}
void handle(int *arry, int len)
{
	int max_num = arry[0], min_num = arry[0];
	int *p_max = NULL, *p_min = NULL;
	for (int i = 1; i < len; i++) {
		if (min_num > arry[i]) {//逐个比对后找出最小值
			min_num = arry[i];
			p_min = &arry[i];	//逐个比对后找到最小值的空间地址
		}
		if (max_num < arry[i]) {//逐个比对后找出最大值
			max_num = arry[i];
			p_max = &arry[i];   //逐个比对后找到最大值的空间地址
		}
	}
	int tmp;
	tmp = *p_min; *p_min = arry[0]; arry[0] = tmp;  //最小值与第一个数据交换
	tmp = *p_max; *p_max = arry[len - 1]; arry[len - 1] = tmp;//最大值与最后一个数据交换
}
int main()
{
	int arry[10];
	printf("Please enter ten nums:");
	input(arry, 10);
	handle(arry, 10);
	print(arry, 10);
	//system("pause");
	return 0;
}

#endif
