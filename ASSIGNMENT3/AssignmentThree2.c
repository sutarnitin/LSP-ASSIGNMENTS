//2. Write a program which accept directory name and file name from user and check whether that file is present in that directory or not.

#include<stdio.h>;
#include<stdlib.h>;
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
	int fd = 0;
    DIR *dp = NULL;
    struct dirent * entry = NULL;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
	
	// while((entry = readdir(dp)) != NULL)
    // {
		// fd = open(argv[2], O_RDONLY);
		// if(fd == -1)
		// {
			// printf("File is not present\n");
		// }else{
			// printf("File is present\n");
			// break;
		// }
		// close(fd);
    // }

    while((entry = readdir(dp)) != NULL)
    {

        if((strcmp(argv[2], entry->d_name)) == 0)
        {
            printf("File is present in directory\n");
            break;
        }
    }

    if(entry == NULL)
    {
        printf("There is no such file\n");
        return -1;
    }
    closedir(dp);
	
    return 0;
	
}


//output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ gcc AssignmentThree2.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ ./myexe MYFILES Hello.txt 
// File is present
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ 
