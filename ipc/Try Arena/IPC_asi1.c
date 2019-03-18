#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

main()
{
int fd, fd1, count;
char str[20];
//Creating fifo
fd = mkfifo("fifoN",0777);
//Checking fifo has been created as it return 0 for success and -1 for failure
if(fd == -1)
    {
	perror("mkfifo");
	return;
    }
//Opening the fifo in write mode
fd = open("fifoN", O_WRONLY);
//Write "This is IPC" into the fifo
write(fd, "This is IPC", 20);

//Opening a fifo in read mode
fd1 = open("fifoM", O_RDONLY);
//Read the data from the fifo and store in str
read(fd1, str,20);
//Print str
puts(str);
close(fd1);

printf("Process completed\n");
return;
}
