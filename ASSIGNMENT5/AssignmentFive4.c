//4. Write a program which  accept directory name from user and combine all contains of file from that directory into one file named as All Combine.

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
	char buffer[20] = {'\0'},dir_name[strlen(argv[1])];
	char * temp;
    DIR *dp = NULL;
    
	memcpy(dir_name, argv[1], strlen(argv[1]));
	if(argc != 2)
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
	
	fd1 = open("allcombined.txt", O_CREAT|O_WRONLY, 0777);
    if(fd1 == -1)
    {
        printf("Unable to create destination file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
		asprintf(&temp, "%s%s", dir_name, entry->d_name);
		
		if(stat(temp, &sobj) ==0)
		{
			if(S_ISREG(sobj.st_mode) && (sobj.st_size!=0))
			{
				printf("File name : %s\n", entry->d_name);
				printf("File size is : %d\n", sobj.st_size);
				fd = open(temp, O_RDONLY);
				
				if(fd == -1)
				{
					printf("1. Unable to open file %s\n", entry->d_name);
				}
				else
				{
					while((ret = read(fd,buffer,sizeof(buffer))) != 0)
					{
						printf("Writing %s\n", buffer);
						write(fd1, buffer, sizeof(buffer));
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
}

//output

/* nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ ./myexe /home/nitin/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5/que3/
File name : demo.txt
File size is : 4
Number of links : 1
Inode number : 1853166
File system number : 2055
Number of blocks : 8
User Id : 1000
Group Id : 1000
Block Size: 4096
abc
============================
.. is not a regular file
============================
File name : hello.txt
File size is : 4
Number of links : 1
Inode number : 1853167
File system number : 2055
Number of blocks : 8
User Id : 1000
Group Id : 1000
Block Size: 4096
abc
============================
File name : input.txt
File size is : 12
Number of links : 1
Inode number : 1853168
File system number : 2055
Number of blocks : 8
User Id : 1000
Group Id : 1000
Block Size: 4096
10
20
40
============================
. is not a regular file
============================
*/