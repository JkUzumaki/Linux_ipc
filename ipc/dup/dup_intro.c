#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd;
    fd = open("test.txt", O_WRONLY|O_CREAT, 0777);
    if(fd == -1){
	perror("open");
	return 1;
    }
    close(1);
    dup(fd);
    system("ls");
    return 0;
}
