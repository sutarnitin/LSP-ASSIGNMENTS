//4. Write a program which accept file name and position from user and read 20 bytes from that position..

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>za

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

    Ret = read(fd,Buffer,10);
    if(Ret == 0)
    {
        printf("Unable to read data from file\n");
        return -1;
    }

    printf("Data from file is : %s\n",Buffer);

    return 0;
}


//output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ ls
// a.txt  b.txt  c.txt  d.txt
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ cd ..
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ gcc AssignmentThree4.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ ./myexe MYFILES
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ cd MYFILES/
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ ls
// a.txt
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ 
