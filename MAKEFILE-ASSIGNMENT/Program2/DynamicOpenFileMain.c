//2. Write a program which accept file name and mode from user and then open that file in specified mode.

#include<stdio.h>
#include<fcntl.h>
#include "DynamicOpenFile.h"

int main(int argc, char * argv[])
{

	int fd = 0, mode = 0;
	char fileName[20];
	char * ptr;
	
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
	ptr = argv[1];
	fd = OpenFile(ptr, mode);
	
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


//output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/Program2$ make -f MakeDynamicOpenFile 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/Program2$ ls
// Demo.txt  DynamicOpenFile  DynamicOpenFile.c  DynamicOpenFile.h  DynamicOpenFileMain.c  MakeDynamicOpenFile
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/Program2$ make -f MakeDynamicOpenFile run
// file name Demo.txt:
 // mode 4: 
// Demo.txt File is successfully opened with read mode
  // nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/Program2$