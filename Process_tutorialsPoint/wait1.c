#include<stdio.h>
int main()
{
    int pid;
    int status;
    pid = fork();

    if(pid == 0){
	system("ps -ef");
	sleep(10);
	system("ps -ef");
	return 4;
    }else{
	sleep(3);
	wait(&status);
	printf("In parent process: exi status for child is decimal %d, hexa %0x\n", status, status);
    }
    return 0;
}
