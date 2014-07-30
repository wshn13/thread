#include <stdio.h>
#include <pthread.h>

void* func(void* p)
{
	printf("Thread arg:%s id:%lu\n",(char*)p,pthread_self());
	sleep(2);
	return (void*)42;
}

int main()
{
	pthread_t th1;
	if(pthread_create(&th1,NULL,func,"hello")==0)
	{
		printf("Create thread success\n");
	}
	void* p=NULL;
	if(pthread_join(th1,&p)==0)
	{
		printf("Thread return %d\n",(int)(p));
	}
	return 0;
}

