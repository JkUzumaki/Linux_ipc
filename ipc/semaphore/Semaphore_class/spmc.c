#include<stdio.h>
#include<unistd.h>

main()
{
    if( fork() ){
	if( fork() ){
	    if( fork() ){
		printf("parent %d     %d\n",getpid(), getppid());
		while(1);	
	    }else{
		printf("Child 3 %d     %d\n",getpid(), getppid());	
	    }
	} else {
           printf("Child 2 %d     %d\n",getpid(), getppid());			
	}
    } else {
	printf("Child 1 %d     %d\n",getpid(), getppid());	
    }
}
