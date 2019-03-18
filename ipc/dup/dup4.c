#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

main()
{
    int fd;
    char str[80];
    fd = open("fifo1", O_RDONLY);
    read(fd, str, 80);
    puts(str);
    close(fd);
    return;
}
