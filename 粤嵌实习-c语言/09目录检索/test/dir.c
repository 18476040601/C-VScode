#include "dir.h"


int find_dir( const char * FilePath , const char * FileType , char fileName[][64] )
{
    int num = 0 ;

    // 打开目录
    DIR * fp = opendir( FilePath );
    if (NULL == fp)
    {
        // perror("open dir error");
        fprintf(stderr , "open dir %s error ： %s \n" , FilePath , strerror(errno));
        return -1 ;
    }
           
    while(1)
    {
        // 读取目录
        struct dirent * dir_info = readdir( fp );
        if (NULL == dir_info)
        {
            perror("read dir error");
            break ;
        }
                      
        // 打印文件名字
        char * ptr =  strrchr(dir_info->d_name , '.' ); // 从右往左找. 如果找到则返回.所在的地址
        if ( ptr == NULL )
        {
            continue ;
        }
        
           
        if ( !strncmp(ptr , FileType , 4  )   ) // 逻辑判断非零则真
        {
           
            printf("文件名字为：%s\n" , dir_info->d_name );
            // fileName = dir_info->d_name ; //错误， 数组名不允许直接复制
            sprintf( fileName[num] , "%s%s" , FilePath , dir_info->d_name );
           
            num ++ ;
            if (num >= 50 )
            {
                printf("以及达到存储上限！！！\n");
                break ;
            }
            
        }
        
    }
    
           
    // 关闭目录   
    closedir(fp);

    return num;
}