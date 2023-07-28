#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc, char *argv[])
{
	 void *ptr = NULL;
    void (*fptr)();
	
	printf("**************\n");
    ptr = dlopen("lib_numberproblem.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
	
	 fptr = dlsym(ptr,"Even");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
	
	fptr(10);
	
    return 0;
}