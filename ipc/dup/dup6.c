#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

main()
{
int fd;
char str[50];
fd = open("ff",O_RDONLY);
read(fd, str,50);
puts(str);
close(str);
return;
}
