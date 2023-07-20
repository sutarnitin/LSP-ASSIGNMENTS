//5. Write a program which accept file name and position from user and read 20 bytes from that position.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[20] = {'\0'};
    int Ret = 0;

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
    }
	
	lseek(fd, atoi(argv[2]), SEEK_CUR);
	
    Ret = read(fd,Buffer,20);
    if(Ret == 0)
    {
        printf("Unable to read data from file\n");
        return -1;
    }

    printf("Data from file is : %s\n",Buffer);

    return 0;
}



//Output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ gcc AssignmentFour5.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ ./myexe abc.txt 20
// Data from file is : file offset to be se
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ 

