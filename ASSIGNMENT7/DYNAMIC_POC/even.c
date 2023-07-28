#include<stdio.h>
#include"even.h"

void Even(int iNo)
{
		int iAns = 0, i = 0;
		
		printf("Even numbers are\n:");
		for(int i = 1; i <= iNo; i++)
		{
			if(i % 2 == 0)
			{
				printf("%d\n", i);
			}
		}
		
}