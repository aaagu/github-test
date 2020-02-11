#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[100];
	fp = fopen("./test.txt", "w+b");
	if(fp == NULL){
//		perror("open error");
		printf("%s\n", strerror(errno));
		printf("%d\n", errno);
		exit(1);
	}else{
		printf("open secussed\n");
	}

	time_t t;
	struct tm *tp;
	int line = 0;
	while(1){
		time(&t);
		tp = localtime(&t);
		fprintf(fp, "%02d, %d-%02d-%02d %02d:%02d:%02d\n", ++line, tp->tm_year+1990, tp->tm_mon+1, tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);
		fflush(fp);
		sleep(1);
	}
	
	if(fclose(fp) == -1)
	{
		perror("fclose");
	}else{
		printf("fclose success\n");
	}

	return 0;
}

