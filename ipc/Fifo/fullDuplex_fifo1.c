#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

main()
{
    int fd, fd1;
    char str[80], buf[80];
    if( mkfifo("fifo1", 0777) == -1 )
	perror("mkfifo");
    if( mkfifo("fifo2", 0777) == -1 )
	perror("mkfifo");
    
    fd = open("fifo1", O_WRONLY);
    fd1 = open("fifo2", O_RDONLY);

    if( fork() ){
	while(1){
		printf("Enter the message\n");
		gets(buf);
		write(fd, buf, strlen(buf)+1);
	}
    } else {
	while(1){
		printf("Waiting......\n");
		read(fd1, str, 80);
		puts(str);
	}	
    }

    return;
}
