#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>	

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
	}
	
    void *ptr = NULL;
    int (*fptr)(int num);

    ptr = dlopen("lib_client.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
	
    fptr = dlsym(ptr,"Display");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
	
	fptr(atoi(argv[1]));
	
    return 0;
}



