//5. Write a program which accept file name which contains data of all file. we have to create all file again.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	
	if(argc != 2)
	{
		printf("insufficient arguments\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("1. Unable to open file %s\n", argv[1]);
	}
	
	while((ret = read(fd, buffer, sizeof(buffer))) != 0)
	{
		write(dest_fd, buffer, ret);
		memset(buffer, 0, sizeof(buffer));
	}
}

//output
