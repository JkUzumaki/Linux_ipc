#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
main()
{
int fd;
fd = mkfifo("ff", 0777);
if( fd == -1)
   {
	perror("mkfifo");
   	//return;
   }
fd = open("ff", O_WRONLY);
write(fd, "Hello World!", 13);
printf("Process Completed!");
return;
}
