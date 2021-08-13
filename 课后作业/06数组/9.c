/*
题目：
    有15个数按由大到小顺序存放在一个数组中，输入一个数，要求用折半查找法找出该数是数组中第几个元素的值。
    如果该数不在数组中，则输出"无此数"。
【答案解析】
    二分查找是一个非常高效简单的查找算法，笔试和面试中非常喜欢考察。
    折半查找又叫二分查找，查找的前提是序列中元素必须有序，假设区间使用[left, right)标记，
    待查找元素为key，具体查找的方式如下：当区间[left, right)有效时循环进行一下操作
        1. 找到[left， right)区间中间位置
        2. 如果key等于中间位置元素，则找到，返回该元素在数组中的下标
        3. 如果key小于中间位置元素，到数组的左半侧继续二分查找
        4. 如果key大于中间位置元素，到数组的右半侧继续二分查找
    如果循环结束时还没有找到，则不存在该元素。
*/

//wks
#if (0)

#include <stdio.h>

int main()

{
    int array[15] = {90, 87, 78, 65, 63, 54, 45, 34, 32, 29, 11, 9, 8, 7, 6};
    int i, num, k = 1;

    printf("该数组为：");
    for (i = 0; i < 15; i++)
    {
        printf("%-4d", array[i]);
    }
    printf("\n");

    printf("请输入要查找的正整数数字： ");
    scanf("%d", &num);

    for (i = 0; i < 15; i++)
    {
        if (array[i] == num)
        {
            k = 0;
            break;
        }
    }

    if (k == 0)
        printf("该数是数组中的下标为：%d\n", i);
    else
        printf("该数组中无此数\n");

    return 0;
}

#endif

#if (1)

#include <stdio.h>
int main()
{
    int array[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int left = 0;
    int right = sizeof(array) / sizeof(array[0]); //计算数组长度
    int key = 0;

    printf("请输入要查找的数字: ");
    scanf("%d", &key);

    // 二分查找
    while (left < right)
    {

        /*
        (left+right)>>1含义
        右移运算符>>,运算结果正好能对应一个整数的二分之一值，
        这就正好能代替数学上的除2运算，但是比除2运算要快。
        mid=(left+right)>>1相当于mid=(left+right)/2
    */
        // 找到中间位置
        int mid = left + ((right - left) >> 1); // (left+right)>>1 = (left+right)/2
        if (key == array[mid])
        {
            printf("%d\n", mid);
            break;
        }
        else if (key < array[mid])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (left >= right)
        printf("无此数\n");
    return 0;
}

#endif