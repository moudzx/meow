#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void main(){

signal(SIGINT,SIG_IGN);
while(1) 
pause();
}