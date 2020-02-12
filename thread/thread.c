#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>

char buf[100];
sem_t semR;
sem_t semW;
void *a_threadFun(void *arg);
int main()
{
	pthread_t a_thread;
	void *rval;

	if(sem_init(&semR,0,0) != 0){
		perror("sem_initR");
		exit(1);
	}
	if(sem_init(&semW,0,1) != 0){
		perror("sem_initW");
		exit(1);
	}
	pthread_create(&a_thread, NULL, a_threadFun, NULL);
	while(1){
		sem_wait(&semW);
		gets(buf);
		sem_post(&semR);
	}
	pthread_join(a_thread, &rval);
	printf("pthread_join rval: %s\n", rval);

	return 0;
}

void *a_threadFun(void *arg)
{
	while(1){
		sem_wait(&semR);
		printf("stdin : %s\n", buf);
		sem_post(&semW);
	}
	pthread_exit("a_thread exit");
}
