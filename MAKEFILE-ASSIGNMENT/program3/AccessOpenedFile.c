#include<fcntl.h>
#include "AccessOpenedFile.h"

int AccessFile(char accessFile[], int mode){
	
	int ret = access(accessFile, mode);
	
	return ret;

}