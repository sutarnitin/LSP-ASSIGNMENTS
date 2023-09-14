#include<fcntl.h>
#include "ReadBytesOfFile.h"

int openFile(char fileName[]){
	int ret = open(fileName, O_RDONLY);
	return ret;
}

int readFile(int fd, char Buffer[],int Size){
	int res = read(fd,Buffer,Size);
	return res;
}