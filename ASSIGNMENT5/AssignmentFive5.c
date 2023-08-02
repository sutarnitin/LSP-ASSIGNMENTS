//5. Write a program which accept file name which contains data of all file. we have to create all file again.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int fd = 0, fd1=0, ret=0;
	char ch[1]={'\0'};
	
	if(argc != 2)
	{
		printf("insufficient arguments\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("1. Unable to open file %s\n", argv[1]);
	}
	char file_name_size[10]={'\0'};
	int cnt=0;
	printf("ch1 %s\n", ch);
	while((ret = read(fd,ch,sizeof(ch))) != 0)
	{
		cnt+=1;
		//printf("leght of c %d and %s and %c\n", sizeof(ch), ch, ch[0]);
		if(cnt==4)
		{
			break;
		}
		if(isdigit(ch[0]))
		{
			
			strcat(file_name_size, ch[0]);
			// sprintf(file_name_size,"%s%s", file_name_size, ch);
			printf("digit %s\n", ch);
			printf("file_name_size %s\n", file_name_size);
		}
		else
		{
			printf(" char %s\n", ch);
		}
	}
		
}

//output

// if(isdigit(ch[0]))
		// {
			
			// sprintf(file_name_size,"%s%s", file_name_size, ch);
			
			// printf("%s", file_name_size);
		// }
		// printf("ch %s\n", ch);
		// else
		// {
			// printf("size %s\n", file_name_size);
			// char file_name[atoi(file_name_size)];
			// printf("size of array %d\n", sizeof(file_name));
			// read(fd,file_name,sizeof(file_name));
			// printf("file name %s", file_name);
			// fd = open(file_name, O_RDONLY);
			// close(fd1);
			// while((ret = read(fd,ch,sizeof(ch))) != 0)
			// {
				// printf("Welcome");
				// break
			// }
			// printf("Hi");
			// break;
			
		// }
		// ch[0] = '\0';
		 // memset(ch, 0, sizeof(ch));
		 // printf("after %s\n", ch);
	// }
	// printf("\n");
    // close(fd);

	// while((ret = read(fd, buffer, sizeof(buffer))) != 0)
	// {
		// write(dest_fd, buffer, ret);
		// memset(buffer, 0, sizeof(buffer));
	// }