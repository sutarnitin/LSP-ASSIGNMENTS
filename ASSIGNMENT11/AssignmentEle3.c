//	3. Write a program which is used to predict the problem due to lack of synchronization.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
  
pthread_t tid[2];
int iCnt;
  
void* threadProcess(void* arg)
{
    unsigned long i = 0;
    iCnt = iCnt + 1;
    printf("\n process %d has started\n", iCnt);
  
    for (i = 0; i < (0xFFFFFFFF); i++)   //Hexadecimal number 4294967295
        ;
    printf("\n process %d has finished\n", iCnt);
  
    return NULL;
}
  
int main(void)
{
    int i = 0;
    int error;
  
    while (i < 2) {
        error = pthread_create(&(tid[i]), NULL, &threadProcess, NULL);
        if (error != 0)
            printf("\nThread can't be created : [%s]", strerror(error));
        i++;
    }
  
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
  
    return 0;
}




//output

/*
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT11$ gcc AssignmentEle3.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT11$ ./exe 

 process 1 has started

 process 2 has started

 process 2 has finished

 process 2 has finished
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT11$ 

*/
