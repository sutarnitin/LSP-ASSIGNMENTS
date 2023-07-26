//1. Write a program which accept file name which contains data of all file, We have to print all file names whose size is greater that 10 bytes.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
    
	if(argc != 2)
	{
		 printf("Insufficient arguments\n");
		 return -1;
	}
	
    fd = open(argv[1],O_RDONLY);
	if(srcfd == -1)
	{
		printf("Unable to open source %s file\n", argv[1]);
        return -1;
	}
    close(fd);

    return 0;
}

//output