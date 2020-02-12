#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
	pid_t pid;
	if((pid = fork()) < 0){
		perror("fork");
		exit(1);
	}
	if(pid == 0){
		while(1){
			printf("zi\n");
			sleep(1);
		}
	}else{
		while(1){
			printf("fu\n");
			sleep(1);
		}
	}
	return 0;
}
