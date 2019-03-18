#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid, mypid, myppid;
	pid = getpid();
	printf("Before fork: Process id %d\n", pid);
	pid = fork();
	
	if(pid < 0){
		perror("fork() failure\n");
		return 1;
	}
	//Child process
	if(pid == 0){
		printf("--------------------CHILD--------------------\n");
		printf("This is child process\n");
		mypid = getpid();
		myppid = getppid();
		printf("Process id is %d and parent process id %d\n", mypid, myppid);
	}else{
		printf("----------------------PARENT------------------\n");
		sleep(2);
		printf("This is parent process\n");
		mypid = getpid();
		myppid = getppid();
		printf("Process id is %d and parent process id %d\n", mypid, myppid);
		printf("Newly created pid or child pid %d\n", pid);
	}
	return 0;
}
