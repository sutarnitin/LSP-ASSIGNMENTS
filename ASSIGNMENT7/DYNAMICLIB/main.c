#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
//#include"shared.h"

int main()
{
    void *ptr = NULL;
    void (*fptr)(int n);
	
    ptr = dlopen("use2.so", RTLD_LAZY);
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

	printf("Welcome\n");
    fptr(10);
    return 0;
}


// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/DYNAMICLIB$ gcc -c -fpic shared.c
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/DYNAMICLIB$ ls
// main.c  shared.c  shared.h  shared.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/DYNAMICLIB$ gcc shared.o -shared -o use2.so
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/DYNAMICLIB$ gcc -c main.c -o main.o 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/DYNAMICLIB$ gcc -o main main.o -L use2.so 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/DYNAMICLIB$ ./main 
// Unable to load liabrary
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/DYNAMICLIB$ sudo cp use2.so /usr/lib
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/DYNAMICLIB$ ./main 
// Welcome
// Jay Ganeshhhh 10...
 // nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/DYNAMICLIB$ 

