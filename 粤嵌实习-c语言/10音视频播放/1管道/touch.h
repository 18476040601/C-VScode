#ifndef  __TOUCH_H__
#define  __TOUCH_H__


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>


int ts_get(int * a , int * b );


#endif