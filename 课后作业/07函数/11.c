/*
题目 ：写一个函数,用“起泡法”对输人的10个字符按由小到大顺序排列。
题目解析:
    该题主要是对冒泡排序的理解，外层循环控制排序的趟数，内层循环主要是进行每一趟排序的比较，
    如果前面的字符大于后面的字符，就进行交换，每做一趟排序，就把一个最大字符排在最后，
    以及每做一趟排序就需要少比较一个字符。
*/

#include <stdio.h>
#include <string.h>

void BubbleSort(char array[]) // 冒泡排序
{
    int i, j;
    char temp;
    int len = strlen(array);

    // 进行(len -1)次循环，实现(len - 1)趟比较。第一个数只要比较n-1次。 
    for (j = 0; j < len -1; j++) 

        for (i = 0; i < len - i - 1 ; i++) //在每一趟中进行len-1-j次比较

        {
            if (array[i] > array[i + 1]) //相邻两个进行比较
            {
                //互换
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
}

int main()

{
    char array[10] = {0};
    int i;

    printf("please input 10 integer : \n");
    for (i = 0; i < 10; i++)
    {
        scanf("%c", &array[i]);
    }

    BubbleSort(array);
    printf("The sorted numbers is : \n");
    //for (i = 0; i < 10; i++)
    //{
    printf("%s\n", array);
    //}
    printf("\n");

    return 0;
}