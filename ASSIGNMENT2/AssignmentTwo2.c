//2. Write a program which accept file name from user and write String in that file.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
		
    int fd = 0;
    char buffer[BLOCKSIZE] = "Write a program which accept file name from user and write String in that file.";

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1], O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open %s file\n", argv[1]);
        return -1;
    }
	
    write(fd,buffer,sizeof(buffer));
	printf("Data successfully write into %s file\n", argv[1]);
    close(fd);

    return 0;
	
}

/* output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ gcc AssignmentTwo2.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ ./myexe hello.txt
Data successfully write into hello.txt file
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ 
*/