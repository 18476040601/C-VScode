/*---------------------------------------
*功能描述:  实现LED的测试
*创建者：   粤嵌技术部
*创建时间： 2015,01,01
---------------------------------------
*修改日志：
*修改内容：
*修改人：
*修改时间：
----------------------------------------*/

/*************************************************
*头文件
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
  
#define TEST_MAGIC 'x'                           //定义幻数
#define TEST_MAX_NR 2                            //定义命令的最大序数

//定义LED的魔幻数
#define LED1 _IO(TEST_MAGIC, 0)              
#define LED2 _IO(TEST_MAGIC, 1)
#define LED3 _IO(TEST_MAGIC, 2)
#define LED4 _IO(TEST_MAGIC, 3)

/*************************************************
*主函数-实现led的控制
*************************************************/
int main(int argc, char **argv)
{
	int fd;
	fd = open("/dev/Led",O_RDWR);                //打开设备下的LED，成功返回0
	if(fd < 0)
	{
		perror("Can not open /dev/LED\n");
		return 0;
	}
	
	while(1)
	{
		ioctl(fd, LED1, 0);  //2ON
		ioctl(fd, LED2, 0);  //2ON
		ioctl(fd, LED3, 0);  //2ON
		ioctl(fd, LED4, 0);  //2ON

		sleep(1);
		ioctl(fd, LED1, 1);  //2OFF
		ioctl(fd, LED2, 1);  //2OFF
		ioctl(fd, LED3, 1);  //2OFF
		ioctl(fd, LED4, 1);  //2OFF

		sleep(1);
	}

	close(fd);
	return 0;
}
