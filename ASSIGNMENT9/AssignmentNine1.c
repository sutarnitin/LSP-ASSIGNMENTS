// 1. Write a program in which creates new process which is responsible to write all file names which are present on desktop
   // in demo file which should be created newly.
   
   
 #include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>
 #include<fcntl.h>
 
 int main()
 {
	 int iRet = 0, status = 0;
	 
	 iRet = fork();
	 
	 if(iRet == 0)
	 {
		 execl("./DisplayFileNames", NULL);
	 }
	 else
	 {
		printf("The running process id is: %d \n", getpid());
	 }
	 
	 wait(&status);
	 return 0;
 }
 
 
 //output
 /*
 nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT9$ gcc AssignmentNine1.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT9$ ./exe 
LSP
..
hello.txt
.
The running process id is: 5073
*/