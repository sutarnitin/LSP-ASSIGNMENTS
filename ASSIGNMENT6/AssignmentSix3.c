//3. Write a program which accept directory name and file name from user and create file in that directory.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
	int fd=0;
    char * path=  NULL;
	
	if(argc != 3)
	{
		 printf("Insufficient arguments\n");
		 return -1;
	}
	
	path = malloc(strlen(argv[1])+strlen(argv[2]));
	sprintf(path,"%s/%s", argv[1], argv[2]);
	
    fd = creat(path,0777);
	if(fd == -1)
	{
		printf("Unable to creat %s file in %s directory\n", argv[2], argv[1]);
	}
	else
	{
		printf("Created %s file in %s directory\n", argv[2], argv[1]);
	}
    close(fd);

    return 0;
}

/*output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT6$ gcc AssignmentSix3.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT6$ ./myexe Que3_Test_Folder que3_test.txt
Created que3_test.txt file in Que3_Test_Folder directory
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT6$ cd Que3_Test_Folder/
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT6/Que3_Test_Folder$ ls
que3_test.txt
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT6/Que3_Test_Folder$ 
*/