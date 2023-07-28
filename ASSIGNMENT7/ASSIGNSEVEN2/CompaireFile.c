//compaire the contents from two files

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024
int CompaireFile(char *file1, char *file2)
{
	int fd1 = 0, fd2 = 0, ret1=0, ret2=0, rs=0;
	int diff;
    int line =1, col = 0;
	char ch1;
	char ch2;
	
	struct stat st1;
	struct stat st2;
	char buffer1[BLOCKSIZE] = {'\0'}, buffer2[BLOCKSIZE] = {'\0'};
	
	//Check file size of two files are equal or not
	if((stat(file1, &st1) ==0) && (stat(file2, &st2) ==0))
	{
		if(st1.st_size != st2.st_size)
		{
			printf("Two files have different size of data.\n");
			return -1;
		}
		else{
			printf("Size are same.\n");
		}
	}
	else{
		printf("Unable to find the file info. \n");
		return -1;
	}
	fd1 = open(file1, O_RDONLY);
	fd2 = open(file2, O_RDONLY);
	 
	if( (fd1 == -1) || (fd1 == -1) )
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	while((ret1 = read(fd1, buffer1, sizeof(buffer1))) != 0 && (ret2 = read(fd2, buffer2, sizeof(buffer2))) != 0)
	{
		//printf("1. %s", buffer1);
		//printf("2. %s", buffer2);
		if(strncmp(buffer1, buffer2, sizeof(buffer1)) != 0)
		{
			printf("Two files are not equal\n");
			return -1;
		}
		memset(buffer1, 0, sizeof(buffer1));
		memset(buffer2, 0, sizeof(buffer2));
	}
	printf("Two files have equal contents\n");

	close(fd1);
	close(fd2);
	
	return 0;
}


// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ ls
// AssignmentSeven2.c  CompaireFile.c  Demo.txt  file.h  hello.txt  main.c
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ gcc -c -fpic CompaireFile.c 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ ls
// AssignmentSeven2.c  CompaireFile.c  CompaireFile.o  Demo.txt  file.h  hello.txt  main.c
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ gcc -o lib_second.so -shared -fpic CompaireFile.o 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ gcc -rdynamic -o Myexe main.c 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ gcc -ldl -o Myexe main.c 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ ./Myexe 
// Insufficient arguments
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ ./Myexe Demo.txt hello.txt 
// Unable to load liabrary
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ 

