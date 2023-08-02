#include<stdio.h>
#include<stdlib.h>	
#include<unistd.h>	

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Insufficient Arguments\n");
	}
	
	printf("\nNumber of arguments %d\n", argc);
	printf("First parameter %d\n", atoi(argv[1]));
	printf("Second parameter %d\n", atoi(argv[2]));
	
	int iAns = 0;
	
	iAns  = atoi(argv[1]) - atoi(argv[2]);
	
	printf("Subtraction is: %d\n", iAns);
	
	return 0;
}