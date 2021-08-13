#include <stdio.h>
#include <unistd.h>

void main()
{
    FILE *fp ;
    if ((fp =fopen("wks.txt" , "w") ) == NULL)  
    // VScode 下只需要在该路径下编译就行，不用在程序中写出路径
    // 注意要用双"/" ,w表示可写，如果没有该文件，会自动建立。rb表示只读
    {
        printf ("Cannot open E:\\C-VSCode\\C程序\\10文件\\wks.txt file !!!\n") ;
        pause ();
    }
    else
    {
        printf ("open success !\n") ;
    }
                                                    
}