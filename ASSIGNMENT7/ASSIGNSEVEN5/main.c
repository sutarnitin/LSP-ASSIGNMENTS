#include<stdio.h>
#include "FileInfo.h"

int main(int argc, char *argv)
{
    if(argc != 2)
	{
		printf("Insuffucient Arguments\n");
	}
	FileInfo(argv[1]);
    return 0;
}