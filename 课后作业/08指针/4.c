/*
题目：
    有n个整数,使前面各数顺序向后移m个位置,最后m个数变成最前面m个数,见图8.43。
    写一函数实现以上功能,在主函数中输人n个整数和输出调整后的n个数。
解题思路： 
    找出倒数第m个数据，从这里开始保存倒数第m位置的数据，因为倒数第m位置的数据要放到数组最前方，
    将m之前的数据向后偏移一位，然后将数组第一个位置的数据替换为保存的m位的数据，逐个往后递增即可。
*/

#include <stdio.h>
#include <stdlib.h>

void move(int *arry, int n, int m)
{
    int end_idx = n - m; //找到倒数第m个数据的位置，也就是要移动到数组首部的数据的起始位置

    for (int i = 0; i < m; i++)
    {
        int *p = arry + end_idx + i; //从倒数第m个数据的位置开始逐渐向后偏移直到数组尾部
        int tmp = *p; //获取到这个位置的值，用于数组前边数据向后偏移1位之后，向数组第i位赋值

        for (int j = end_idx + i; j > i; j--)
        { //从第i位开始逐个向后偏移一位
            *p = *(p - 1);  // 把前1位的值赋给后1位，相当于后移1位
            p--;
        }
        *(arry + i) = tmp; //数组的前第i个数字逐个替换为后边被覆盖的值
    }
}

int main()
{
    int number[32], n, m, i;

    printf("Please enter the number of numbers: ");
    scanf("%d", &n); //先确定要输入多少个数字

    printf("Please enter %d numbers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &number[i]); //输入指定个数的数字
    }

    printf("Number of positions to move: ");
    scanf("%d", &m); //确定要向后移动多少个位置

    move(number, n, m);

    printf("The array that moves %d positions is : \n", m);
    for (i = 0; i < n; i++)
    {
        printf("%-4d ", number[i]);
    }
    printf("\n");

    return 0;
}
