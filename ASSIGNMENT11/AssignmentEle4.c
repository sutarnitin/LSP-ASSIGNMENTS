//4. Write a program which creates two threads and by using appropriate synchronization technique avoid the scheduling probolem.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
  
pthread_t tid[2];
int counter;
pthread_mutex_t lock;
  
void* trythis(void* arg)
{
    pthread_mutex_lock(&lock);
  
    unsigned long i = 0;
    counter += 1;
    printf("\n process %d has started\n", counter);
  
    for (i = 0; i < (0xFFFFFFFF); i++)
        ;
  
    printf("\n process %d has finished\n", counter);
  
    pthread_mutex_unlock(&lock);
  
    return NULL;
}
  
int main(void)
{
    int i = 0;
    int error;
  
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }
  
    while (i < 2) {
        error = pthread_create(&(tid[i]), NULL,  &trythis, NULL);
        if (error != 0)
            printf("\nThread can't be created :[%s]", strerror(error));
        i++;
    }
  
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);
  
    return 0;
}

/* Output 
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT11$ gcc AssignmentEle4.c -o exe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT11$ ./exe 

 process 1 has started

 process 1 has finished

 process 2 has started

 process 2 has finished
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT11$
*/