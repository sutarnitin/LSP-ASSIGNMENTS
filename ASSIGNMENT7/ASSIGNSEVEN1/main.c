#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    void (*fptr)();

	printf("**************\n");
    ptr = dlopen("lib_first.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"Addition");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr(10, 20);
    return 0;
}

// //
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ gcc -c -fpic Addition.c Subtraction.c Multiplication.c 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ gcc -o lib_first.so -shared -fpic *.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ ls
// Addition.c  Addition.o  AssignmentSeven1.h  lib_first.so  main.c  Multiplication.c  Multiplication.o  Subtraction.c  Subtraction.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ gcc -rdynamic -o myexe main.c 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ gcc -ldl -o myexe main.c 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ ./myexe 
// **************
// Unable to load liabrary
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ gcc -c main.c -o main.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ gcc -o main main.o -L lib_first.so 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ ./main 
// **************
// Unable to load liabrary
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ ls
// Addition.c  Addition.o  AssignmentSeven1.h  lib_first.so  main  main.c  main.o  Multiplication.c  Multiplication.o  myexe  Subtraction.c  Subtraction.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ ./myexe 
// **************
// Unable to load liabrary
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ 