//	4.  Write a program which map any file in memory and read the data from that mapped file.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
    int fd = 0;

    char *path = "Demo";
    
    fd = mkfifo(path,0666);
    if(fd == -1)
    {
        printf("Unable to create named pipe\n");
        return -1;
    }

    printf("Server is running and writing the data into named pipe...\n");
    fd = open(path,O_WRONLY);

    write(fd, "Jay Ganesh...", 10);

    close(fd);
    
    unlink(path);
    
    printf("Data succesfully written in the pipe\n");
    return 0;
}


//Output
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ gcc AssignmentTwelve4.c -o Server
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ ./Server 
// Server is running and writing the data into named pipe...
// Data succesfully written in the pipe
// nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT12$ 