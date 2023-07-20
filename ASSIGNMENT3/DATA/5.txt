//3. Write a program which accept two directory names from user and move all files from source directory to destination directory.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char oldname[50];
    char newname[50];
    int iCnt = 1;
    
    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(oldname,"%s/%s",argv[1],entry->d_name);
		printf("a***", entry->d_name);
        sprintf(newname,"%s/%d.txt",argv[2],iCnt);

        rename(oldname,newname);
        iCnt++;
    }

    closedir(dp);
    return 0;
}



//output:
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ gcc AssignmentThree3.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ ./myexe DATA MYFILES
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ cd DATA/
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/DATA$ ls
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/DATA$ cd ..
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ cd MYFILES
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ ls
// 1.txt  3.txt  4.txt  5.txt  6.txt
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/MYFILES$ 



//sprintf stands for "string print". In C programming language, it is a file handling function that is used to send formatted output to the
// string. Instead of printing on console, sprintf() function stores the output on char buffer that is specified in sprintf.