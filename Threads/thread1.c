#include<stdio.h>
#include<pthread.h>
pthread_mutex_t m1,m2,m3;
pthread_t tid, tid1, tid2;

void f1(void *n){
	int i;
	for(i=1;i<=26;i++)
	{
	pthread_mutex_lock(&m1);
	printf("%d",i);
	fflush(stdout);
	pthread_mutex_unlock(&m2);
	}
}

void f2(void *n){
	int i;
	for(i='a';i<='z';i++)
	{
	pthread_mutex_lock(&m2);
	printf("%c",i);
	fflush(stdout);
	pthread_mutex_unlock(&m3);
	}
}

void f3(void *n){
	int i;
	for(i='A';i<='Z';i++)
	{
	pthread_mutex_lock(&m3);
	printf("%c\n",i);
	fflush(stdout);
	pthread_mutex_unlock(&m1);
	}
}

int main()
{
	pthread_mutex_lock(&m2);
	pthread_mutex_lock(&m3);
	pthread_create(&tid, NULL, f1, NULL);
	pthread_create(&tid1, NULL, f2, NULL);
	pthread_create(&tid2, NULL, f3, NULL);
	pthread_exit(0);
}
