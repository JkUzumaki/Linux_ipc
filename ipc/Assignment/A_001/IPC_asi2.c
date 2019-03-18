#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

main()
{
int fd, fd1, count =0;
char str[20];
//This fifo is present as it is created previously
fd = open("fifoN", O_RDONLY);
//Reads the data in fifo and store it in str
read(fd, str, 20);
// Counting the number of character present in the str
while(str[count] != '\0'){
    count++;
}
close(fd);
//printf("The number of char %d\n", count);


//To add a string to a character str
sprintf(str, "num of char %d",count);
//printf("%s\n",str);
//Open in wrote mode
fd1 = open("fifoM", O_WRONLY);
//
write(fd1, str, 20);

return;
}  
