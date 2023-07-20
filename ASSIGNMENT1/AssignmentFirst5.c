//Assignment1
//5. Write a program which accept file name and number of bytes from user and read that number of bytes from file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char * argv[])
{
	int fd = 0;
    int Ret = 0;
    char *Buffer = NULL;
    int Size = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }else{
		printf("File successfully opened in read mode\n");
	}

    Size = atoi(argv[2]);

    Buffer = (char *)malloc(Size);

    Ret = read(fd,Buffer,Size);
    if(Ret == 0)
    {
        printf("Unable to read data from file\n");
        return -1;
    }

    printf("File data is : \n");
    write(1,Buffer,Ret);
	printf("\n");
	
	return 0;
}


//output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ gcc AssignmentFirst5.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ ./myexe Demo.txt 11
// File successfully opened in read mode
// File data is : 
// Jay Ganesha
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT1$ 

