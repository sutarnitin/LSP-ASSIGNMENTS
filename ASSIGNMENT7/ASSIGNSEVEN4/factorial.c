#include<stdio.h>

void CalculateFactorial(int iNo)
{
	int iFact = 1;
	
	for(int i = iNo; i > 0; i--)
	{
		iFact = iFact * i;
	}
	
	printf("Factorial of the given number is: %d:\n", iFact);
	
	
}

// int main(int agc, char *argv[])
// {
	// int iValue = 5;
	// CalculateFactorial(iValue);
	// return 0;
// }