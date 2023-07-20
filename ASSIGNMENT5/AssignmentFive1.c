//1. Write a program which writes structure in file. structure should contains information of student.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

struct student
{
	int age;
	char name;
	int rollNo;
	float marks;
};

int main(int argc, char *argv)
{
	struct student sobj;
	int fd = 0;
    char fname[20];

    printf("Enter the file name : \n");
    scanf("%s", &fname);
	// if(argc != 2)
	// {
		// printf("Insufficient arguments\n");
		// return -1;
	// }
	
	fd =creat(fname, 0777);
	if(fd == -1)
	{
		printf("Unable to open file with fd %d\n", fd);
		return -1;
	}
	printf("Enter roll no:\n ");
	scanf("%d", &sobj.rollNo);
	printf("Enter student name:\n");
    scanf("%s", &sobj.name);
	printf("Enter marks:\n ");
    scanf("%f", &sobj.marks);
	printf("Enter age:\n ");
    scanf("%d", &sobj.age);
	
	write(fd, &sobj, sizeof(struct student));
	
	close(fd);
	
	return 0;
	
}
