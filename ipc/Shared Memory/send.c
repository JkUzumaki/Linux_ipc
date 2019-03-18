//send.c
#include<stdio.h>
#include<sys/shm.h>
#include<sys/types.h>

main()
{
    int id;
    if( (id = shmget(2, 20, IPC_CREAT | 0777))==-1 ){
	perror("shmget");
	return;
    }
    char *ch;
    if((ch = shmat(id, (void*)NULL, 0))==-1)
	{
	perror("shmat");
	return;
	}
	while(1)
	{
	    puts("Enter the message\n");
	    gets(ch);
	}
}
