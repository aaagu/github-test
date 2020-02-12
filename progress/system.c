#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int te;
	if((te = system("./systemrun")) == EOF){
		perror("system");
	}else{
		printf("system return : %d\n", te);
	}
	return 0;
}
