//2. Write a program which create hole of size 1kb at the end of file.

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