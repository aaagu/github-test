#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int *status;
	status = (int *)malloc(sizeof(int));
	pid_t pid;
	if((pid = fork()) < 0){
		perror("fork");
		exit(1);
	}
	if(pid == 0){
		sleep(3);
		exit(2);
	}else{
		wait(status);
		printf("status : %d\n", *status);
	}
	return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  int status;
    pid_t pid;

	  if ((pid = fork()) < 0) {
	       perror("fork");  
			 exit(-1);
			   }
			     else if (pid == 0) {
				      sleep(1);  
						 exit(2);
						   }
						     else {
							      wait(&status);  
									 printf("%x\n", status);
									   }

									     return 0;
										 }  
*/
