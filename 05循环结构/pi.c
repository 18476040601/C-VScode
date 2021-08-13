/*
    用π/4~=1-1/3+1/5-1/7+1/9-.....,公式求π的近似值，直到某一项的绝对值小于为止。
    提示：1.要确定计算的精度......  ，可以配合while语句用fabs()函数来确定精度来退出
          2.据观察，分子不变，分母却每次递增2，且正负切换。
           3.记得结果乘以4。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float s = 1;
    float pi = 0;
    float i = 1.0;
    float n = 1.0;
    while (fabs(i) >= 1e-7)
    {
        pi += i;    //pi = pi+i
        n += 2 ;    //n = n + 2;
        // 这里设计的很巧妙，每次正负号都不一样
        s = -s;
        i = s / n;
    }
    pi = 4 * pi;
    printf("pi的值为：%.7f\n", pi);  //pi为圆周率

    return 0;
}