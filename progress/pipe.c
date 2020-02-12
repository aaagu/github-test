#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	char buf[100];
	int pfd[2];
	if(pipe(pfd) != 0){
		perror("pipe");
		exit(1);
	}
	if((pid = fork()) < 0){
		perror("fork");
		exit(1);
	}
	if(pid == 0){
		close(pfd[1]);
		while(1){
			read(pfd[0], buf, 100);
			printf("buf: %s\n", buf);
		}
	}else{
		close(pfd[0]);
		while(1){
			gets(buf);
			write(pfd[1], buf, 100);
		}
	}

	return 0;
}
