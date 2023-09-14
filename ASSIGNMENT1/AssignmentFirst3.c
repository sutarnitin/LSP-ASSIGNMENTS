//Assignment1
//3. Write a program which accept file name and mode and that program check whether our process can access that 
//    file in accepted mode or not.

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	int fd = 0, mode = 0;
	
	if(argc != 3)
	{
		printf("Insufficeint arguments\n");
		return -1;
	}
	 
	if(strcmp(argv[2], "read") == 0)
	{
		mode = R_OK;
	}
	else if(strcmp(argv[2], "write") == 0)
	{
		mode = W_OK;
	}
	else if(strcmp(argv[2], "execute") == 0)
	{
		mode = X_OK;
	}
	
	if(access(argv[1], mode) < 0)
	{
		printf("Unable to access %s file in %s mode \n ", argv[1], argv[2]);
	} 
	else
	{
		printf("You can access %s file in %s mode \n ", argv[1], argv[2]);
	}
	
	return 0;
}

/*output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ gcc AssignmentFirst2.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ ./myexe Demo.txt write
Demo.txt File is successfully opened with write mode
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ ./myexe Demo.txt read
Demo.txt File is successfully opened with read mode
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$
*/


