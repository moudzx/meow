#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<string.h>
void traiter(int sig){}

int main(){
struct sigaction sa;
memset(&sa,0,sizeof(struct sigaction));
sa.sa_handler=traiter;
sigaction(SIGUSR1,&sa,NULL);


pid_t fils;
switch ((fils=fork ())){
case -1: perror("fork"); exit(-1);
case 0: {
	pause();
	printf("ca\n");
	kill(getppid(),SIGUSR1);
	exit(0); 
}
default:
	printf("wow\n");
	kill(fils,SIGUSR1); 
	pause();
	printf("compile\n");
return 0; } } 