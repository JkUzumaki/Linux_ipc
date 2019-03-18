#include<stdio.h> 
#include<unistd.h>
#include<sys/sem.h>
#include<sys/ipc.h>
main()
{
    if( fork() ){
	if( fork() ){
	    if( fork() ){
		printf("Parent\n");
	    } else {
		printf("Child 3\n");
		int id,semval,i;
		struct sembuf v;
		id=semget(1,3,IPC_CREAT|0777);
		if(id==-1)
		{
		    perror("semget");
		    return;
		}
		v.sem_num=1;
		v.sem_op=0;
		v.sem_flg=0;
		for(i='A';i<='Z';i++)
		{
		    semop(id,&v,1);
		    printf("  %c\n",i);
		    fflush(stdout);
		    sleep(2);
		    semctl(id,1,SETVAL,1);
		    semctl(id,2,SETVAL,0);
		    semctl(id,0,SETVAL,1);
		}
		    }
		} else {
		    printf("Child 2\n");
		    int id, semval, i;
		    struct sembuf v;
		    id=semget(1,3,IPC_CREAT|0777);
		    if(id==-1)
		    {
			perror("semget");
			return;
		    }
		    v.sem_num=0;
		    v.sem_op=0;
		    v.sem_flg=0;
		    for(i=0;i<26;i++){
			semop(id,&v,1);
			printf("%d \n",i);
			fflush(stdout);
			sleep(2);
			semctl(id,0,SETVAL,1);
			semctl(id,1,SETVAL,0);
			semctl(id,2,SETVAL,1);
		    }
	    }
	}
    else{
        printf("Child 1\n");
        int id,semval,i;
        struct sembuf v;
        id=semget(1,3,IPC_CREAT|0777);
        if(id==-1)
        {
        perror("semget");
        return;
        }
        v.sem_num=2;
        v.sem_op=0;
        v.sem_flg=0;
        for(i='a';i<='z';i++){
		semop(id,&v,1);
		printf("%c \n",i);
		sleep(2);
		semctl(id,1,SETVAL,1);
		semctl(id,2,SETVAL,1);
		semctl(id,0,SETVAL,0);
        }
    }
    return;
}
