//msg_snd
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgBuf
{
    long int mtype;
    char mtext[20];
};

main()
{
    struct msgBuf v;
    int id;
    id = msgget(1, IPC_CREAT|0777);
    if(id == -1){
	perror("msgget");
	return;	
    }
	while(1){
	    printf("Enter the data\n");
	    gets(v.mtext);
	    v.mtype = 1;
	    if( msgsnd( id, &v, strlen(v.mtext)+1, 0) == -1 ){
		perror("msgsnd");
		return;	
	    } 
	}
}
