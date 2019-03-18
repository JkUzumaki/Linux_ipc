#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd, fd1;
    char buff[100]="Hello Ari India";
    //Create 1st fifo
    fd = mkfifo("fifo1",0777);
    if(fd == -1){
	perror("mkfifo");
    }
    //Create 2nd fifo
    fd1 = mkfifo("fifo2", 0777);
    if(fd == -1){
	perror("mkfifo");
    } 
    // Open the fifo
    fd = open("fifo1", O_WRONLY);
    write(fd,"ls /home/jmariyappan/DUP/Assignment/A_002", 100);
   // write(fd,buff,100);

    return 0;
}
