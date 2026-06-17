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
	case 0 : sleep(50);exit(3);
	break;
	default :
		int status;
		wait(&status);
	if(WIFEXITED(status))
printf("Mon fils se termine par exit et voici le code retour %d\n",WEXITSTATUS(status));		
		if(WIFSIGNALED(status))
printf("Mon fils se termine par un signale de code %d\n",WTERMSIG(status));
	}
}