//Assignment1
//4. Write a program which accept file name from user and print all information about that file.

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	struct stat buffer;
	int fd = 0;
	if(argc != 2){
		printf("Insufficient arguments \n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open %s file\n", argv[1]);
		return -1;
	}
	else
	{
		printf("%s file opened successfully in read mode\n");
	}

	fstat(fd, &buffer);	
	printf("File name : %s\n", argv[1]);
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


/*output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ gcc AssignmentFirst4.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ ./myexe Demo.txt
Demo.txt file opened successfully in read mode
File name : Demo.txt
File size is : 27
Number of links : 1
Inode number : 1852788
File system number : 2055
Number of blocks : 8
User Id : 1000
Group Id : 1000
Block Size: 4096
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$
*/