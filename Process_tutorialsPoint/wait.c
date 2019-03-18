#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
 int pid;
 int pids[3];
 int status;
 int numprocesses = 0;
 int tot_proc = 3;
 while( numprocesses < tot_proc){
  pid = fork();
  if(pid == 0){
   printf("In child process: pid %d\n", getpid());
   sleep(5);
   return 4;
  } else{
   pids[numprocesses] = pid;
   numprocesses++;
   printf("In parent process: created process number %d\n", pid);
  }
 }

 waitpid(pids[tot_proc - 1], &status, 0);
 if(WIFEXITED(status) != 0){
  printf("process %d exited normally\n", pids[tot_proc - 1]);
  printf("exit status from child is %d\n", WEXITSTATUS(status));
 } else {
  printf("process %d not exited normally\n" , pids[tot_proc -1]);	
 }
 return 0;
}
