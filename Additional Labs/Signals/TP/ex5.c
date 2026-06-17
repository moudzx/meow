#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void traiter(int s){
printf("Au Revoir...................................................!\n");
sleep(1);
alarm(3);
}

void main(int argc,char**argv){

signal(SIGALRM,traiter);
alarm(3);
while(1) {printf("Bonjour \n");}
}