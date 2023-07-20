//Assignment1
//Write a program which accept file name from user and open that file.

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	
	char fileName[20];
	int fd = 0;
	
	printf("Enter the file name: \n");
	scanf("%s", fileName);
	
	fd = open(fileName, O_RDONLY);
		if(fd == -1){
	
			printf("Unable to open the file\n");
			return -1;
		
		}else{
	
		printf("File is suuccessfully opened with FD %d \n ", fd);
		
	}
	
	return 0;
}


//output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ gcc OpenFile.c -o OpenFile
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ ./OpenFile 
// Enter the file name: 
// OpenFile.c
// File is suuccessfully opened with FD 3 
 // nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ 


