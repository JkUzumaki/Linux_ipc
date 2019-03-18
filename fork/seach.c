#include<stdio.h>
#include<string.h>
#include<dirent.h>
int search(char *d,char *fname)
{
char str[2000];
DIR *dptr;
struct dirent *ptr;
dptr=opendir(d);
if(dptr==NULL)
{
//perror("opendir");
return;
}
while((ptr=readdir(dptr))!=NULL)
{
if((ptr->d_type==4)&&(ptr->d_name[0]!='.'))/////dorectory name
{
bzero(str,200);
strcpy(str,d);
strcat(str,"/");
strcat(str,ptr->d_name);
search(str,fname);
}
if(strcmp(fname,ptr->d_name)==0)
{
printf("********%s\n",d);
return;
}
}
}
main(int argc,char **argv)
{
search("/home/jmariyappan",argv[1]);
}
