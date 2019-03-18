#include<stdio.h>
int main()
{
 int pid;
 pid = fork();
 printf("The PID %d\nThe PPID %d\n", getpid(), getppid()); 
 if(pid == 0){
  //printf("The PID %d\nThe PPID %d\n", getpid(), getppid()); 
  system("ps -ef");
  sleep(10);
  system("ps -ef");
 }else{
  sleep(3);
 }
}
