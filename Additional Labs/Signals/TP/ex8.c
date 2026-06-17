#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

#define password "123456"
char motdepass[30];

void tester(int sig){
	printf("Entrer le mot de passe :");
	scanf("%s",motdepass);
	if(strcmp(password,motdepass)==0)
	exit(0);
	else
	printf("Try again \n");
}

void main(){
signal(SIGINT,tester);
while(1)pause();
}