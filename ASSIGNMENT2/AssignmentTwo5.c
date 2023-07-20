//5. Write a program which accept directory name from user and print name of such a file having largest size.

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
    int iMax = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    };

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(iMax < sobj.st_size)
            {
                iMax = sobj.st_size;
                strcpy(namecopy,name);
            }
        }
    }

    printf("Largest file is : %s with size %d bytes \n",namecopy,iMax);

    closedir(dp);
    
    return 0;
}

//output:
 // nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ gcc AssignmentTwo5.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ ./myexe MYFILES
// Largest file is : MYFILES/AssignmentTwo1.c with size 1639 bytes 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT2$ 