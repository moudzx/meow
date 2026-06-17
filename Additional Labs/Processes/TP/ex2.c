#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void printInfos(char name[]){
	printf("%s-- PID=%d\n",name,getpid());
	printf("%s-- PPID=%d\n",name,getppid());
	printf("%s-- Working Directory=%s\n",name,getcwd(NULL,0));
	printf("%s-- Owner ID=%d\n",name,getuid());
	printf("%s-- Owner GROUP ID=%d\n",name,getgid());
	
}
void main () {
	int code_retour;

	code_retour = fork ();
	switch (code_retour ) {
	case -1 :
	printf ("Pbm lors de la creation du processus\n");
	 break;
	case 0 :
	printInfos("CHILD");
	break;
	default :
	printInfos("PARENT");
	break;
	}
}