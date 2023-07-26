//4. Write a program which accept directory name from user and print all the names and its types from that directory.

#include<stdio.h>;
#include<stdlib.h>;
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
	struct stat sobj;
    DIR *dp = NULL;
    struct dirent * entry = NULL;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open %s directory\n", argv[1]);
        return -1;
    }
	
	while((entry = readdir(dp)) != NULL)
    {
        printf("File name : %s\n",entry->d_name);
		stat(entry->d_name,&sobj);
		if(S_ISREG(sobj.st_mode))
		{
			printf("Its a regular file\n");
		}
		else if(S_ISDIR(sobj.st_mode))
		{
			printf("Its a directory\n");
		}
		else if(S_ISLNK(sobj.st_mode))
		{
			printf("Its a symbolic link\n");
		}
		printf("==================\n");
    }

    closedir(dp);
    return 0;
	
}


/*output:
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ gcc AssignmentTwo4.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ ./myexe MYFILES
File name : AssignmentTwo2.c
Its a regular file
==================
File name : ..
Its a directory
==================
File name : Assignment2.txt
Its a regular file
==================
File name : AssignmentTwo3.c
Its a regular file
==================
File name : .
Its a directory
==================
File name : AssignmentTwo1.c
Its a regular file
==================
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2
*/