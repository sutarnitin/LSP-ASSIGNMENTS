//2.write a program which create three level process hierarchy where process1 creates process2 
//  and it internally creates process3.

//3. Wrire a program which creates three different processes internally as process2, process3, process4.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int pid = 0, pid1 = 0, pid2 = 0;
	pid = fork();
	
	if(pid == 0)
	{
		printf("1.Child process id is: %d and its parent process if is %d\n", getpid(), getppid());
	}
	else
	{
		pid1 =fork();
		
		if(pid1 == 0)
		{
			printf("2.Child process id is: %d and its parent process if is %d\n", getpid(), getppid());
		}
		else
		{
			pid2 =fork();
			if(pid2 == 0)
			{
			printf("3.Child process id is: %d and its parent process if is %d\n", getpid(), getppid());
			}
		}
		
	}
	
}



//output
/*
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ gcc AssignmentEight3.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ ./exe 
1.Child process id is: 8271 and its parent process if is 8270
2.Child process id is: 8272 and its parent process if is 8270
3.Child process id is: 8273 and its parent process if is 8270
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT8$ 
*/