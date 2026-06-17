#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void main () {
	int code_retour;

	code_retour = fork ();
	switch (code_retour ) {
	case -1 :
	printf ("Pbm lors de la creation du processus\n");
	 break;
	case 0 :
	printf("First Child before sleeping\n");
	sleep(5);
	printf("First Child after sleeping\n");
	exit(1);
	
	default :
			int codRet=fork();
			switch (codRet ) {
			case -1 :
			printf ("Pbm lors de la creation du processus\n");
			 break;
			case 0 : 
			printf("Second Child before sleeping\n");
			sleep(10);
				printf("Second Child after sleeping\n");
			exit(2);
			
			default :
	
		int status;
			waitpid(codRet,&status,0);
	
	if(WIFEXITED(status))
	printf("Mon fils se termine par exit et voici le code retour %d\n",
		WEXITSTATUS(status));
	if(WIFSIGNALED(status))
		printf("Mon fils se termine par un signale de code %d\n",
		WTERMSIG(status));
	}
	}
}
