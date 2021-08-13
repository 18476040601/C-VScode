/*
    一个数如果恰好等于它的因子之和,这个数就称为“完数”。
    例如,6的因子为1,2,3,而6=1+2+3,因此6是“完数”。
    编程序找出1000之内的所有完数,并按下面格式输出其因子:
        6 its factors are 1,2,3
    答案解析：
    因子：整数a除以整数b(b≠0) 的商正好是整数而没有余数，我们就说b是a的因子。
    整数n除以m，结果是无余数的整数，那么我们称m就是n的因子。 
    需要注意的是，唯有被除数，除数，商皆为整数，余数为零时，此关系才成立。因子是不包括自身的

    举一个例子：20 = 4 * 5，则4和5就是20的因子，也被称之为因子

*/

#include <stdio.h>

int main()
{
    int data, fator, sum; /* data表示要判断的数，fator表示因子，sum表示因子之和*/

    for (data = 2; data <= 1000; data++)
    {
        //1是所有整数的因子，所以因子之和从1开始
        sum = 1;
        for (fator = 2; fator <= data / 2; fator++)
        {
            /* 判断data能否被fator整除，能的话fator即为因子  因子不包括自身 */
            if (data % fator == 0)
            {
                sum += fator;
            }
        }
        // 判断此数是否等于因子之和 */
        if (sum == data)
        {
            printf("%d its factors are 1, ", data);
            for (fator = 2; fator <= data / 2; fator++)
            {
                if (data % fator == 0)
                {
                    printf("%d, ", fator);  //输出所有因子
                }
            }
            printf("\n");
        }
    }
    return 0;
}
