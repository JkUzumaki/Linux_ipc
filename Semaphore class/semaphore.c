#include<stdio.h>
#include<sys/sem.h>
#include<sys/ipc.h>
main(int argc,char **argv)
{
int id,semval;
id=semget(1,3,IPC_CREAT|0777);
if(id==-1)
{
perror("semget");
return;
}
if((semval=semctl(id,atoi(argv[1]),GETVAL))==-1)
{
perror("semctl");
return;
}
printf("\n%d\n",semval);
}
