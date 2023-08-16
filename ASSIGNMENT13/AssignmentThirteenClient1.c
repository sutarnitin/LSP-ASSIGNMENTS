//Client

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = 0;
	char buf1[100],  buf2[100];
	
	char * myfifo = "mypipe";
	mkfifo(myfifo, 0666);
	
	while(1)
	{
		fd = open(myfifo,  O_RDONLY);
		if(fd == -1)
		{
			printf("Unable to open file\n");
			return -1;
		}
	
		read(fd, buf1, 100);
		printf ( "Server: %s\n", buf1); 
		close(fd);
		
		fd = open(myfifo, O_WRONLY);
        fgets(buf2, 100, stdin);
        write(fd, buf2, strlen(buf2)+1);
        close(fd);
	}
	return 0;
}

//Output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT13$ ./Client 
// Server: 
// Hello

// Hey
