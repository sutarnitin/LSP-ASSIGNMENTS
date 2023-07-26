//4. Write a program which accept directory name from user and delete all such files whose size is greater than 100 bytes.

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
	int limit = atoi(argv[2]);
    
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    };

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open %s directory \n", argv[1]);
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
	
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size> limit)
            {
                remove(name);
				printf("Removed %s file from %s directory whose size %d is greater than %d byte \n" , entry->d_name, argv[1], sobj.st_size, limit);
            }
			else
			{
				printf("Not removed %s file from %s directory whose size %d is greater than %d byte \n" , entry->d_name, argv[1], sobj.st_size, limit);
            }
        }
    }

    closedir(dp);
    
    return 0;

}

/*output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT6$ gcc AssignmentSix4.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT6$ ./myexe Que4_Test_Folder 200
Removed que4_test1.txt file from Que4_Test_Folder directory whose size 721 is greater than 200 byte 
Not removed que4_test2.txt file from Que4_Test_Folder directory whose size 99 is greater than 200 byte 
Removed que4_test3.txt file from Que4_Test_Folder directory whose size 1441 is greater than 200 byte 
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT6$ cd Que4_Test_Folder
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT6/Que4_Test_Folder$ ls
que4_test2.txt
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT6/Que4_Test_Folder$ 
*/