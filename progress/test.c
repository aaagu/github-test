#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{	
	pid_t pid;
	if((pid = fork()) < 0){
		perror("fork");
		exit(1);
	}
	if(pid == 0){
		while(1);
	}else{
		while(1);
	}
	return 0;
}
