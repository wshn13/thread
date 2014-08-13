#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int flag = 0;

void* thread1(void* arg)
{
	printf("this is thread %lu\n",pthread_self());
	pthread_mutex_lock(&mtx);
	while(flag==0)
	{
		pthread_cond_wait(&cond,&mtx);
	}
	printf("condition come true %lu \n",pthread_self());
	pthread_mutex_unlock(&mtx);
}

void* thread2(void* arg)
{
	sleep(2);
	pthread_mutex_lock(&mtx);
	flag=1;
	pthread_cond_broadcast(&cond);
	printf("send signal to condition \n");
	pthread_mutex_unlock(&mtx);
}

int main(int argc,char** argv)
{
	pthread_t t2;
	int i=0;
	for(i=0;i<5;i++)
	{
		pthread_t t1;
		pthread_create(&t1,NULL,thread1,NULL);
	}
	pthread_create(&t2,NULL,thread2,NULL);
	sleep(4);
	return 0;
}


