#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd, fd1, fd2, fd3;
    char ch[100];
    fd = open("fifo1", O_RDONLY);
    read(fd, ch, 100);
    system(ch);
    //printf("%s",ch);
    //close(1);	//Closing the std o/p
    //fd1 = dup(fd);
}
