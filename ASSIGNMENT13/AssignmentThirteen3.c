//3. Write a program which creates such a process which accept signals from the terminal.

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <strings.h>



int main()
{
	
	int pid = 0;
	char buf1[100];
	
	pid  = fork();
	
	if(pid == -1)
	{
		printf("Unable to create the process\n");
		return -1;
	}
	
	if(pid == 0) //child
	{
		
	}
	else  //parent 
	{
		while(1)
		{
			fgets(buf1, 100, stdin);
			
			
			
		}
	}
	
	
}



















// // Signal handler for SIGINT
// void	sigint_handler(int signal)
// {
	// if (signal == SIGINT)
		// printf("\nIntercepted SIGINT!\n");
// }

// void set_signal_action(void)
// {
	// // Declare the sigaction structure
	// struct sigaction	act;

	// // Set all of the structure's bits to 0 to avoid errors
	// // relating to uninitialized variables...
	// bzero(&act, sizeof(act));
	// // Set the signal handler as the default action
	// act.sa_handler = &sigint_handler;
	// // Apply the action in the structure to the
	// // SIGINT signal (ctrl-c)
	// sigaction(SIGINT, &act, NULL);
// }

// int	main(void)
// {
	// // Change SIGINT's associated action
	// set_signal_action();
	// // Infinite loop to give us time to do ctrl-c
	// // as much as we want!
	// while(1)
		// continue ;
	// return (0);
// }