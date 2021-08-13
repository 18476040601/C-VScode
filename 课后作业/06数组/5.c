/*
题目：
    将一个数组中的值按逆序重新存放。例如：原来顺序为8,6,5,4,1。要求改为1,4,5,6,8。
【答案解析】
    该题为数组的逆置，具体处理方式如下：
    如果begin < end时，则循环进行一下操作
    1.给定两个下标begin和end，begin放在数组起始的位置，end放在数组最后一个元素的位置
    2.交换begin和end位置的元素
    3.begin往后移动，end往前移动
*/
#if (0)
#include <stdio.h>

int main()

{
    int array[5] = {8, 6, 5, 3, 1};
    int i;

    printf("逆序之前数组为：");
    for (int i = 0; i < 5; ++i)
        printf("%-3d", array[i]);   //-3表示从最左边开始，给每位输出的值3个字符。+3表示从右边开始
    printf("\n");

    printf("逆序之后数组为:");
    for (i = 4; i >= 0; i--)
    {
        printf("%-3d", array[i]);
    }
    printf("\n");

    return 0;
}

#endif

#if (1)
#include <stdio.h>
int main()
{
    int array[5] = {8, 6, 5, 4, 1};
    int begin = 0, end = 4;

    printf("逆序之前数组为：");
    for (int i = 0; i < 5; ++i)
        printf("%-3d", array[i]);
    printf("\n");

    // 逆序：begin在数组最左侧，end在数组最右侧
    // 只要begin < end，将begin和end位置元素进行交换
    // 然后begin往后移动一步，end往前移动一步
    while (begin < end)
    {
        int temp = array[begin];
        array[begin] = array[end];
        array[end] = temp;
        begin++;
        end--;
    }

    printf("逆置之后数组为：");
    for (int i = 0; i < 5; ++i)
        printf("%-3d", array[i]);
    printf("\n");
    return 0;
}

#endif
