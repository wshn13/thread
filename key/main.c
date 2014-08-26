#include <stdio.h>
#include <pthread.h>

pthread_key_t k;

void key_del(void* data)
{
	printf("key destruct \n");
}

void* fun(void* data)
{
	printf("fun thread %lu \n",pthread_self());
	pthread_key_create(&k, key_del);
	int i=8;
	pthread_setspecific(k,(void*)(&i));
	printf("get specific %d\n", *(int*)(pthread_getspecific(k)));
	/*
	 * If pthread_key_delete called ,the cleanup function(key_del) will not be called . 
	 */
	//pthread_key_delete(k);

}

int main(int argc,char** argv)
{
	pthread_t t;
	pthread_create(&t,NULL,fun,NULL);
	sleep(1);
	return 0;
}

