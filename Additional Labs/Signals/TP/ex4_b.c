#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int cpt=0,p;
void traiter(int s){
cpt++;
printf("Aie!\n");
if(cpt==p) 
{
printf("ca suffit, j’ai trop mal...\n");
exit(0); }
}
void main(int argc,char**argv){
if(argc<2){
printf("Using %s N\n",argv[0]);
exit(1);
}
p=atoi(argv[1]);

signal(SIGINT,traiter);

while(1) pause();
}