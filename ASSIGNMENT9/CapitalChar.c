//find small characters country

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	
	int fd = 0, fd1 = 0;
	char Buffer[512];
	int iCnt = 0, iRet = 0, i = 0;
	
	if(argc != 2)
	{
		printf("Insufficient Arguments\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	
	while((iRet = read(fd, Buffer, sizeof(Buffer)))!=0)
	{
		for(i = 0; i < iRet; i++)
		{
			if(((Buffer[i]) >= 'A') && ((Buffer[i]) <= 'Z'))
			{
				iCnt++;
			}
		}
	}


		printf("Number of capital characters are %d\n", iCnt);

		fd1 =  open("count.txt", O_WRONLY | O_CREAT, 06660);
		char str[50];
		sprintf(str, "Number of capital characters in %s  are:  %d \n", argv[1], iCnt);
		lseek(fd1, 0, SEEK_END);
		write(fd1, str, strlen(str) );
		
		close(fd1);
		close(fd);

return 0;
}