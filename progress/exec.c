#include <unistd.h>

int main()
{
	execl("./test", "",NULL);
	printf("-----------\n");
	execl("/bin/ls", "-l", "-a", ".", NULL);
	while(1);
}
