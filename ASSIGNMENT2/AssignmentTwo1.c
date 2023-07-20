//1. Write a program to accept file name from user and read whole file.

#include<stdio.h>;
#include<stdlib.h>;
#include<fcntl.h>;
#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
		
    int fd = 0;
    int Ret = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        write(1,Buffer,Ret);
    }
    printf("\n");
    close(fd);

    return 0;
	
}

// output:
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ gcc AssignmentTwo1.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ ./myexe Demo.txt 
// File successfully opened in read mode
// Modes
// The mode argument describes how to open the given file. It is one of the following strings:
// r
// Open the file for reading. The stream is positioned at the start of the file.
// r+
// Open the file for both reading and writing. The stream is positioned at the start of
// the file.
// w
// Open the file for writing. If the file exists, it is truncated to zero length. If the file
// does not exist, it is created. The stream is positioned at the start of the file.
// w+
// Open the file for both reading and writing. If the file exists, it is truncated to zero
// length. If the file does not exist, it is created. The stream is positioned at the start
// of the file.
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ 

