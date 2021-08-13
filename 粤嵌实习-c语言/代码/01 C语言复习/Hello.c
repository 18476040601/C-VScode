#include <stdio.h>

int main(int argc, char const *argv[])
{

    // \n 换行符  表示一行的结束 --> 让标准输出缓冲区刷新
    printf("Hello Even\n") ;

    // 使用系统预定义的宏来定位程序运行的位置
    printf("%s__%s__%d\n" , __FILE__ , __FUNCTION__  , __LINE__ );

    while(1) ;


    return 0;
}
