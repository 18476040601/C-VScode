#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float x;
    //clrscr();       // clear screen 清除屏幕
    //textmode(0x00); // 6 lines per LCD screen
    x = -74.12;
    printf("|%f|=%f\n", x, fabs(x));
    x = 0;
    printf("|%f|=%f\n", x, fabs(x));
    x = 74.12;
    printf("|%f|=%f\n", x, fabs(x));
    getchar();
    return 0;
}