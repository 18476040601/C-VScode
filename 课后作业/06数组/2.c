/*
题目：
    用选择法对10个整数排序
【答案解析】
    选择排序原理：
    总共两个循环，外循环控制选择的趟数，内循环控制具体选择的方式。
    用maxPos标记区间中 首元素位置，然后用后序元素依次与maxPos标记的元素进行比较，
    如果有元素大于maxPos位置的元素，用maxPos标记该元素的位置，直到区间的末尾。
    该趟选择完成后，即找到该区间中最大元素，如果maxPos标记的最大元素不在区间末尾，
    用maxPos位置元素与区间末尾的元素进行交换。
    继续新一趟选择，直到区间中剩余一个元素
*/

#if (0)

#include <stdio.h>

int main()

{
    int i, j, array[10];
    int size = sizeof(array) / sizeof(array[0]);
    printf("请输入10个正整数：\n");
    for (i = 0; i < 10; i++)
    {
        printf("array[%d]=", i);
        scanf("%d", &array[i]);
    }
    printf("\n");

    // 选择排序过程：
    // 外循环控制选择的趟数，总共选择size-1趟，
    // 减1是因为最后一趟选择区间中剩余一个元素，该趟选择可以忽略
    for (int i = 0; i < size - 1; ++i)
    {
        // 用maxPos标记[0, size-i)区间中最大元素
        // 在该趟选择没有开始前，默认认为0号位置就是最大元素
        int maxPos = 0;
        for (int j = 1; j < size - i; ++j)
        {
            // 遍历区间[0, size-i)中元素，如果有元素比maxPos位置元素大，maxPos记录该元素位置
            if (array[j] > array[maxPos])
                maxPos = j;
        }

        // 如果最大元素不在区间末尾时，将最大元素与区间末尾元素交换
        if (maxPos != size - i - 1)
        {
            int temp = array[maxPos];
            array[maxPos] = array[size - i - 1];
            array[size - i - 1] = temp;
        }
    }

    // 输出原数组
    printf("选择排序后数组中数据为：");
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}

#endif

/*
优化：
    既然一趟选择能找到最大的元素，那么也可以找到最小的元素，
    因此在一趟中可以找到最小和最大两个元素，最小元素放在区间左侧，最大元素放在区间右侧，可以减少选择的趟数。
*/

#if (1)

#include <stdio.h>
int main()
{
    int i, j, array[10];

    //sizeof表示计算数组的字节数。如果数组a中有10个整数，那么sizeof(a)通常为40(假定每个整数占4个字节)
    //还可以用sizeof来计算数组元素(如a[0])的大小。
    //用数组的大小除以数组元素的大小可以得到数组的长度。例如：sizeof(a) / sizeof(a[0]);
    int size = sizeof(array) / sizeof(array[0]);  //计算数组的长度
    printf("请输入10个正整数：\n");
    for (i = 0; i < 10; i++)
    {
        printf("array[%d]=", i);
        scanf("%d", &array[i]);
    }
    printf("\n");

    int begin = 0, end = size - 1;
    
    // [begin, end]区间中进行选择
    while (begin < end)
    {
        int maxPos = begin; // 标记区间中最大元素的位置
        int minPos = begin; // 标记区间中最小元素的位置
        int index = begin + 1;
        while (index <= end)
        {
            if (array[index] > array[maxPos])
                maxPos = index;

            if (array[index] < array[minPos])
                minPos = index;
            ++index;
        }

        // 如果最大元素不在区间末尾，则交换
        if (maxPos != end)
        {
            int temp = array[maxPos];
            array[maxPos] = array[end];
            array[end] = temp;
        }

        // 如果在交换前区间末尾刚好存储的是最小的元素，则最小的元素被交换到maxPos位置
        // 此时需要更新minPos
        if (minPos == end)
            minPos = maxPos;

        // 如果最小元素不在区间起始位置，则交换
        if (minPos != begin)
        {
            int temp = array[minPos];
            array[minPos] = array[begin];
            array[begin] = temp;
        }

        // 最大与最小元素已经在区间的起始和末尾的位置，
        // 因此begin往后移动，end往前移动
        begin++;
        end--;
    }

    // 输出原数组
    printf("选择排序后数组中数据为：");
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}

#endif