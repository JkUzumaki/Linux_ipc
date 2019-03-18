#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

main()
{
    int fd, fd1;
    char str[80], buf[80];
    fd = open("fifo1", O_RDONLY);
    fd1 = open("fifo2", O_WRONLY);
    if( fork() ){
	while(1){
	    printf("Waiting................\n");
	    read(fd, str, 80);
	    puts(str);
	}
    } else {
	while(1){
		printf("Enter the message\n");
		gets(buf);
		write(fd1, buf, strlen(buf)+1);
	}
    }
    return;
}
