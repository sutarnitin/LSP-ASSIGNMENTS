//1. Write a program in which parent process waits till its child process terminates.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char * argv[])
{
	int ret = 0, cpid = 0, Exit_status = 0;
	ret = fork();
	if(ret == 0)
	{
		execl("./childProcess", "Demo", "Hello", "Nitin", NULL);
	}
	else
	{
		printf("Parent is running with PID is: %d \n", getpid());
		cpid = wait(&Exit_status);
		printf("child process terminated having PID %d with exit status %d\n", cpid, Exit_status);
	}
	
	return 0;
}






//output
/*
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ gcc AssignmentEight1.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ ./exe 
Parent is running with PID is: 4255 
The running child process id is: 4256
The running parent process id is: 4255
child process terminated having PID 4256 with exit status 0
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ 
*/

