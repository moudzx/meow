#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int p;
void traiter(int s){
printf("Aie!\n");
}
void main(int argc,char**argv){


signal(SIGINT,traiter);

while(1) pause();
}