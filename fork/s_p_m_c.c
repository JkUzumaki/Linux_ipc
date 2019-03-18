#include<stdio.h>
#include<unistd.h>
main(int argc,char **argv)
{
if(fork())
{
if(fork())
{
if(fork())
{
printf("parent %d    %d\n",getpid(),getppid());
while(1);
}
else
{
printf("child3:%d    %d\n",getpid(),getppid());
}
}
else
{
printf("child2:%d    %d\n",getpid(),getppid());
}
}
else
{
printf("child1:%d    %d\n",getpid(),getppid());
}
}
