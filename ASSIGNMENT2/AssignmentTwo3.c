// 3. Write a program which accept directory name from user and print all the file names from that directory.

#include<stdio.h>;
#include<stdlib.h>;
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
		
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
        printf("Unable to open directory\n");
        return -1;
    }
	
	while((entry = readdir(dp)) != NULL)
    {
        printf("%s\n",entry->d_name);
    }

    closedir(dp);
    return 0;
	
}

//Output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ gcc AssignmentTwo3.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ ./myexe MYFILES
// AssignmentTwo2.c
// ..
// Assignment2.txt
// AssignmentTwo3.c
// .
// AssignmentTwo1.c
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$