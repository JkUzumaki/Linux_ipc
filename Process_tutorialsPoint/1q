#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int id = 0;
    id = fork();
    if(id == 0){
	sleep(3);
 	printf("Child process\nPID %d\nPPID %d\n",getpid(), getppid());
    }else if(id > 0){
 	printf("Parent process\nPID %d\nPPID %d\n",getpid(), getppid());
    }else{
	printf("No process is created\n");
    }
    return 0;
}
