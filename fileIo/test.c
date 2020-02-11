#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int fd;
	fd = open("./test.txt", O_RDWR|O_CREAT|O_TRUNC, 0666);
	if(fd == EOF){
		perror("open");
		exit(1);
	}

	fchmod(fd, 0666);
	if((write(fd, "12345", 5)) == EOF){
		perror("write");
	}else{
		printf("write success\n");
	}
	
	struct stat st;
	fstat(fd, &st);


	close(fd);

	DIR *dir;
	if((dir = opendir("./")) == NULL){
		perror("opendir");
	}else{
		printf("opendir success\n");
	}
	
	return 0;
}


