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
    char size_of_file[50]={'\0'};
	char length_of_file_name[50]={'\0'};
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
			
				sprintf(length_of_file_name, "%d", strlen(entry->d_name));
				printf("Write %s size of %s file into %s\n", length_of_file_name, entry->d_name, argv[2]);
				write(dest_fd, length_of_file_name, strlen(length_of_file_name));
				
				printf("Write %s filename into %s\n", entry->d_name, argv[2]);
				write(dest_fd, entry->d_name, strlen(entry->d_name));
				
				sprintf(size_of_file, "%d", sobj.st_size);
				printf("Write %s file size %s file into %s\n", size_of_file, entry->d_name, argv[2]);
				write(dest_fd, size_of_file, strlen(size_of_file));
				
				printf("Write data of %s into %s file\n",  entry->d_name, argv[2]);
				while((ret = read(fd, buffer, sizeof(buffer))) != 0)
				{
					write(dest_fd, buffer, ret);
					memset(buffer, 0, sizeof(buffer));
				}
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
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ ./myexe  QUE4_DATA all_combined.txt
.. is not a regular file
============================
File : f2.txt 
size: 1767
Write 6 size of f2.txt file into all_combined.txt
Write f2.txt filename into all_combined.txt
Write 1767 file size f2.txt file into all_combined.txt
Write data of f2.txt into all_combined.txt file
============================
File : hello.txt 
size: 216
Write 9 size of hello.txt file into all_combined.txt
Write hello.txt filename into all_combined.txt
Write 216 file size hello.txt file into all_combined.txt
Write data of hello.txt into all_combined.txt file
============================
. is not a regular file
============================
File : f1.txt 
size: 1312
Write 6 size of f1.txt file into all_combined.txt
Write f1.txt filename into all_combined.txt
Write 1312 file size f1.txt file into all_combined.txt
Write data of f1.txt into all_combined.txt file
============================
Successfully write all file data into all_combined.txt file 
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ 
*/
