//Send the array as a paramter to the thread process and find the sum of the array elelements

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void* arg)
{
	int *ptr = (int *) arg;
	int iSize = ptr[0];
	printf("size 1 of the array is: %d\n", iSize);
	
	int iSum=0;
	for(int i = 1;  i <= iSize; i++)
	{
		iSum = iSum + ptr[i];
		printf("Inside - %d\n", ptr[i]);
	}
	printf("Sum of the given array elements are: %d\n", iSum);
	//pthread_exit(++i);
}

int main()
{
	pthread_t TID;
	int ret = 0;
	int arr[4] = {3, 20, 30, 40};
	int value = 0;
	
	printf("Array elements: \n");
	for(int i = 0;  i <= 3; i++)
	{
		printf("values - %d\n", arr[i]);
	}
	ret = pthread_create(&TID, NULL, ThreadProc, &arr);
							   
	if(ret != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread is created with ID: %d\n", TID);
	
	pthread_join(TID, &value);
	//printf("Return value from thread is: %d\n", value);
	printf("End of main thread\n");
	
	return 0;
}



//output
/*


*/