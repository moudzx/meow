#include <signal.h> 
#include <stdio.h> 
#include <sys/stat.h> 
#include<unistd.h>
#include<stdlib.h>
void main() 
{ 

pid_t pid ; 

pid = fork() ; 

if (pid ==-1) 
{ perror("\n Erreur de création de processus\n") ; 
exit(-1) ; 
} 

if (pid == 0) 
while (1) ; 

printf("\n J’ai crée un processus et je vais le tuer \n") ; 
kill(pid,9) ; /* envoi un signal SIGKILL au fils */ 
} 
