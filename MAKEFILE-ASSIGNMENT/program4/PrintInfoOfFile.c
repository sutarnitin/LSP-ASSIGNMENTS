#include<fcntl.h>
#include "PrintInfoOfFile.h"

int openFile(char fileName[]){
	int fd = open(fileName, O_RDONLY);
	return fd;
}