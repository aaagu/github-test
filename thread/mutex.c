#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>

char buf[100];
unsigned int count,value1,value2;
pthread_mutex_t mutex;

void *a_threadFun(void *arg);
int main()
{
	pthread_t a_thread;
	void *rval;

	if(pthread_mutex_init(&mutex, NULL) != 0){
		perror("pthread_mutex_init");
		exit(1);
	}

	pthread_create(&a_thread, NULL, a_threadFun, NULL);
	count = 0;
	while(1){
		count++;
		pthread_mutex_lock(&mutex);
		value1 = count;
		value2 = count;
		pthread_mutex_unlock(&mutex);
	}
	pthread_join(a_thread, &rval);
	printf("pthread_join rval: %s\n", rval);

	return 0;
}

void *a_threadFun(void *arg)
{
	while(1){
		printf("value1 : %d   value2 : %d\n", value1, value2);
	}
	pthread_exit("a_thread exit");
}
