#include<stdio.h>
#include<unistd.h>
main(int argc,char **argv)
{
int i=0;
for(i=1;i<=3;i++)
{
if(fork()==0)
{
execlp(argv[i],argv[i],NULL);
}
while(wait(0)!=-1);
}
}
