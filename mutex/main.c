#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

int main(int argc,char** argv)
{
	int ret = pthread_mutex_lock(&mtx);
	printf("%lu return %d\n",pthread_self(),ret);
	return 0;
}

