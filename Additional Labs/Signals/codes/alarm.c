#include<stdio.h>
#include<signal.h>
int i;

void traiter_signal(int sig){	
if(sig==SIGALRM)	{
printf(" i=%d \n",i);			
alarm(3);			
signal(SIGALRM,traiter_signal);
}	
else 		
signal(sig,SIG_IGN);}
int main(){	
signal(SIGALRM,traiter_signal);	
alarm(3);
	for(i=0; ;i++);
}	
