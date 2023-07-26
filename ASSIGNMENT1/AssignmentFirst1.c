//Assignment1
//1. Write a program which accept file name from user and open that file.

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	char fileName[20];
	int fd = 0;
	
	printf("Enter the file name: \t");
	scanf("%s", fileName);
	
	fd = open(fileName, O_RDONLY);
		if(fd == -1)
		{
			printf("Unable to open the %s file\n", fileName);
			return -1;
		}
		else
		{
			printf("%s file is suuccessfully opened with FD %d \n ", fileName, fd);
		}
	close(fd);
	return 0;
}


/*output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ gcc AssignmentFirst1.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ ./myexe
Enter the file name: 	Demo.txt 
Demo.txt file is suuccessfully opened with FD 3 
 nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ ./myexe
Enter the file name: 	DEmo.txt
Unable to open the DEmo.txt file
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ 
*/
