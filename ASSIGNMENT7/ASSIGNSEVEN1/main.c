#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)(int iNo1, int iNo2);
    int (*fptr2)(int iNo1, int iNo2);
    int (*fptr3)(int iNo1, int iNo2);
	int ret = 0, ret2 = 0, ret3 = 0;

    ptr = dlopen("lib_number.so",RTLD_LAZY);
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

   ret =  fptr(10, 20);
   printf("Addition is: %d\n", ret);
   
    fptr2 = dlsym(ptr,"Subtraction");
    if(fptr2 == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

   ret2 =  fptr2(10, 20);
   printf("Subtraction is: %d\n", ret2); 
   
   
   fptr3 = dlsym(ptr,"Multiplication");
    if(fptr3 == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

   ret3 =  fptr3(10, 20);
   printf("Multiplication is: %d\n", ret3);
    return 0;
}


// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ ls
// Addition.c  Addition.o  AssignmentSeven1.h  lib_number.so  main  main.c  main.o  Multiplication.c  Multiplication.o  Subtraction.c  Subtraction.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ gcc -c main.c -o main.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ gcc -o main main.o -L lib_number.so 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ ./main 
// Addition is 30
// Subtraction is -10
// Multiplication is 200
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN1$ 
