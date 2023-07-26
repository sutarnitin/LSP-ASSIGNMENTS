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
    DIR *source = NULL;
	DIR *destination = NULL;
    struct dirent *entry = NULL;
    char *source_name= NULL;
    char *dest_name= NULL;
    
	if(argc != 3)
	{
		printf("insufficient Arguments\n");
		return -1;
	}
	
    source = opendir(argv[1]);
	destination = opendir(argv[2]);
    if(source == NULL)
    {
        printf("Unable to open %s directory\n", argv[1]);
        return -1;
    }

    while((entry = readdir(source)) != NULL)
    {
		source_name = malloc(strlen(argv[1])+strlen(entry->d_name)+1);
		dest_name = malloc(strlen(argv[2])+strlen(entry->d_name)+1);
        sprintf(source_name,"%s/%s",argv[1],entry->d_name);
        sprintf(dest_name,"%s/%s",argv[2],entry->d_name);
        rename(source_name,dest_name);
    }
	printf("Successfully move files from %s directory to %s directory\n", argv[1], argv[2]);

    closedir(source);
    closedir(destination);
    return 0;
}



/*output:
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ gcc AssignmentThree3.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ cd DATA
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/DATA$ ls
f1.txt  f2.txt  hello.txt
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/DATA$ cd ..
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ cd DESTINATION/
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/DESTINATION$ ls
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/DESTINATION$ cd ..
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ ./myexe DATA DESTINATION
Successfully move files from DATA directory to DESTINATION directory
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ cd DATA
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/DATA$ ls
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/DATA$ cd ..
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3$ cd DESTINATION/
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/DESTINATION$ ls
f1.txt  f2.txt  hello.txt
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT3/DESTINATION$
*/


//sprintf stands for "string print". In C programming language, it is a file handling function that is used to send formatted output to the
// string. Instead of printing on console, sprintf() function stores the output on char buffer that is specified in sprintf.