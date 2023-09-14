//Assignment1
//5. Write a program which accept file name and number of bytes from user and read that number of bytes from file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include "ReadBytesOfFile.h"


int main(int argc, char * argv[])
{
	int fd = 0;
    int Ret = 0;
    char *Buffer = NULL;
    int Size = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
	
	char *ptr = argv[1];

    fd = openFile(ptr);
    if(fd == -1)
    {
        printf("Unable to open %s file\n", argv[1]);
        return -1;
    }
	else
	{
		printf("%s file successfully opened in read mode\n", argv[1]);
	}

    Size = atoi(argv[2]);

    Buffer = (char *)malloc(Size);

    Ret = readFile(fd,Buffer,Size);
    if(Ret == 0)
    {
        printf("Unable to read data from %s file\n", argv[1]);
        return -1;
    }

    printf("File data is : \n");
    write(1,Buffer,Ret);
	printf("\n");
	
	return 0;
}


/*output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/program5$ rm ReadBytesOfFile
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/program5$ ls
Demo.txt  MakeReadBytesOfFile  ReadBytesOfFile.c  ReadBytesOfFile.h  ReadBytesOfFileMain.c
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/program5$ make -f MakeReadBytesOfFile 
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/program5$ ls
Demo.txt  MakeReadBytesOfFile  ReadBytesOfFile  ReadBytesOfFile.c  ReadBytesOfFile.h  ReadBytesOfFileMain.c
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/MAKEFILE-ASSIGNMENT/program5$ make -f MakeReadBytesOfFile run
Demo.txt file successfully opened in read mode
File data is : 
Jay Ganesh...
*/