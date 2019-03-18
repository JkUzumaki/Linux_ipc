#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

pthread_mutex_t lock;

  pthread_t tid1,tid2;
   int fd, fd1;
   char str[80], buf[80];
void Worker()
{
	while(1){
	//	pthread_mutex_lock(&lock);
		printf("Enter the message\n");
		gets(buf);
		printf("Thread is id %i\n",pthread_self());
		write(fd, buf, strlen(buf)+1);
	//	pthread_mutex_unlock(&lock);
	}
}

void Worker1()
{
	while(1){
		printf("Message is: ");
		fflush(stdout);
		read(fd1, str, sizeof(str));
		//intf("Thread is id %i\n",pthread_self());
		puts(str);
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
	if(fd==-1)
	{
	perror("open");return;	
	}
    fd1 = open("fifo2", O_RDONLY);
	if(fd1==-1)
	{
	perror("open");return;	
	}
    pthread_create(&tid1,NULL,Worker,NULL);
    //pthread_join(tid1, NULL); 
    pthread_create(&tid2,NULL,Worker1,NULL);
    //pthread_join(tid2, NULL);
    pthread_exit(0);
    return;
}
