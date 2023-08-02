//2. Write a program which create hole of size 1kb at the end of file.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
    int fd=0, offset = 1024;
	struct stat statbuf;
	
	if(argc != 2)
	{
		 printf("Insufficient arguments\n");
		 return -1;
	}
	
    fd = open(argv[1],O_RDWR|O_CREAT, 0666);
	if(fd == -1)
	{
		printf("Unable to open source %s file\n", argv[1]);
        return -1;
	}
	lseek(fd, offset, SEEK_SET);
	write(fd, "A", 1);
    close(fd);
	stat(argv[1], &statbuf);
    printf("The file %s has size %lld and takes %lld sectors\n", argv[1],
               (long long) statbuf.st_size, (long long) statbuf.st_blocks);
    return 0;
}

//output