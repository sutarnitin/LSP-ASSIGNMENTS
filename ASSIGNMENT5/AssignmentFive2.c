//2. Write a program which accept file name from user which contains information of employee, we have to read all contents of that file.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    char fname[20];
    int fd = 0, cnt=0, ret=0;
	char ch[1]={'\0'};
	 if(argc != 2)
	{
		 printf("Insufficient arguments\n");
		 return -1;
	}
	
    fd = open(argv[1],O_RDONLY);
	printf("Student Information:\n");
	printf("Roll No:\t");
	
	while((ret = read(fd,ch,sizeof(ch))) != 0)
	{
		
		if(ch[0]=='\n')
		{
			cnt +=1;
			if(cnt ==1)
			{
				printf("\nMarks:\t");
			}
			else if(cnt==2){
				printf("\nAge:\t");
			}
			else{
				printf("\nName:\t");
			}
			
			continue;
		}
		else
		{
			printf("%s", ch);
		}
		 memset(ch, 0, sizeof(ch));
	}
	printf("\n");
    close(fd);

    return 0;
}

/*output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ gcc AssignmentFive2.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ ./myexe employee.txt 
Student Information:
Roll No:	12345
Marks:	100
Age:	25
Name:	Nitin
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ 
*/