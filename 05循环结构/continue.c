//把100~200之间不能被3整除的数输出

#include <stdio.h>

int main()
{
    int n;
    for (n = 100; n <= 200; n++)
    {
        if (n % 3 == 0) //结束条件,当n能把3整除时，执行continue语句，结束本次循环
                        //即跳过printf函数语句，只有不满足才能执行printf语句
            continue;   //结束不输出满足条件的n，for语句继续执行
//          break;      //如果为break，运行到符合n%3==0的时候就会结束整个for语句
        printf("%d\t", n);
        }
    printf("\n");
    return 0;
}