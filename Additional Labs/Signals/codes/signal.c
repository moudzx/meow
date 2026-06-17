#include <signal.h> 
#include <stdio.h> 
#include<stdlib.h>
#include <unistd.h>

void traiter_signaux( int sig) { 
if (sig == SIGUSR1) 
signal(sig,traiter_signaux); /* reassocier la procédure au signal SIGUSR1 uniquement */ 
else 
signal(sig,SIG_DFL) ; 
printf("\n signal reçu est : %d \n",sig) ; 
} 

void main() 
{ 
pid_t pid;
int s; 

signal(SIGUSR1, traiter_signaux) ; 
signal(SIGUSR2, traiter_signaux) ;

pid = fork() ; 
 
if (pid ==-1) 
{
perror("\n Erreur de création de processus\n") ; 
exit(-1) ;
} 
if (pid == 0) 
while (1); 

for (s=1 ;s>0 ;) 
{
printf("\nNuméro de signal (négative pour finir):"); 
scanf("%d",&s); 
kill(pid,s) ; /* envoyer le signal lu au fils */ 
} 
} 
