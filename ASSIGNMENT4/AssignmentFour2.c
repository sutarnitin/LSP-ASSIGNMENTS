//2. Write a program which accept directory name from user and create new directory of that name.

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	
	struct stat st = {0};
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	if (stat(argv[1], &st) == -1) {
		mkdir(argv[1], 0700);
		printf("%s directory created\n", argv[1]);
	}
	
    return 0;
}


/*output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ ls
abc.txt          AssignmentFour1.c  AssignmentFour3.c  AssignmentFour5.c  hello.txt  myDir  output.txt       que4output1.txtclear
Assignment4.txt  AssignmentFour2.c  AssignmentFour4.c  demo.txt           input.txt  myexe  que4output1.txt  que4output.txt
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ gcc AssignmentFour2.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ ./myexe testdir
testdir directory created
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ ls
abc.txt          AssignmentFour1.c  AssignmentFour3.c  AssignmentFour5.c  hello.txt  myDir  output.txt       que4output1.txtclear  testdir
Assignment4.txt  AssignmentFour2.c  AssignmentFour4.c  demo.txt           input.txt  myexe  que4output1.txt  que4output.txt
*/