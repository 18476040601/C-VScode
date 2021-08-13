#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    
    system("mplayer -quiet -slave -input file=/tmp/my_fifo -geometry 0:300 -zoom -x 800 -y 180 Faded3.avi  &");

    printf("MUSIC PALY !!\n");



    return 0;
}
