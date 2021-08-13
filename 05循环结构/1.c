#include <stdio.h>
int main()
    {
        int n=0;
        printf("input a string:\n");
        while(getchar()!='\n') n++;      //计算字符长度
        printf("%d\n",n);
    }