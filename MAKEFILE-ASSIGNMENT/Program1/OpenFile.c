#include<fcntl.h>
#include "OpenFile.h"

int openFile(char fileName[])
{
	int fd = 0;
	fd = open(fileName, O_RDONLY);
	
	return fd;
}



//output

// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT$ gcc OpenFile.c OpenFileMain.c -o OpenFileMain -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT$ ls
// OpenFile.c  OpenFile.h  OpenFileMain  OpenFileMain.c
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT$ ./OpenFileMain 
// Enter the file name: 	OpenFile.c
// OpenFile.c file is suuccessfully opened with FD 3 
 // nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT$ 


