#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{	
	int fd;
	char buf[100];

	if((fd = open("myfifo", O_WRONLY)) < 0){
		perror("open");
		exit(1);
	}
	while(1){
		gets(buf);
		if(strcmp(buf, "quit\n") == 0)
			break;
		write(fd, buf, 100);
	}
	close(fd);

	return 0;
}
