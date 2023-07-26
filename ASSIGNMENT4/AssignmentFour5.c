//5. Write a program which accept file name and position from user and read 20 bytes from that position.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char buffer[20] = {'\0'};
    int ret = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open %s file\n", argv[1]);
        return -1;
    }
	
	lseek(fd, atoi(argv[2]), SEEK_CUR);
	
    ret = read(fd,buffer,20);
    if(ret == 0)
    {
        printf("Unable to read data from %s file\n", argv[1]);
        return -1;
    }

    printf("20 bytes date from %s file after %s position:\n %s\n",argv[1], argv[2],buffer);
	close(fd);
    return 0;
}



/*sOutput
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ gcc AssignmentFour5.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ ./myexe que5_test.txt 15
20 bytes date from que5_test.txt file after 15 position:
 the  file offset to 
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ 
*/