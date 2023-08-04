//1.  Write a program which is used to create the simple thread by using pthread library.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
	printf("Jay Ganesha...\n");
}

int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID, NULL, ThreadProc, NULL);

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread is created with ID : %d\n", TID);

    return 0;
}


//output
/*
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT10$ gcc AssignmentTen1.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT10$ ./exe 
Thread is created with ID : 685766336
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT10$ 



nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT10$ gcc AssignmentTen1.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT10$ ./exe 
Thread is created with ID : 1853880000
Jay Ganesha...
Jay Ganesha...
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT10$ 

*/