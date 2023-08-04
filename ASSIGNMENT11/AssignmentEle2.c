//2. Write a program which creates multiple thread and sets its thread attributes accordingly.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#define _UNIX03_THREADS

void * ThreadProcMain(void *ptr)
{
	printf("hello from the thread\n");                                           
	pthread_exit(NULL);
}

void * ThreadProcFirst(void *ptr)
{
	printf("hello from the thread\n");                                           
    pthread_exit(NULL);
}

void * ThreadProcSecond(void *ptr)
{
	printf("hello from the thread\n");                                           
	pthread_exit(NULL);
}

int main()
{
	pthread_t TID1;
	pthread_t TID2;
	pthread_t TID3;
	int ret1 = 0, ret2 = 0, ret3 = 0, rc1 = 0, rc2 = 0, rc3 = 0, status1 = 0, status2 = 0, status3 = 0;
	
	pthread_attr_t attr1;    
	pthread_attr_t attr2;    
	pthread_attr_t attr3;    
	
	rc1 = pthread_attr_init(&attr1);                                               
   if (rc1 == -1) {                                                              
      perror("error in pthread_attr_init");                                     
      exit(1);                                                                  
   } 
	ret1 = pthread_create(&TID1, &attr1, ThreadProcMain, NULL);		   
	if(ret1 != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	printf("Thread is created with ID: %d\n", TID1);
	
	rc2 = pthread_attr_init(&attr2);                                               
   if (rc2 == -1) {                                                              
      perror("error in pthread_attr_init");                                     
      exit(1);                                                                  
   } 
	ret2 = pthread_create(&TID2, &attr2, ThreadProcFirst, NULL);		   
	if(ret2 != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	printf("Thread is created with ID: %d\n", TID2);
	rc2 = pthread_join(TID2, (void *)&status2);
	printf("End of first thread\n");
	
	rc3 = pthread_attr_init(&attr3);                                               
   if (rc3 == -1) {                                                              
      perror("error in pthread_attr_init");                                     
      exit(1);                                                                  
   } 
	ret3 = pthread_create(&TID3, &attr3, ThreadProcSecond, NULL);		   
	if(ret3 != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	printf("Thread is created with ID: %d\n", TID3);
	rc1 = pthread_join(TID3, (void *)&status2);
	printf("End of third thread\n");
	
	rc1 = pthread_join(TID1, (void *)&status1);
	printf("End of main thread\n");
	
	return 0;
}

//output
/*
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT11$ gcc AssignmentEle2.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT11$ ./exe 
Thread is created with ID: -530581824
hello from the thread
Thread is created with ID: -538974528
hello from the thread
End of first thread
Thread is created with ID: -538974528
hello from the thread
End of third thread
End of main thread
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT11$ 
*/