//3. Write a program which accept file name and mode and that program check whether our process can access that 
 // file in accepted mode or not.

#include<stdio.h>
#include<fcntl.h>
#include "AccessOpenedFile.h"

int main(int argc, char * argv[])
{
	int fd = 0, mode = 0;
	char *ptr = argv[1];
	
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
	
	ptr = AccessFile(ptr, mode); 	

	if(ptr< 0)
	{
		printf("Unable to access %s file in %s mode \n ", argv[1], argv[2]);
	} 
	else
	{
		printf("You can access %s file in %s mode \n ", argv[1], argv[2]);
	}
	
	return 0;
}

//Output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/program3$ make -f MakeAccessOpenedFile 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/program3$ ls
// AccessOpenedFile  AccessOpenedFile.c  AccessOpenedFile.h  AccessOpenedFileMain.c  Demo.txt  MakeAccessOpenedFile
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/program3$ make -f MakeAccessOpenedFile run
// Insufficeint arguments
// make: *** [MakeAccessOpenedFile:5: run] Error 255
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/program3$ make -f MakeAccessOpenedFile run
// You can access Demo.txt file in Write mode 
 // nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/program3$