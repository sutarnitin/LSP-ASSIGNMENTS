//1. Write a program which writes structure in file. structure should contains information of student.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

struct student
{
	int age;
	int rollNo;
	float marks;
	char *name;
};

int main(int argc, char *argv)
{
	struct student sobj;
	struct student sobj2;
	int fd = 0, ret =0, limit=0, fd1=0;
    char fname[20];

    printf("Enter the file name :\t");
    scanf("%s", &fname);
	
	fd =creat(fname, 0777);
	if(fd == -1)
	{
		printf("Unable to open file with fd %d\n", fd);
		return -1;
	}
	printf("\nEnter maximum length of name: \t");
    scanf("%d", &limit);

    //allocate memory dynamically
    sobj.name = (char*)malloc(limit * sizeof(char));

	printf("\nEnter student name:\t");
    scanf("%s", sobj.name);
	
	printf("\n Enter roll no:\t");
	scanf("%d", &sobj.rollNo);
	
	printf("\n Enter marks:\t ");
    scanf("%f", &sobj.marks);
	
	printf("\nEnter age:\t ");
    scanf("%d", &sobj.age);
	
	write(fd, &sobj, sizeof(sobj));
	close(fd);
	
	fd1 = open(fname, O_RDONLY);
	if(fd1 == -1)
	{
		printf("Unable to open %s file\n", fname);
		return -1;
	}
	
	ret = read(fd1, &sobj2, sizeof(sobj2));
	if(ret !=0)
	{
		printf("Student Information: \n");
		printf("Name: %s\n", sobj2.name);
		printf("Roll no: %d\n", sobj2.rollNo);
		printf("Age: %d\n", sobj2.age);
		printf("Marks: %f\n", sobj2.marks);
		
		
	}
	close(fd1);
	return 0;
	
}

/* Output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ gcc AssignmentFive1.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$ ./myexe
Enter the file name :	que1_student.txt             

Enter maximum length of name: 	5

Enter student name:	Nitin

 Enter roll no:	25

 Enter marks:	 99

Enter age:	 27
Student Information: 
Name: Nitin
Roll no: 25
Age: 27
Marks: 99.000000
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT5$
*/