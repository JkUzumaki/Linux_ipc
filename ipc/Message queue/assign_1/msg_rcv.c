//msg_rcv
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
	    printf("Waiting..........................\n");
	    v.mtype = 1;
	    if( msgrcv(id, &v, 20, v.mtype, 0) == -1){
		perror("msgrcv");
		return;
	    }
	    puts(v.mtext);
	}
}
