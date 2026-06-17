#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int ctr=0;
void donnerresultat(int s){
	printf("La valeure actuelle de ctr est %d\n",ctr);
}
void main(){
	struct sigaction action;
	memset(&action,0,sizeof(struct sigaction));
	action.sa_handler=donnerresultat;
	sigaction(SIGUSR1,&action,NULL);
	//signal(SIGUSR1,donnerresultat)
	while(1)ctr++;
}