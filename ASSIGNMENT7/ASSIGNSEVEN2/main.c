#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc, char *argv[])
{
	void *ptr = NULL;
    void (*fptr)();
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
    ptr = dlopen("lib_second.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
	
	fptr = dlsym(ptr,"CompaireFile");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr(argv[1], argv[2]);
	
    return 0;
	
}