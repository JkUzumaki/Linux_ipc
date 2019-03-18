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
printf("Enter the set val");
scanf(" %d",&semval);
if((semctl(id,atoi(argv[1]),SETVAL,semval))==-1)
{
perror("semctl");
return;
}
}
