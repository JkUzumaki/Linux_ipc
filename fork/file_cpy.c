#include<stdio.h>
#include<unistd.h>
#include<sys/fcntl.h>
//#include<sys/types.h>
int main()
{
    int fd, fd1;
    fd = open("fork.c",O_RDONLY);
    fd1 = open("b.c",O_WRONLY|O_CREAT, 0777);
    char ch;
    while(read(fd, &ch, 1))
    {
	write(fd1, &ch, 1);	
    }
    close(fd);
    close(fd1);
    return 0;
}
