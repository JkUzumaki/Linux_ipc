#include<stdio.h>
#include<pthread.h>

pthread_t tid;

void f1()
{
	while(1)
		{
		printf("Hello World!\n");
		break;
	}
}

int main()
{
    while(1){
	printf("****************************\n");
	pthread_create(&tid, NULL, f1, NULL);
	pthread_join(tid,NULL);
    }
	pthread_exit(0);
}
