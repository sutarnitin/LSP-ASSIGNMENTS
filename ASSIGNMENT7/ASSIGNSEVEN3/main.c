#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>

int main()
{
    void *ptr = NULL;
    void *ptr2 = NULL;
    bool (*fptr)();
    void (*fptr2)();

	printf("**************\n");
    ptr = dlopen("lib_prime.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
	
    bool ret = fptr(11);
	if(ret)
	printf("prime\n");
	else
	printf("Not prime\n");
	
	ptr2 = dlopen("lib_perfect.so",RTLD_LAZY);
    if(ptr2 == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr2 = dlsym(ptr,"CheckPerfect");
    if(fptr2 == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
	
	fptr2(11);
	
    return 0;
}



// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -c -fpic prime.c perfect.c
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -o lib_prime -shared prime.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -o lib_perfect -shared perfect.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ ls
// lib_perfect  lib_prime  main.c  perfect.c  perfect.h  perfect.o  prime.c  prime.h  prime.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -rdynamic -o exe main.c 
// main.c: In function ‘main’:
// main.c:26:16: error: void value not ignored as it ought to be
   // 26 |     bool ret = fptr(11);
      // |                ^~~~
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -rdynamic -o exe main.c 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -ldl -o exe main.c 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ ./exe 
// **************
// Unable to load liabrary
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc main.c -o main.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ ls
// exe  lib_perfect  lib_prime  main.c  main.o  perfect.c  perfect.h  perfect.o  prime.c  prime.h  prime.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -o main main.o -L lib_prime
// /usr/bin/ld: cannot use executable file 'main.o' as input to a link
// collect2: error: ld returned 1 exit status
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -o main main.c -L lib_prime
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ ./main
// **************
// Unable to load liabrary
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$