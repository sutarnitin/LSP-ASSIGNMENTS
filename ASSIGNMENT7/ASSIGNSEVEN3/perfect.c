#include<stdio.h>

void CheckPerfect(int iNo)
{
	int add = 0, i = 0;
	for(i = 1; i <= iNo/2; i++)
	{
		if((iNo % i) == 0)
		{
			add = add + i;
		}
	}
	if(iNo == add)
	{
		printf("The number %d is perfect", iNo);
	}else
	{
			printf("The number %d is not a perfect", iNo);
	}
}
