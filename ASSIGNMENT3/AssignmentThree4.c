//4. Write a program which accept directory name from user and delete all empty files from that directory.

#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>

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
        printf("Unable to open %s directory\n", argv[1]);
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
				printf("Succeesfully removed %s empty file from %s directory.\n", entry-> d_name, argv[1]);
            }
        }
    }

    closedir(dp);
    
    return 0;
}


/*output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ gcc AssignmentThree4.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ cd MYFILES/
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ ls
a.txt  empty.txt
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ cd ..
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ ./myexe MYFILES
Succeesfully removed empty.txt empty file from MYFILES directory.
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ cd MYFILES/
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ ls
a.txt
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ 
*/