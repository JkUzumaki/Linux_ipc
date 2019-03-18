#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
    int fd;
    fd = mkfifo("fifo1", 0777);
    if( fd == -1){
	perror("mkfifo");
//	return;
    }
    fd = open("fifo1", O_WRONLY);
    write(fd, "Hello", 5);
	printf("Process completed!\n");
	return;
}
