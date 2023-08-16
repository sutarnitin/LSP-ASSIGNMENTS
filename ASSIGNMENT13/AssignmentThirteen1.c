//1. Write a program which creates two processes as a reader and writer and that processes should communicate with each other using FIFO.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	//char *arr = "This is the process which communicate with each other using FIFO";
	int fd = 0;
	char buf1[100], buf2[100];
	
	char * myfifo = "mypipe";
	
	mkfifo(myfifo, 0666);
	
	 while (1)
     {
		fd = open("mypipe",  O_WRONLY );
		if(fd == -1)
		{
			printf("Unable to open file\n");
			return -1;
		}
	
		fgets(buf2, 100, stdin);
	
		write(fd, buf2, strlen(buf2));
	//	printf("Data Successfully written into the file\n");
		close(fd);
		
		 // Open FIFO for Read only
		 fd = open(myfifo, O_RDONLY);
		 read(fd, buf1, sizeof(buf1));
		 printf("Client: %s\n", buf1);
        close(fd);
	}
	
	return 0;
}


//Output

// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT13$ ./Server 
// Hello
// Client: 


// Client: Hey

// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT13$ gcc AssignmentThirteenClient1.c -o Client
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT13$ ./Client 

// Server: Hello

// Hey
// Server: 
// ello
