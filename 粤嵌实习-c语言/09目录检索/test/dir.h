#ifndef     __DIR_H__
#define     __DIR_H__

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

/*
*   函数名：    find_dir
*   功  能：    在指定路径中查找指定文件的类型， 并存入到指定的内存中
*   参  数：    @FilePath 需要查找的路径+名字
*               @FileType 需要查找的文件的后缀名
*               @fileName 找都之后存放到的地址（二维数组）
*   返  回：     成功则返回实际寻找的文件数
*               失败 返回 -1 
*   日  期：
*   作  者：
*   联  系：
*/
int find_dir( const char * FilePath , const char * FileType , char fileName[][64] );



#endif