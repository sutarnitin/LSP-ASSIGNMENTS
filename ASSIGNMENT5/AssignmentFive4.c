//4. Write a program which  accept directory name from user and combine all contains of file from that directory into one
//    file named as All Combine.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
	int fd=0, dest_fd=0, ret=0;
    char size_of_file[50];
	DIR *dp = NULL;
	char *path = NULL;
	struct stat sobj;
	struct dirent *entry = NULL;
	char buffer[BLOCKSIZE] = {'\0'};
	
	if(argc != 3)
	{
		printf("insufficient arguments\n");
		return -1;
	}
	
	dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open %s directory\n", argv[1]);
        return -1;
    }
	
	dest_fd = creat(argv[2], 0777);
    if(dest_fd == -1)
    {
        printf("Unable to create %s destination file\n", argv[2]);
        return -1;
    }
	
	while((entry = readdir(dp)) != NULL)
	{
		path = malloc(strlen(argv[1])+strlen(entry->d_name)+1);
		sprintf(path,"%s/%s", argv[1], entry->d_name);
		stat(path, &sobj);
		if(S_ISREG(sobj.st_mode) && (sobj.st_size!=0))
		{
			fd = open(path, O_RDONLY);
			if(fd == -1)
			{
				printf("1. Unable to open file %s\n", entry->d_name);
			}
			else
			{
				printf("File : %s \n", entry->d_name);
				printf("size: %d\n",sobj.st_size);
				sprintf(size_of_file, "%d", sobj.st_size);
				write(dest_fd, entry->d_name, strlen(entry->d_name));
				write(dest_fd, size_of_file, strlen(size_of_file));
				while((ret = read(fd, buffer, sizeof(buffer))) != 0)
				{
					write(dest_fd, buffer, ret);
					memset(buffer, 0, sizeof(buffer));
				}
				printf("Successfully written all the data from %s file into %s file \n", entry->d_name, argv[2]);
			}
			close(fd);
		}
		else
		{
			printf("%s is not a regular file\n", entry->d_name);
		}
		printf("============================\n");
	}
	close(dest_fd);
	printf("Successfully write all file data into %s file \n", argv[2]);
	return 0;
}


/*output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ gcc AssignmentFive4.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ ./myexe que3_test_dir all_combined.txt
.. is not a regular file
============================
File : Hello.txt 
size: 1338
Successfully written all the data from Hello.txt file into all_combined.txt file 
============================
File : Demo.txt 
size: 1338
Successfully written all the data from Demo.txt file into all_combined.txt file 
============================
. is not a regular file
============================
Successfully write all file data into all_combined.txt file 
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ 
*/
