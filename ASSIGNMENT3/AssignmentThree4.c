//4. Write a program which accept directory name from user and delete all empty files from that directory.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>za

int main(int argc, char *argv[])
{
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
   }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s", argv[1], entry->d_name);
        stat(name, &sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size == 0)
            {
                remove(name);
            }
        }
    }

    closedir(dp);
    
    return 0;
}


//output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ ls
// a.txt  b.txt  c.txt  d.txt
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ cd ..
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ gcc AssignmentThree4.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ ./myexe MYFILES
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ cd MYFILES/
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ ls
// a.txt
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ 
