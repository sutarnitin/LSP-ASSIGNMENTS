//2.write a program which create three level process hierarchy where process1 creates process2 
//  and it internally creates process3.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int ret = 0, cpid = 0, Exit_status = 0;
	
	ret = fork();
	if(ret == 0)
	{
		execl("./process", NULL);
	}
	else
	{
		printf("child[1] id is %d & parent id is : %d \n", getpid(), getppid());
		cpid = wait(&Exit_status);
	}
	
	return 0;
}



//output
/*
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ gcc AssignmentEight2.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ ./exe 
child[1] id is 8245 & parent id is : 3968 
child[2] id is: 8246 & parent id is : 8245
child[3] id is: 8247 & parent id is : 8246
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ 

*/