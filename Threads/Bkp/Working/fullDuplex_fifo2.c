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
		printf("Receive:\n");
		fflush(stdout);
		read(fd, buf, sizeof(buf));
		puts(buf);
		pthread_mutex_unlock(&lock);
	//
		printf("Send:\n");
		gets(str);
		write(fd1, str, strlen(str)+1); 
	}
}
	
main()
{
    if( mkfifo("fifo1", 0777) == -1 )
	perror("mkfifo");
    if( mkfifo("fifo2", 0777) == -1 )
	perror("mkfifo");
    pthread_mutex_init(&lock, NULL);
    fd = open("fifo1", O_RDONLY);
    fd1 = open("fifo2", O_WRONLY);
    pthread_create(&tid1,NULL,Worker,NULL);
    pthread_join(tid1, NULL);
    //pthread_create(&tid2,NULL,Worker1,NULL);
    //pthread_join(tid2, NULL);
    pthread_exit(0);
    return;
}
