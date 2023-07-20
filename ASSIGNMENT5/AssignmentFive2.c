//2. Write a program which accept file name from user which contains information of employee, we have to read all contents of that file.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct employee
{
    int empId;
    char ename[20];
	double salary;
    int age;
};

int main(int argc, char *argv[])
{
    struct employee eobj;
    char fname[20];
    int fd = 0;
	 if(argc != 2)
	{
		 printf("Insufficient arguments\n");
		 return -1;
	}
	
    fd = open(argv[1],O_RDONLY);
	

    read(fd,&eobj,sizeof(fname));
	//printf("1. %s", fname);
    printf("Employee ID : %d : \n",eobj.empId);
    printf("Employee Name : %s : \n",eobj.ename);
    printf("salary : %f : \n",eobj.salary);
    printf("age : %d : \n",eobj.age);

    close(fd);

    return 0;
}

//output

// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ gcc AssignmentFive2.c -o myexe -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ ./m
// mn.txt  myexe   
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ ./myexe < employee.txt 
// Enter the file name : 
// Roll number : 0 : 
// Name :  : 
// Marks : 0.000000 : 
// Age : 0 : 
