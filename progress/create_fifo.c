#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{	
	if(mkfifo("myfifo", 0666) != 0){
		perror("fifo");
		exit(1);
	}
	return 0;
}
