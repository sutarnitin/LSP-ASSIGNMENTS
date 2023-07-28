#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>	

int main()
{
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
	
	fptr(11);
	
    return 0;
}



