//6. Write a program which accept directory name from user and create hole in file if size is less than 1kb
// and if it is greater than 1kb then truncate the remaining data.
	
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    char namecopy[30] = {'\0'};
	int offset = 1024, limit=1024, ret=0, fd=0;
    
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    };

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open %s directory \n", argv[1]);
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
	
        if(S_ISREG(sobj.st_mode))
        {
			fd = open(name, O_RDONLY|O_WRONLY, 0666);
            if(sobj.st_size<limit)
            {
                //remove(name);
				printf("Removed %s file from %s directory whose size %d is greater than %d byte \n" , entry->d_name, argv[1], sobj.st_size, limit);
            }
			else
			{
				ret = ftruncate(fd, offset);
				printf("Deleted data after %d position from %s file\n",offset, entry->d_name);
			}
			close(fd);
        }
    }

    closedir(dp);
    
    return 0;

}
/*output
*/