#ifndef __FIFO_H__
#define __FIFO_H__


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



#define     FIFO_PATH       "/tmp/my_fifo"


int cmd_send(char *cmd);


#endif