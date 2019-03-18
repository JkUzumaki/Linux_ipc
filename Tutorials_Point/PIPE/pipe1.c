#include<stdio.h>
int main()
{
	int p[2];	// p[0] = read && p[1] = write
	pipe(p);
	char str[80];
	if( fork() ){
		printf("Waiting for read\n");
		read(p[0], str, 80);
		printf("The message is %s\n",str);
	} else {
		printf("Ener the message\n");
		scanf("%s",&str);
		write(p[1], str, strlen(str)+1);
	}
	return 0;	
}
