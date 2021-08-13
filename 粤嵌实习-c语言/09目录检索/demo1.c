#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // 打开目录
    DIR * fp = opendir("./");
    if (NULL == fp)
    {
        perror("open dir error");
        return -1 ;
    }

    while(1)
    {
        // 读取目录
        struct dirent * dir_info = readdir( fp );
        if (NULL == dir_info)
        {
            perror("read dir error");
            return -1 ;
        }

        // 打印文件名字
        if (strstr(dir_info->d_name , ".bmp"))
        {
            printf("文件名字为：%s\n" , dir_info->d_name );
        }
        
        
    }
    

    // 关闭目录   
    closedir(fp);

    return 0;
}
