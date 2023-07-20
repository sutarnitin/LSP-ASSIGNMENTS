//2. Write a program which accept file name from user and write String in that file.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
		
    int fd = 0;
    int Ret = 0;
    char buffer[BLOCKSIZE];

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1], O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
	
    while((Ret = read(fd,buffer,sizeof(buffer))) != 0)
    {
        write(fd,buffer,Ret);
		memset(buffer,0,sizeof(buffer));
    }
    
    close(fd);

    return 0;
	
}