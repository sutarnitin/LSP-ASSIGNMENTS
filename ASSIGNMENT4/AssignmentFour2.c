//2. Write a program which accept directory name from user and create new directory of that name.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

int main(int argc, char *argv[])
{
	
	struct stat st = {0};
	if(argc != 3)
	{
		printf("Insufficent arguments\n");
		return -1;
	}
	
	if (stat(argv[2], &st) == -1) {
		mkdir(argv[2], 0700);
		printf("%s directory created\n", argv[2]);
	}
	
    return 0;
}


//output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ gcc AssignmentFour2.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ ./myexe myDir
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ ls
// Assignment4.txt  AssignmentFour1.c  AssignmentFour2.c  AssignmentFour3.c  AssignmentFour4.c  AssignmentFour5.c  myDir  myexe
