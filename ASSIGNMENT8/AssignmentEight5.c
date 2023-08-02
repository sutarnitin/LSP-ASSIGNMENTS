//5. Wrire a program which is used to create daemon process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int ret = 0, sid = 0, fd = 0, iCnt = 0;
	
	ret = fork();
	if(ret < 0)
	{
		printf("fork failed!\n");
		exit(1);
	}
	
	if(ret > 0)
	{
		printf("pid of child process %d \n", getpid());
		exit(0);
	}
	
	umask(0);
	
	//create new session
	sid = setsid();
	if(sid < 0)
	{
		exit(1);
	}
	
	// Change the current working directory to root.
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	// Open a log file in write mode.
	fd = open("Log.txt", O_WRONLY | O_CREAT, 0666);
	
	while(iCnt < 5)
	{
		write(fd, "Jay Ganesh...\n", 13);
		iCnt++;
	}
	
	close(fd);
	return (0);
}



//output
/*
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ gcc AssignmentEight5.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ ./exe 
pid of child process 6515 
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ 
*/