#include "main.h"

int main(int argc, char const *argv[])
{
    char bmpName [50][64] ;
    char mp3Name [50][64] ; 

    // 检索指定目录中的BMP文件
            
    int num = find_dir( "./" , ".bmp" , bmpName);          
    printf("文件名列表如下：\n" );
    for (int i = 0; i < num ; i++)
    {
        printf("bnmpName[%d]:%s\n" , i , bmpName[i]);
    }
    

    // 检索指定目录中的MP3文件
    num = find_dir("./" , ".mp3" , mp3Name);
    printf("文件名列表如下：\n" );
    for (int i = 0; i < num ; i++)
    {
        printf("mp3Name[%d]:%s\n" , i , mp3Name[i]);
    }

    // 循环显示BMP图像文件
    while(1)
    {

    }

    // 资源回收

    return 0;
}
