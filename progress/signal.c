#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

void handler(int signal)
{
	if(signal == SIGINT){
		printf("-----SIGINT-------\n");
	}
	if(signal == SIGQUIT){
		printf("----SIGQUIT-----\n");
	}
}

int main()
{	
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	while(1)
	pause();
	return 0;
}
