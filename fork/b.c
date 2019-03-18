#include<stdio.h>
main()
{
printf("***************************************");
int i=5;
if(fork())
{
sleep(2);
wait(&i);
i=i>>8;
printf("parent:%d   %d   %d\n",getpid(),getppid(),i);
}
else
{
i=i+1;
printf("child:%d   %d   %d\n",getpid(),getppid(),i);
exit(i);
}
}
