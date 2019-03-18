#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
main()
{
struct stat v;
struct dirent *d;
DIR *ptr;
ptr=opendir("./");
if(ptr==NULL)
{
perror("opendir");
return;
}
while((d=readdir(ptr))!=NULL)
{
printf("%s\n",d->d_name);
}
}
