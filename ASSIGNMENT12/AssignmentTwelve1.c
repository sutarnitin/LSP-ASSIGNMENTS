//1. Write a Program which is used to create unnamed pipe. Parent process creates new child process and both the processess will communicate
//    with each other

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int ret = 0;
	int fd[2];
	char Arr[] = "This is unnamed pipe";
	char buffer[512];
	
	pipe(fd);  //unanamed pipe created
	ret = fork();
	
	if(ret == 0)
	{
		printf("Child process scheduled for writing into pipe\n");
		close(fd[0]);
	}
	else{
		printf("Parent process scheduled for reading into pipe\n");
		close(fd[1]);
	}

	
	return 0;
}



//output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ gcc AssignmentTwelve1.c -o exe
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ ./exe 
// Parent process scheduled for reading into pipe
// Child process scheduled for writing into pipe
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ 
