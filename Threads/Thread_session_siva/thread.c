#include<stdio.h>
#include<pthread.h>
pthread_t tid,tid1,tid2;
void  f1(void *n)
{
printf("****hyd******%d %d \n",getpid(),getppid());
printf("ARI IN HYD\n");
sleep(20);
}
void  f2(void *n)
{
printf("***chn******%d %d \n",getpid(),getppid());
printf("ARI IN chn\n");
}
void  f3(void *n)
{
printf("****gooty******%d %d \n",getpid(),getppid());
printf("ARI IN gooty\n");
}
main()
{
pthread_create(&tid, NULL,f1,NULL);
pthread_join(tid,NULL);
pthread_create(&tid1, NULL,f2,NULL);
pthread_join(tid1,NULL);
pthread_create(&tid2, NULL,f3,NULL);
pthread_join(tid2,NULL);
pthread_exit(0);
}
