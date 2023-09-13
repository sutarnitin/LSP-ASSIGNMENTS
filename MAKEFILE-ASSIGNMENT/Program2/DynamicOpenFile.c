	#include<stdio.h>
	#include<fcntl.h>
	#include "DynamicOpenFile.h"
 
	int OpenFile(char fileName[], int mode){
		
		int ret = 0;
		printf("file name %s:\n ", fileName);
		printf("mode %d: \n", mode);
		ret = open(fileName, mode);
		 
		 return ret;
	}