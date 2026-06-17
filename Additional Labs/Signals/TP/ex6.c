#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void traiter(int s){
printf("C'est trop tard !\n");
exit(0);
}

void main(int argc,char**argv){
char prenom[25];
signal(SIGALRM,traiter);
alarm(5);

printf("Entrer vore prenom \n");
scanf("%s",prenom);

printf("Bien venue %s \n",prenom);
}