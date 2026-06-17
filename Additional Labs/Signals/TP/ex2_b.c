#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int N=0;
void traiter(int s){
N++;
printf(" Je suis le père, j'ai reçu un signal SIGUSR1 de mon fils pour la %dième fois\n",N);
}
void main(){
pid_t fils;
int status;
switch(fork()){
case -1: perror("Fork"); exit(0);
case 0: 
	{
	 int i;
	pid_t pere=getppid();
	for(i=1;i<=200000;i++){
	kill(pere,SIGUSR1);
	
}
	exit(0);
	}break;
default :
	signal(SIGUSR1,traiter);
	fils=wait(&status);
if(WIFEXITED(status)){
printf("Mon processus fils ayant le numéro pid %d vient de se terminer, et a retourné un code erreur %d\n",fils,WEXITSTATUS(status));
}	

}
}