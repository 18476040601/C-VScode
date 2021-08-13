#include "rfid.h"

static struct timeval timeout;

 unsigned int ID=0;



void init_tty(int fd)
{    

	struct termios termios_new;

	bzero( &termios_new, sizeof(termios_new));

	cfmakeraw(&termios_new);


	cfsetispeed(&termios_new, B9600);
	cfsetospeed(&termios_new, B9600);

 
	termios_new.c_cflag |= CLOCAL | CREAD;

	
	termios_new.c_cflag &= ~CSIZE;
	termios_new.c_cflag |= CS8; 

	termios_new.c_cflag &= ~PARENB;

	termios_new.c_cflag &= ~CSTOPB;


	termios_new.c_cc[VTIME] = 0;
	termios_new.c_cc[VMIN] = 1;

	tcflush (fd, TCIFLUSH);


	if(tcsetattr(fd, TCSANOW, &termios_new))
		printf("Setting the serial1 failed!\n");

}

unsigned char CalBCC(unsigned char *buf, int n)
{
	int i;
	unsigned char bcc=0;
	for(i = 0; i < n; i++)
	{
		bcc ^= *(buf+i);
	}
	return (~bcc);
}

void beep(int buz, float microsec)
{
	ioctl(buz, 0, 1);	
	usleep(microsec * 1000*1000);
	ioctl(buz, 1, 1);
}


void * get_car_id(void * arg)
{
	#if(1)
	Init_Font();
	char buf1[128]={0};
	 Clean_Area(400,  
                0,  
                400, 
                120,
                0xffffff); 
	#endif
	void init_tty(int fd);
    unsigned char CalBCC(unsigned char *buf, int n);
    void beep(int buz, float microsec);
	
	int fd = open( DEV_PATH1, O_RDWR | O_NOCTTY);
	init_tty(fd);

	int buz = open("/dev/beep", O_RDWR);

	
	char *get_dev_info = calloc(1, 7);
	get_dev_info[0] = 0x07;	
	get_dev_info[1] = 0x02;	
	get_dev_info[2] = 'A';	
	get_dev_info[3] = 0x01;	
	get_dev_info[4] = 0x52;	
	get_dev_info[5] = CalBCC(get_dev_info, get_dev_info[0]-2); 
	get_dev_info[6] = 0x03; 

	char *pcd_config = calloc(1, 8);
	pcd_config[0] = 0x08;	
	pcd_config[1] = 0x02;	
	pcd_config[2] = 'B';	
	pcd_config[3] = 0x02;	
	pcd_config[4] = 0x93;	
	pcd_config[5] = 0x00;	
	pcd_config[6] = CalBCC(pcd_config, pcd_config[0]-2); 
	pcd_config[7] = 0x03;	

	int old=0, cardid=0;
	fprintf(stderr, "è¯·å°†RFIDå¡é è¿‘è?»å¡å™¨\n");

	char RBuf[128];
	while(1)
	{
		
		while(1)
		{
			
			
			tcflush (fd, TCIFLUSH);
			write(fd, get_dev_info, 7);

			usleep(10*1000);

			bzero(RBuf, 128);   
			read(fd, RBuf, 128); 

			
			if(RBuf[2] == 0x00)	 
			{
				break;
			}

			usleep(100*1000);
		}

		


		
		tcflush (fd, TCIFLUSH);
		write(fd, pcd_config, 8);  

		usleep(10*1000);

		bzero(RBuf, 128);
		read(fd, RBuf, 128);

		
		if(RBuf[2] == 0x00) 
		{
			int i, j;
			for(i=RBuf[3]-1, j=0; i>=0; i--, j++)
			{
				
				memcpy((char *)&cardid+j, &RBuf[4+i], 1);
			}
		}
		else
		{
			continue; 
		}
     
	 
		if(old != cardid &&cardid != 0)
		{
			printf("\r¿¨ºÅ: %#.8x\n", cardid);
            ID = cardid ;  
			
			beep(buz, 0.1); 
		}
		old = cardid==0 ? old : cardid;

		#if(1)
		if(cardid==0xf199931e||cardid==0x27e764a6)
		{
			  Clean_Area(400,0, 400, 120 ,0xfffff); 

		 sprintf(buf1,"¿¨_ºÅ%#.8x",cardid);                        
		Display_characterX( 420,          
							30,          
							buf1,   
							0x0000ff,     
							2
							);	
		}
	  
		#endif

	}
	UnInit_Font();
	close(fd);
	exit(0);
}
