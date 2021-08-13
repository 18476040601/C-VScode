
/*3、有一个已排好序的数组int a[11]={-5,-3,0,6,8,12,16,28,66,88};，
要求输入一个数后，按原来排序的规律将它插入数组中。
插入的数值为：10；
输出结果 a[11]= {-5,-3,0,6,8,10,12,16,28,66,88}
*/
#include <stdio.h>
int main()
{
    int a[11] = {-5, -3, 0, 6, 8, 12, 16, 28, 66, 88};
    int i, num, k;
    printf("请输入要插入的数：");
    scanf("%d", &num);
    for (i = 0; i < 10; i++)
        if (num < a[i])
            break;
    k = i;
    for (i = 10; i > k; i--)
        a[i] = a[i - 1];
    a[k] = num;
    printf("新的数组为：");
    for (i = 0; i < 11; i++)
        printf("%d\t", a[i]);
        printf ("\n") ;
    return 0;
}