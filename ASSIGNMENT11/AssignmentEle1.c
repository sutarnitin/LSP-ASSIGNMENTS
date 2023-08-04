//1.  Write a program which creates 4 number of threads and our main thread waits till all the thread terminates.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProcMain(void *ptr)
{
	printf("Insid Main Thread \n");
}

void * ThreadProcFirst(void *ptr)
{
	printf("Insid First Thread \n");
}

void * ThreadProcSecond(void *ptr)
{
	printf("Insid Second Thread \n");
}

int main()
{
	pthread_t TID1;
	pthread_t TID2;
	pthread_t TID3;
	int ret1 = 0, ret2 = 0, ret3 = 0;
	
	ret1 = pthread_create(&TID1, NULL, ThreadProcMain, NULL);		   
	if(ret1 != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	printf("Thread is created with ID: %d\n", TID1);
	
	ret2 = pthread_create(&TID2, NULL, ThreadProcFirst, NULL);		   
	if(ret2 != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	printf("Thread is created with ID: %d\n", TID2);
	pthread_join(TID2, NULL);
	printf("End of first thread\n");
	
	ret3 = pthread_create(&TID3, NULL, ThreadProcSecond, NULL);		   
	if(ret3 != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	printf("Thread is created with ID: %d\n", TID3);
	pthread_join(TID3, NULL);
	printf("End of third thread\n");
	
	pthread_join(TID1, NULL);
	printf("End of main thread\n");
	
	return 0;
}


//Output
/*
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT11$ gcc AssignmentEle1.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT11$ ./exe 
Thread is created with ID: -213911872
Insid Main Thread 
Thread is created with ID: -222304576
Insid First Thread 
End of first thread
Thread is created with ID: -222304576
Insid Second Thread 
End of third thread
End of main thread

*/