
#include <stdio.h>

int main()

{
    int i;
    int f[20] = {1, 1};
    for (i = 2; i < 20; i++)
        f[i] = f[i - 2] + f[i - 1];
    for (i = 0; i < 20; i++)
    {
        if (i % 5 == 0)
            printf("\n");
        printf("%12d", f[i]);  //%12d : 输出12个长度的数，如果不够空格来补
    }
    printf("\n");
    return 0;
}