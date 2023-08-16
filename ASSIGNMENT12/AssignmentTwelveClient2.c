//2. Write a program which creates two processes and that two processes can communicate with each other by using concept of shared memory.
//Client for the shared memory

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
    int Key = 1234;
    char *ptr = NULL;

    printf("Client application running...\n");

    shmid = shmget(Key,shmsize, 0666);
	printf("Shared memory allocated succesfully...\n");

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("Shared memory attached succesfully...\n");
    }
	
	printf("Data from shared memory is : \n");
	while(*ptr != '\0')
	{
		printf("%c", *ptr);
		ptr++;
	}
	printf("\n");
	
    shmdt(shmid);
    return 0;
}



//Output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ gcc AssignmentTwelveClient2.c -o Client 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ ./Client 
// Client application running...
// Shared memory allocated succesfully...
// Shared memory attached succesfully...
// Data from shared memory is : 
// JAYGANSH
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ 
