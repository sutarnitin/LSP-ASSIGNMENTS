//1. Write a program which is used to demonstrate concept of I/O redirection.

#include<stdio.h>

int main(int argc, char *argv[])
{
    int iNo1 = 0, iNo2 = 0, iNo3=0;
    int iAns = 0;

    scanf("%d",&iNo1);
    scanf("%d",&iNo2);
	scanf("%d",&iNo3);
    iAns = iNo1 + iNo2+iNo3;

    printf("Addition is : %d\n",iAns);

    return 0;
}



/*Output
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ gcc AssignmentFour1.c -o myexe -w
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ ./myexe <input.txt > output.txt
nitin@Nitin:~/Documents/LSP-ASSIGNMENTS/ASSIGNMENT4$ ls
abc.txt          AssignmentFour1.c  AssignmentFour3.c  AssignmentFour5.c  hello.txt  myDir  output.txt       que4output1.txtclear
Assignment4.txt  AssignmentFour2.c  AssignmentFour4.c  demo.txt           input.txt  myexe  que4output1.txt  que4output.txt
*/