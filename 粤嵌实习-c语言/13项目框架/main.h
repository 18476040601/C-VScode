#ifndef     __MAIN_H__
#define     __MAIN_H__

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "bmp_display.h"

// 声明一个结构体用来存放卡号以及其对应的余额
typedef struct car_info
{
    unsigned int car_id ;
    int money ;
}INFO ;



#endif

