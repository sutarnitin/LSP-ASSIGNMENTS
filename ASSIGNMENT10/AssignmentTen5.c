//5. Write a program which is used to get thread id inside thread function.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

//pthread_t pthread_self(void);
void * ThreadProc(void *ptr)
{
	    printf("In thread function \nthread id = %d\n", pthread_self());
		pthread_exit(NULL);
}

int main()
{
	pthread_t TID;
	int ret = 0;
	
	ret = pthread_create(&TID,  NULL, ThreadProc, NULL);

	if(ret != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread is created in main thread with ID: %d\n", TID);
	
	pthread_join(TID, NULL);
	
	return 0;
}


//output
/*
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT10$ gcc AssignmentTen5.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT10$ ./exe 
Thread is created in main thread with ID: -1193281856
In thread function 
thread id = -1193281856
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT10$ 




Information
pthread_self - obtain ID of the calling thread


*/
