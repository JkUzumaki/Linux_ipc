#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int mypid, myppid;
	printf("Program to know PID and PPID's information\n");
	mypid = getpid();
	myppid = getppid();
	printf("My process Id : %d\n", mypid);
	printf("My parent process Id : %d\n", myppid);
	printf("Cross verification of pid by executing process command on shell\n");
	//'ps -ef' command is listing all the executing files with their pid and ppid
	system("ps -ef");
	return 0;
}
