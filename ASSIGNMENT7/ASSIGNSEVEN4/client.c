#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>	


int Display(int num)
{
	printf("We are calculating the factorial %d\n", num);
	
	void *ptr = NULL;
    void (*fptr)(int iNo);

    ptr = dlopen("lib_factorial.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
	
    fptr = dlsym(ptr,"CalculateFactorial");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
	
	fptr(num);
	
    return 0;
}
