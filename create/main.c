#include <stdio.h>
#include <pthread.h>

void* func(void* p)
{
	// 获得自己的线程ID
	printf("Thread arg:%s id:%lu\n",(char*)p,pthread_self());
	sleep(2);
	return (void*)42;
}

int main()
{
	pthread_t th1;
	pthread_t th2;
	
	// 创建线程
	if(pthread_create(&th1,NULL,func,"thread1")==0)
	{
		printf("Create thread1 success\n");
	}
	
	if(pthread_create(&th2,NULL,func,"thread2")==0)
	{
		printf("Create thread2 success\n");
		// 分离线程
		if(pthread_detach(th2)==0)
		{
			printf("Detached thread2 \n");
		}
	}

	void* p=NULL;
	// 等待线程结束
	if(pthread_join(th1,&p)==0)
	{
		printf("Thread return %d\n",(int)(p));
	}
	return 0;
}

