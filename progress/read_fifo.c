#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int fd;
	char buf[100];
	if((fd = open("myfifo", O_RDONLY)) < 0){
		perror("open");
		exit(1);
	}

	while(read(fd, buf, 100) > 0){
		printf("buf : %s\n", buf);
	}
	close(fd);
	return 0;
}
