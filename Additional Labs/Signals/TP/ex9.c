#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int duree=5;

void handler(int signum){

switch(signum){
case SIGINT:duree--; break;
case SIGUSR1:duree+=2;
}
printf("Duree=%d\n",duree);
}
void main(){
signal(SIGINT, handler);
signal(SIGUSR1,handler);
while(duree>0)pause();
printf("See you!\n");
}
