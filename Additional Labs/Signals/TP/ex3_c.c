#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void traiter(int s){}

void main(){
int i;
pid_t fils;

signal(SIGUSR1,traiter);

switch(fils=fork()){
case -1 : perror("Fork"); exit(0);
case 0 :
	
	for(i=1;i<20;i+=2)
	{
	pause();
	printf("%d\n",i);
	kill(getppid(),SIGUSR1);
	}
exit(0);
break;
default :	sleep(1);
	for(i=0;i<=20;i+=2)
	{
	printf("%d\n",i); 
	kill(fils,SIGUSR1);
	pause();
	}
}

wait(NULL);
printf("\n");

}