#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/ipc.h>
main()
{
	if( fork() ){
		if( fork() ){
			//Process1
			int id,semval,i,flg;
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
			for(i=0;i<26;i++)
			{
				if(flg == 3){
					printf("\n");
					flg = 0;
				}
				semop(id,&v,1);
				printf("%d ",i);
				if(flg < 3){
					flg++;		
				}
				fflush(stdout);
				sleep(2);
				semctl(id,0,SETVAL,1);
				semctl(id,1,SETVAL,0);
				semctl(id,2,SETVAL,1);
			}	
		} else{			
			//Process2
				int id,semval,i,flg;
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
				for(i='A';i<='Z';i++){
						if(flg == 3){
							printf("\n");
							flg = 0;
						}
						semop(id,&v,1);
						printf("  %c ",i);
						if(flg < 3){
							flg++;
						}
						fflush(stdout);
						sleep(2);
						semctl(id,1,SETVAL,1);
						semctl(id,2,SETVAL,0);
						semctl(id,0,SETVAL,1);

			    }	
			}
	}else{
		//Process3
	    int id,semval,i, flg;
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
		//smallcase
		for(i='a';i<='z';i++){
				if(flg == 3){
					printf("\n");
					flg = 0;
				}
				semop(id,&v,1);
				printf("%c ",i);
				if(flg < 3){
					flg++;
				}
				sleep(2);
				semctl(id,1,SETVAL,1);
				semctl(id,2,SETVAL,1);
				semctl(id,0,SETVAL,0);
				
		}	
	}
}
