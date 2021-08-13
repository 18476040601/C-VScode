/*
    口袋中有红黄蓝白黑5种颜色的球若干个。每次从口袋中先后取出3个球，
    问得到3种不同颜色的球可能取法，输出每种排列的情况
*/

#include <stdio.h>

enum Color
{
    red,
    yellow,
    blue,
    white,
    black
};
enum Color i, j, k, pri;

int main()
{
    int n, loop;
    n = 0;

    for (i = red; i <= black; i++)
    {
        for (j = red; j <= black; j++)
            if (i != j) // 如果第一球和第二球不同色
            {
                for (k = red; k <= black; k++)
                    if (i != k && j != k) // 如果3球不同色
                    {
                        n += 1;  // 符合3球不同色的话，次数加1
                        printf("The No.%d arrange :\n", n);
                        for (loop = 1; loop <= 3; loop++) // 先后对3个球进行处理
                        {
                            switch (loop)
                            {
                            case 1: // loop为1时，把第1球的颜色赋给pri
                                pri = i;
                                break;
                            case 2: // loop为2时，把第2球的颜色赋给pri
                                pri = j;
                                break;
                            case 3: // loop为3时，把第3球的颜色赋给pri
                                pri = k;
                                break;
                            default:
                                break;
                            }
                            switch (pri)
                            {
                            case red:                   // pri的值等于枚举常量red时，输出"red"
                                printf("%-10s", "red"); // 输出字符串red
                                break;
                            case yellow:
                                printf("%-10s", "yellow");
                                break;
                            case blue:
                                printf("%-10s", "blue");
                                break;
                            case white:
                                printf("%-10s", "white");
                                break;
                            case black:
                                printf("%-10s", "balck");
                                break;
                            default:
                                break;
                            }
                        }
                        printf("\n\n");
                    }
            }
        printf("There are %d permutations.\n", n); // 共有多少种排列
    }

    return 0;
}
