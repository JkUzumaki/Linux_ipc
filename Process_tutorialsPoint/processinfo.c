#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int mypid, myppid;
    printf("Program to know PID and PPID information\n");
    mypid = getpid();
    myppid = getppid();
    printf("My process id %d\n",mypid);
    printf("My parent process id %d\n",myppid);
    printf("Cross verification of pid's by executing process commands on the shell\n");
    system("ps -ef");
    return 0;
}
