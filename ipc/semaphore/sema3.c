#include<stdio.h>
#include<sys/sem.h>
#include<sys/ipc.h>

int main(int argc, char ** argv)
{
    int flg, id, semval;
    struct sembuf v;
    id = semget(1, 3, IPC_CREAT|0777);
    if(id == -1){
	perror("semget");
	return 1;
    }
    v.sem_num = 0;
    v.sem_op = 1;
    v.sem_flg = 0;
    flg = semop(id, &v, 1);
    printf("ARI MAS\n");
   /* v.sem_num = 0;
    v.sem_op = 0;
    v.sem_flg = 0;
    */printf("AR HYD\n");
    return 0;
}
