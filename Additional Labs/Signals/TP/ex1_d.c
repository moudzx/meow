#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void traiter(int s){
	
}

void main(){
pid_t fils;

switch(fils=fork()){
case -1: perror("Fork"); exit(0);
case 0: 
	signal(SIGUSR1,traiter);
	pause();
	printf("World!\n");  break;
default :
	sleep(1);
	printf("Hello,"); 
	kill(fils,SIGUSR1);
}
}