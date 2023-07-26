//Assignment1
//2. Write a program which accept file name and mode from user and then open that file in specified mode.

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	int fd = 0, mode = 0;
	
	if(argc != 3)
	 {
		 printf("insufficeint Arguments\n");
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
	 	
	fd = open(argv[1], mode);
	
	if(fd == -1)
	{
		printf("Unable to open the %s file\n", argv[1]);
		return -1;	
	}
	else
	{
		printf("%s File is successfully opened with %s mode\n  ", argv[1], argv[2]);	
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




