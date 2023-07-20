//4. Write a program which accept directory name from user and copy first 10 bytes from all regular files into newly created file 
//named as Demo.txt.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int ret = 0, fd=0, fd1=0;
	struct stat sobj;
	struct dirent *entry = NULL;
	char buffer[20] = {'\0'};
	char dir_name[strlen(argv[1])];
	char * temp;
    DIR *dp = NULL;
    printf("1. %s\t%d\n", dir_name, strlen(argv[1]));
    printf("3. %s\t%d\n", argv[1], strlen(argv[1]));
	memcpy(dir_name, argv[1], strlen(argv[1]));
	printf("2. %s\t%d\t%d\n", dir_name, strlen(argv[1]), strlen(dir_name));
	if(argc != 3)
	{
		printf("insufficient arguments\n");
		return -1;
	}

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

	fd1 = creat(argv[2], 0777);
    if(fd1 == -1)
    {
        printf("Unable to create destination file\n");
        return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
		asprintf(&temp, "%s%s", dir_name, entry->d_name);
		printf("%s\t \n", temp);
		if(stat(temp, &sobj) ==0)
		{
			if(S_ISREG(sobj.st_mode) && (sobj.st_size!=0))
			{
				printf("File name : %s\n", entry->d_name);
				
				fd = open(temp, O_RDONLY);
				
				
				if(fd == -1)
				{
					printf("1. Unable to open file %s\n", entry->d_name);
				}
				else
				{
					if((ret = read(fd,buffer,10)) != 0)
					{
						printf("%s", buffer);
						memset(buffer, 0, sizeof(buffer));
					}
				}
			}
			else
			{
				printf("%s is not a regular file\n", entry->d_name);
			}
		}
		else
		{
			printf("Unable to open %s file\n", entry->d_name);
		}
		close(fd);
		printf("============================\n");
	}
	close(fd1);
	return 0;
}