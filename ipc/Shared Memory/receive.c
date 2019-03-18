//receive.c
#include<stdio.h>
#include<sys/shm.h>
#include<sys/types.h>
main()
{
    int id;
    char* ptr=NULL;
    if( (id = shmget(2, 20, IPC_CREAT|0777) ) == -1 ){
	perror("shmget");
	return;
    }
    ptr = shmat(id, 0, SHM_RDONLY);
	while(1)
	{
    puts("wait...............\n");
    puts(ptr);
	//sleep(5);
}
    shmdt(ptr);
}
