#ifndef __RFID_H__
#define __RFID_H__

#include <stdio.h>
#include <assert.h>
#include <fcntl.h> 
#include <unistd.h>
#include <termios.h> 
#include <sys/types.h>
#include <sys/select.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include "font.h"
#include "time.h"


#define DEV_PATH1   "/dev/ttySAC1"   // 串口1 
#define DEV_PATH2   "/dev/ttySAC2"   // 串口2

void init_tty(int fd);
unsigned char CalBCC(unsigned char *buf, int n);
void beep(int buz, float microsec);
void * get_car_id(void * arg);

#endif