#include "bmp_display.h"

void * bmp_display(void *arg)
{
    #if(0)
    char fileame [10][128] ; 
    char name[128];
    int num = 0 ;
    
    DIR * fp = opendir("./");
    if (NULL == fp)
    {
        fprintf(stderr , "open dir %s error ： %s \n" ,   "./" , strerror(errno));
    }
    
    while(1)
    {
        struct dirent * dir_info = readdir( fp );

        if (NULL == dir_info)
        {
            perror("read dir error");
            break ;
        }
        char * ptr =  strrchr(dir_info->d_name , '.' ); 
        if ( ptr == NULL )
        {
            continue ;
        }  
        if ( !strncmp(ptr , ".avi" , 4  )   ) 
        {
           
            printf("文件名字为：%s\n" , dir_info->d_name );

            sprintf( fileame[num] , "%s", dir_info->d_name );
           
            num ++ ;
            if (num >= 82 )
            {
                printf("以及达到存储上限！！！\n");
                break ;
            }
            
        }
        
    }
    #endif

    //   sprintf(name,"mplayer -quiet -geometry 0:0 -zoom -x 800 -y 480  %s &",fileame[0]);
         system("mplayer -quiet -geometry 0:200 -zoom -x 800 -y 280 video_2.avi &");
   
   
       
   // closedir(fp);

  //  return 0;
}
