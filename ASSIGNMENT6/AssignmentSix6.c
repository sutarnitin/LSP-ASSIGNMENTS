//6. Write a program which accept directory name from user and create hole in file if size is less than 1kb and if it is greater 
    // than 1kb then truncate the remaining data.
	
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int fd = 0;
    int ret = 0;
	char *buffer=NULL;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
	buffer=malloc(atoi(argv[2])*sizeof(char));

    fd = open(argv[1], O_WDONLY|O_RDONLY);
	
    if(fd == -1)
    {
        printf("Unable to open %s file\n", argv[1]);
        return -1;
    }
	
	lseek(fd, atoi(argv[2]), SEEK_CUR);
	ret = truncate(fd, 10);
    printf("Deleted data from %s file after %s position:\n",argv[1], argv[2]);
	close(fd);
    return 0;
}

/*output
*/