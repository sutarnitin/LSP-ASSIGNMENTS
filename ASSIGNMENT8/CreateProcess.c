//process id using getpid()

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	
	int pid = 0;
	pid = getpid();
	
	printf("The running child process id is: %d\n", pid);
	printf("The running parent process id is: %d\n", getppid());
}