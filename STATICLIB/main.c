#include<stdio.h>
#include "staticshared.h"

int main()
{
    int a = 10, b = 11, ret = 0;

    ret = Addition(a,b);

    printf("Addition is : %d\n",ret);

    return 0;
}