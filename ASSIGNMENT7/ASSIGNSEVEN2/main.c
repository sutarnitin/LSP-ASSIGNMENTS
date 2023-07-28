#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc, char *argv[])
{
	void *ptr = NULL;
    int (*fptr)(char *file1, char *file2);
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
    ptr = dlopen("lib_fileOperation.so",RTLD_LAZY);
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


// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ gcc -c -fpic CompaireFile.c -w
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ ls
// CompaireFile.c  CompaireFile.o  Demo.txt  file.h  hello.txt  main.c
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ gcc CompaireFile.o -shared -o lib_fileOperation.so
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ gcc -c main.c -o main.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ gcc -o main main.o -L lib_fileOperation.so 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ sudo cp lib_fileOperation.so /usr/lib
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ ./main hello.txt Demo.txt 
// Size are same.
// Two files have equal contents
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN2$ 
