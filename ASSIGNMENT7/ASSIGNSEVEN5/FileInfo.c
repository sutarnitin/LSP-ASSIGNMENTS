//Write a program which accept file name from user and print all information about that file.

#include<stdio.h>
#include<fcntl.h>

int FileInfo(char fptr[])
{
	struct stat buffer;
	int fd = 0;

	fd = open(fptr, O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open %s file\n", fptr);
		return -1;
	}
	else
	{
		printf("%s file opened successfully in read mode\n");
	}

	fstat(fd, &buffer);	
	printf("File name : %s\n", fptr);
    printf("File size is : %d\n", buffer.st_size);
    printf("Number of links : %d\n", buffer.st_nlink);
    printf("Inode number : %d\n", buffer.st_ino);
    printf("File system number : %d\n", buffer.st_dev);
    printf("Number of blocks : %d\n", buffer.st_blocks);
    printf("User Id : %d\n", buffer.st_uid);
    printf("Group Id : %d\n", buffer.st_gid);
    printf("Block Size: %d\n", buffer.st_blksize);

	return 0;
}

