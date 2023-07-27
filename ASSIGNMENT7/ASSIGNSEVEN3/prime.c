#include<stdio.h>
#include <stdbool.h>
#include"prime.h"


bool CheckPrime(int iNo)
{
	bool bflag = false;
	int i = 0;

	for(i = 2; i <= iNo/2; i++)
	{
		if(iNo % i == 0)
		{
			bflag = false;
			break;
		}
	}
	if(i > iNo/2){
		bflag = true;
	}
	return bflag;
}


// int main()
// {
	
	// bool b = false;
	// b = CheckPrime(2);
	// if(b == true)
	// {
		// printf("prime\n");
	// }else{
		// printf("not prime\n");
	// }
	
// }


//ouput
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -c -fpic prime.c perfect.c 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ ls
// AssignmentSeven3.c  main.c  perfect.c  perfect.o  prime.c  prime.h  prime.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -o lib_prime.so -shared -fpic prime.o
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -rdynamic -o exe main.c 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ gcc -ldl -o exe main.c 
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ ./exe 
// **************
// Unable to load liabrary
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT7/ASSIGNSEVEN3$ 

