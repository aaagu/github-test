#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
	pid_t pid;
	if((pid = fork()) < 0){
		perror("fork");
		exit(1);
	}
	if(pid == 0){
		if(setsid() < 0){
			perror("setsid");
			exit(1);
		}
		chdir("/tmp");
		if(umask(0) < 0){
			perror("umask");
			exit(1);
		}
		int i;
		for(i = 0; i < getdtablesize(); i++){
//			close(i);
		}
		FILE *fp;
		time_t t;
		if((fp = fopen("/home/chy/Development/work/gitTest/github-test/progress/time.log", "w")) ==NULL){
			perror("fopen");
			exit(1);
		}
		while(1){
			time(&t);
			fprintf(fp, "%s\n", ctime(&t));
			fflush(fp);
			sleep(1);
		}
	}else{
		exit(0);
	}
	return 0;
}
