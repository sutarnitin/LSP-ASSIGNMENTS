//2. Write a program which creates two processes and that two processes can communicate with each other by using concept of shared memory.

//Server

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include <sys/shm.h>

int main()
{
    int shmid = 0;
    int shmsize = 100;
    int key = 1234;
    char *ptr = NULL;

    printf("Server application running...\n");

    shmid = shmget(key,shmsize,IPC_CREAT | 0666);

    printf("Shared memory allocated succesfully...\n");

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("Shared memory atached succesfully...\n");
    }
	
	*ptr = 'J';
	 ptr++;
	 
	 *ptr = 'A';
	 ptr++;
	 
	 *ptr = 'Y';
	 ptr++;
	 
	 *ptr = 'G';
	 ptr++;	

	 *ptr = 'A';
	 ptr++;
	 
	 *ptr = 'N';
	 ptr++;	

	 *ptr = 'S';
	 ptr++;	 
	 
	 *ptr = 'H';
	 ptr++;
	
	*ptr = '\0';
	 ptr++;
	
	printf("Data Written in shared memory Successfully...\n");
    
    return 0;
}

//Output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ gcc AssignmentTwelve2.c -o Server
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ ./Server 
// Server application running...
// Shared memory allocated succesfully...
// Shared memory atached succesfully...
// Data Written in shared memory Successfully...


// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ gcc AssignmentTwelveClient2.c -o Client 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ ./Client 
// Client application running...
// Shared memory allocated succesfully...
// Shared memory attached succesfully...
// Data from shared memory is : 
// JAYGANSH
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ 
