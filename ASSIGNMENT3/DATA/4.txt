//1. Write a program which accept two file names from user and copy the contents of an existing file into to newly created file.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
	int srcfd = 0, destfd = 0, ret = 0;
	char buffer[BLOCKSIZE] = {'\0'};
	
	if(argc != 3)
	{
		printf("insufficient Arguments\n");
		return -1;
	}
	
	srcfd = open(argv[1], O_RDONLY);
	if(srcfd == -1)
	{
		printf("Unable to open source file\n");
        return -1;
	}
	
	destfd = creat(argv[2], 0777);
	if(destfd == -1)
	{
		printf("Unable to create file\n");
        return -1;
	}
	
	while((ret = read(srcfd, buffer, sizeof(buffer))) != 0)
	{
		write(destfd, buffer, ret);
		memset(buffer, 0, sizeof(buffer));
	}
	
	close(srcfd);
	close(destfd);
	
	return 0;
	
}


//output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ gcc AssignmentThree1.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ ./myexe Demo.txt Hello.txt
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ ls
// Assignment3.txt  AssignmentThree1.c  AssignmentThree2.c  AssignmentThree3.c  AssignmentThree4.c  Demo.txt  Hello.txt  myexe
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$