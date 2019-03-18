#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

pthread_mutex_t lock;

  pthread_t tid1,tid2;
   int fd, fd1;
   char str[80], buf[80];
void *Worker()
{
	while(1){
		pthread_mutex_lock(&lock);
		printf("Enter the message\n");
		gets(buf);
		write(fd, buf, strlen(buf)+1);
		pthread_mutex_unlock(&lock);
	}
}

main()
{
    if( mkfifo("fifo1", 0777) == -1 )
	perror("mkfifo");
    if( mkfifo("fifo2", 0777) == -1 )
	perror("mkfifo");
    pthread_mutex_init(&lock, NULL);
    fd = open("fifo1", O_WRONLY);
    fd1 = open("fifo2", O_RDONLY);
    pthread_create(&tid1,NULL,Worker,NULL);
    pthread_exit(0);
    return;
}
