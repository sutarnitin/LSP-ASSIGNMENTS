//4. Write a program which creates two processes as addition and subtraction and our parent process terminates till both 
//  the process terminates.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int ret1 = 0, ret2 = 0;
	int status1 = 0, status2 = 0;
	
	ret1 = fork();
	if(ret1 != 0)
	{
		execl("./addition", "Addition", "10", "20", NULL);
	}
	
	wait(&status1);
	
	ret2 = fork();
	if(ret2 != 0)
	{
		execl("./subtraction", "Subtraction", "20", "10", NULL);
	}
	wait(&status2);

	return 0;
}


//output
/*
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ gcc AssignmentEight4.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ ./exe 
Number of arguments 3
First parameter 10
Second parameter 20
Addition is: 30

Number of arguments 3
First parameter 20
Second parameter 10
Subtraction is: 10
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ 
*/