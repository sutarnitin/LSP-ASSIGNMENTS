//3. Write a program which creates one child process, child process write something in unnamed pipe and parent process read the data from that
//	file.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define READ 0
#define WRITE 1

int main()
{
	int ret = 0, res = 0;
	int fd[2];
	char arr[] = "This is unnamed pipe";
	char buffer[512];
	
	pipe(fd);  //unanamed pipe created
	ret = fork();
	
	if(ret == 0)
	{
		printf("Child process scheduled for writing into pipe\n");
		close(fd[READ]);
		write(fd[WRITE], arr, strlen(arr));
		printf("Child:  Wrote '%s' to pipe!\n", arr);
	}
	else{
		printf("Parent process scheduled for reading into pipe\n");
		close(fd[WRITE]);
		res = read(fd[READ], buffer, sizeof(buffer));
		printf ( "Parent: Read %d bytes from pipe: %s\n", res, buffer);
	}

	
	return 0;
}


//Output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ gcc AssignmentTwelve3.c -o exe
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ ./exe 
// Parent process scheduled for reading into pipe
// Child process scheduled for writing into pipe
// Child:  Wrote 'This is unnamed pipe' to pipe!
// Parent: Read 20 bytes from pipe: This is unnamed pipe
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ 

