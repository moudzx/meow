#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>

void handler(int sig){
switch(sig){
case SIGUSR1: system("who");break;
case SIGUSR2: system("df .");break;
default:
printf("SIGNAL recu %d=",sig); 
psignal(sig,"");;}


}
void main(){
int i;
for(i=1;i<32;i++)
signal(i,handler);
while(1);//pause(); a ne pas utiliser car ne fonctionne pas avec SIGCONT
}