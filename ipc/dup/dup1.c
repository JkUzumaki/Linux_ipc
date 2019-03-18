#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int fd, fd1, fd2, fd3, size =0, i = 0;
    // fd
    fd = open("test.c", O_RDONLY);
    if( fd == -1){
	perror("open");
	return 1;
    }
    size = lseek(fd, 0, 2);
    lseek(fd, 0, 0);
    close(0);// close the std input
    
    fd1 = dup(fd);
    
    fd2 = open("b.c", O_WRONLY | O_CREAT, 0777);
    if( fd2 == -1){
	perror("open");
	return 1;
    }
    close(1);
    
    fd3 = dup(fd2);
    
    char ch;

    while(i < size){
	scanf("%c", &ch);
	printf("%c", ch);
	fflush(stdout);
	i++;
    }
    close(fd);
    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}
