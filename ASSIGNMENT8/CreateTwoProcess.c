#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	
	int pid = 0, Exit_status = 0, cpid = 0;
	
	pid = fork();
	
	if(pid == 0)
	{
		printf("child[3] id is: %d & parent id is : %d\n", getpid(), getppid());
	}
	else
	{
		printf("child[2] id is: %d & parent id is : %d\n", getpid(), getppid());
		cpid = wait(&Exit_status);
	}
	
}


//output
/*
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ ./process 
child[2] id is: 8229 & parent id is : 3968
child[3] id is: 8230 & parent id is : 8229
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ 
*/

