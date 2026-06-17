#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(){
int tube[2];

if(pipe(tube)<0){
perror("Pipe");
exit(0);
}
char c='+';
int nbecris;
close(tube[0]);
nbecris=write(tube[1],&c,1);
printf("Jai ecris %d caracteres qui sont %c \n",nbecris,c);
}