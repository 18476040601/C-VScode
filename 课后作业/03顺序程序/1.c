#include <stdio.h>
#include <math.h>

int main()
{
    float p, r = 0.07;
  
    for (int n=1; n<=10 ; n++)
    {
        p= pow((1+r),n);
        printf("%d年后增长的百分比为：%f\n", n , p);
    }
    return 0;
}