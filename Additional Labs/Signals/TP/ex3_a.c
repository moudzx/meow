#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

int cpt=0;

void traiter(int s){
cpt++;
printf("Jai recu %d SIGINT\n",cpt);
if(cpt==5) exit(0); 
}

void main(){
//signal(SIGINT,traiter);
struct sigaction s;
memset(&s,0,sizeof(s));
s.sa_handler=traiter;
sigaction(SIGINT,&s,NULL);

while(1)
 pause();
}