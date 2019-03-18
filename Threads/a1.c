#include<stdio.h>
#include<pthread.h>

pthread_t tid;

int main()
{
	int fd, fd1;
	if( mkfifo("f1", 0777) == -1){
		perror("f1");
		return -1;
	}
	if( mkfifo("f2", 0777) == -1){
		perror("f2")
		return -1;
	}
	// Opening the file in necessary mode
	fd = open("f1", O_WRONLY);
	fd1 = open("f2", O_RDONLY);
	
}
