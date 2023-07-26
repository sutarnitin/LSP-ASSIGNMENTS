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
        printf("Unable to open %s directory\n", argv[1]);
        return -1;
    }
	
	while((entry = readdir(dp)) != NULL)
    {

        if((strcmp(argv[2], entry->d_name)) == 0)
        {
            printf("%s file is present in %s directory\n", argv[2], argv[1]);
            break;
        }
    }

    if(entry == NULL)
    {
        printf("There is no such %s file present in %s directory\n", argv[2], argv[1]);
        return -1;
    }
    closedir(dp);
	
    return 0;
	
}


/*output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ gcc AssignmentThree2.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ ./myexe MYFILES a.txt
a.txt file is present in MYFILES directory
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ ./myexe MYFILES Hello.txt 
There is no such Hello.txt file present in MYFILES directory
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$
*/