//1. Write a program which accept file name from user and open that file.

#include<stdio.h>
#include<fcntl.h>
#include "OpenFile.h"

int main(int argc, char * argv[])
{
	char fileName[20];
	int fd = 0;
	
	printf("Enter the file name: \t");
	scanf("%s", fileName);
	
	fd = openFile(fileName);
		if(fd == -1)
		{
			printf("Unable to open the %s file\n", fileName);
			return -1;
		}
		else
		{
			printf("%s file is successfully opened with FD %d \n ", fileName, fd);
		}
	close(fd);
	return 0;
}



// Using makefile output

// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT$ make
// make: *** No targets specified and no makefile found.  Stop.
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT$ make -f MakeOpenFile
// gcc OpenFile.c OpenFileMain.c -o OpenFileMain -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT$ ls
// MakeOpenFile  OpenFile.c  OpenFile.h  OpenFileMain.c
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT$ make -f MakeOpenFile
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT$ ls
// MakeOpenFile  OpenFile.c  OpenFile.h  OpenFileMain  OpenFileMain.c
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT$ make -f MakeOpenFile run
// Enter the file name: 	OpenFile.c
// OpenFile.c file is successfully opened with FD 3 
 // nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT$ 

